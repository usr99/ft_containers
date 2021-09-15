/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 02:44:47 by mamartin          #+#    #+#             */
/*   Updated: 2021/09/14 22:21:12 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include "mapIterator.hpp"
# include "../utils/pair.hpp"
# include "../utils/sort.hpp"

namespace ft
{
	template <class Key, class T, class Compare = less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
	class map
	{
		public:
		
			typedef Key 												key_type;
			typedef T													mapped_type;
			typedef pair<const key_type, mapped_type>					value_type;
			typedef Compare												key_compare;
			typedef Alloc												allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef mapIterator<value_type>								iterator;
			typedef mapIterator<const value_type>						const_iterator;
			typedef reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef reverse_iterator<iterator>							reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type	difference_type;
			typedef size_t												size_type;

			class value_compare : public binary_function<value_type, value_type, bool>
			{
				friend class map;

				public:

  					bool operator()(const value_type& x, const value_type& y) const
  					{
  						return comp(x.first, y.first);
  					}					

				protected:

					Compare	comp;
					value_compare(Compare c) : comp(c) {}
			};

			// empty constructor
			explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) :
				_root(NULL), _size(0), _key_comp(comp), _alloc(alloc)
			{
				_end = _create_node(btree()); // create node
				_end->depth = 0;
				_begin = _end;
			}

			// range constructor
			template <class InputIterator>
			map(
				InputIterator first,
				typename enable_if<is_input_iterator<typename iterator_traits<InputIterator>::iterator_category>::value, InputIterator>::type last,
				const key_compare &comp = key_compare(),
				const allocator_type &alloc = allocator_type())
			: _root(NULL), _size(0), _key_comp(comp), _alloc(alloc)
			{
				_end = _create_node(btree()); // create node
				_end->depth = 0;
				_begin = _end;

				insert(first, last);
			}

			// copy constructor
			map(const map &x) :
				_root(NULL), _size(0), _key_comp(x._key_comp), _alloc(x._alloc)
			{
				_end = _create_node(btree()); // create node
				_end->depth = 0;
				_begin = _end;

				*this = x;
			}

			// destructor
			~map()
			{
				clear();
				node_alloc(_alloc).destroy(_end);
				node_alloc(_alloc).deallocate(_end, 1);
			}

			map &operator=(const map &x)
			{
				clear();
				insert(x.begin(), x.end());
				return (*this);
			}

			iterator begin()
			{
				return (iterator(_begin));
			}

			const_iterator begin() const
			{
				return (const_iterator(_begin));
			}

			iterator end()
			{
				return (iterator(_end));
			}

			const_iterator end() const
			{
				return (const_iterator(_end));
			}

			reverse_iterator rbegin()
			{
				return (++reverse_iterator(_end));
			}
			
			const_reverse_iterator rbegin() const
			{
				return (++const_reverse_iterator(_end));
			}

			reverse_iterator rend()
			{
				return (++reverse_iterator(_begin));;
			}

			const_reverse_iterator rend() const
			{
				return (++const_reverse_iterator(_begin));;
			}

			bool empty() const
			{
				return (!_size);
			}

			size_type size() const
			{
				return (_size);
			}

			size_type max_size() const
			{
				return (node_alloc(_alloc).max_size());
			}

			mapped_type& operator[](const key_type& k)
			{
				pair<iterator, bool> ret = insert(ft::make_pair(k, mapped_type()));

				return (ret.first->second);
			}

			pair<iterator,bool> insert(const value_type& val)
			{
				// no tree
				if (!_root)
				{
					_root = _create_node(btree(val)); // create node
					_append_end_node(_root); // place end node
					_begin = _root;
					_begin->left = _end;
					_size++;
					return (ft::make_pair(iterator(_root), true));
				}
				
				pair<iterator, bool> ret = _insert(_root, val); // find where to insert
				if (ret.second == true) // if element doesn't already exist
				{
					if (_end->parent->right != _end) // replace end if overwrited
						_append_end_node(ret.first.get_node());
					else if (_begin->left != _end) // if val < _begin->data
					{
						_begin = _begin->left;
						_begin->left = _end;
					}
					_size++;
				}

				return (ret);
			}

			iterator insert(iterator position, const value_type& val)
			{
				btree		*node = position.get_node();
				iterator	ret;

				if ((!node->left || node->left == _end) && _key_comp(val.first, node->data.first))
				{
					node->left = _create_node(btree(node, val)); // create node
					ret = iterator(node->left);
				}
				else if ((!node->right || node->right == _end) && _key_comp(node->data.first, val.first))
				{
					node->right = _create_node(btree(node, val)); // create node
					ret = iterator(node->right);
				}
				else if (val.first == node->data.first)
					return (position);
				else
					return (insert(val).first);

				if (_end->parent->right != _end) // replace end if overwrited
					_append_end_node(ret.get_node());
				else if (_begin->left != _end) // if val < _begin->data
				{
					_begin = _begin->left;
					_begin->left = _end;
				}

				return (ret);
			}

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					insert(*first);
					first++;
				}
			}

    		void erase(iterator position)
			{
				if (_size == 1)
				{
					clear();
					return ;
				}
				else if (position == begin()) // move _begin pointer
				{
					_begin = (++position).get_node();
					--position; // restore iterator after incrementation
				}
				else if (position == --end()) // same for end node
				{
					_end->parent = _end->parent->parent;
					_end->right = _end->parent;
				}
				_erase(position.get_node()); // erase node
				_size--; // decrease size
			}

			size_type erase(const key_type& k)
			{
				iterator	it = find(k);

				if (it == end())
					return (0);
				erase(it);
				return (1);
			}

    		void erase(iterator first, iterator last)
			{
				iterator tmp;

				while (first != last)
				{
					tmp = first;
					tmp++;
					erase(first);
					first = tmp;
				}
			}

			void swap(map& x)
			{
				avl_tree<value_type>	*node;
				size_type				sz;
				key_compare				cmp;
				allocator_type			allocator;

				// swap trees
				node = _root; // root
				_root = x._root;
				x._root = node;

				node = _begin; // pointer to smallest element
				_begin = x._begin;
				x._begin = node;

				node = _end; // pointer to after-the-end node
				_end = x._end;
				x._end = node;

				// swap sizes
				sz = _size;
				_size = x._size;
				x._size = sz;

				// swap comparison object
				cmp = _key_comp;
				_key_comp = x._key_comp;
				x._key_comp = cmp;

				// swap allocators
				allocator = _alloc;
				_alloc = x._alloc;
				x._alloc = allocator;
			}

			void clear()
			{
				if (empty())
					return ;

				_begin->left = NULL;
				_end->parent->right = NULL;

				_clear(_root);

				_size = 0;
				_begin = _end;
				_root = NULL;
				_end->parent = NULL;
				_end->right = NULL;
			}

			key_compare key_comp() const
			{
				return (_key_comp);
			}

			value_compare value_comp() const
			{
				return (value_compare(_key_comp));
			}

			iterator find(const key_type& k)
			{
				btree *node = _find(_root, k);
				return (iterator(node));
			}

			const_iterator find(const key_type& k) const
			{
				btree *node = _find(_root, k);
				return (const_iterator(node));
			}

			size_type count(const key_type& k) const
			{
				if (_find(_root, k) == _end)
					return (0);
				return (1);
			}

			iterator lower_bound(const key_type& k)
			{
				iterator it = begin();

				while (it != end() && _key_comp(it->first, k))
					++it;
				return (it);
			}

			const_iterator lower_bound(const key_type& k) const
			{
				const_iterator it = begin();

				while (it != end() && _key_comp(it->first, k))
					++it;
				return (it);
			}

			iterator upper_bound(const key_type& k)
			{
				iterator it = begin();

				while (it != end() && _key_comp(it->first, k))
					++it;

				if (it == end() || _key_comp(k, it->first))
					return (it);

				return (++it);
			}

			const_iterator upper_bound(const key_type& k) const
			{
				const_iterator it = begin();

				while (it != end() && _key_comp(it->first, k))
					++it;

				if (it == end() || _key_comp(k, it->first))
					return (it);

				return (++it);
			}

			pair<iterator, iterator> equal_range(const key_type& k)
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			pair<const_iterator, const_iterator> equal_range(const key_type& k) const
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			allocator_type get_allocator() const
			{
				return (_alloc);
			}

		private:

			typedef avl_tree<value_type>									btree;
			typedef typename allocator_type::template rebind<btree>::other	node_alloc;

			pair<iterator, bool>	_insert(btree *root, const value_type &val);
			void					_append_end_node(btree * node);
			btree*					_create_node(const btree &val);
			bool					_is_balanced(btree *node) const;
			btree*					_rotate_left(btree *root);
			btree*					_rotate_right(btree *root);
			btree*					_rotate_left_right(btree *root);
			btree*					_rotate_right_left(btree *root);
			btree*					_find(btree *root, const key_type &k) const;
			void					_erase(btree *node);
			void					_rebalance(btree *node);
			void					_replace_node(btree *node, btree *child);
			void					_clear(btree *root);

			btree*					_root;
			btree*					_begin;
			btree*					_end;
			size_type				_size;
			key_compare				_key_comp;
			allocator_type			_alloc;
	};
}

# include "map_utils.ipp"

#endif
