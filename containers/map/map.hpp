/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 02:44:47 by mamartin          #+#    #+#             */
/*   Updated: 2021/09/08 00:59:08 by mamartin         ###   ########.fr       */
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
			map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) :
				_root(NULL), _size(0), _key_comp(comp), _alloc(alloc)
			{
				insert(first, last);
			}

			// copy constructor
			map(const map &x) :
				_root(NULL), _size(0), _key_comp(x._key_comp), _alloc(x._alloc)
			{
				insert(x.begin(), x.end());
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
				pair<iterator, bool> ret = insert(make_pair(k, mapped_type()));

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
					return (make_pair(iterator(_root), true));
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
					_append_end_node(ret.first.get_node());
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
					++first;
				}
			}

    		void erase(iterator position)
			{

			}

			size_type erase(const key_type& k)
			{
				iterator	it = find(k);

				if (it == end())
					return (0);
				else if (_size == 1)
					clear();
				else if (it == begin())
				{
					_begin = (++it).get_node();
					--it;
				}
				else if (it == --end())
				{
					_end->parent = _end->parent->parent;
					_end->right = _end->parent;
				}

				if (_erase(it.get_node()))
				{
					_size--;
					return (1);
				}
				return (0);
			}

    		void erase(iterator first, iterator last)
			{

			}

			void swap(map& x)
			{
				void	*tmp;

				// swap trees
				tmp = _root; // root
				_root = x._root;
				x._root = tmp;
				tmp = _begin; // pointer to smallest element
				_begin = x._begin;
				x._begin = tmp;
				tmp = _end; // pointer to after-the-end node
				_end = x._end;
				x._end = tmp;

				// swap sizes
				tmp = &_size;
				_size = x._size;
				x._size = *static_cast<size_type*>(tmp);

				// swap comparison object
				tmp = &_key_comp;
				_key_comp = x._key_comp;
				x._key_comp = *static_cast<key_compare*>(tmp);

				// swap allocators
				tmp = &_alloc;
				_alloc = x._alloc;
				x._alloc = *static_cast<allocator_type*>(tmp);
			}

			void clear()
			{
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
				iterator it = lower_bound(k);
				return (make_pair(it, it));
			}

			pair<const_iterator, const_iterator> equal_range(const key_type& k) const
			{
				const_iterator it = lower_bound(k);
				return (make_pair(it, it));
			}

			allocator_type get_allocator() const
			{
				return (_alloc);
			}

		private:

			typedef avl_tree<value_type>									btree;
			typedef typename allocator_type::template rebind<btree>::other	node_alloc;

			pair<iterator, bool> _insert(btree *root, const value_type& val)
			{
				pair<iterator, bool>	ret;

				// insert
				if (_key_comp(val.first, root->data.first))
				{
					if (root->left && root->left != _end)
					{
						ret = _insert(root->left, val);
						if (ret.second == false)
							return (ret);
					}
					else
					{
						root->left = _create_node(btree(root, val)); // create node
						ret = make_pair(iterator(root->left), true);
					}
					if (!_is_balanced(root))
					{
						if (_key_comp(val.first, root->left->data.first))
							root = _rotate_right(root);
						else
							root = _rotate_left_right(root);
					}

				}
				else if (_key_comp(root->data.first, val.first))
				{
					if (root->right && root->right != _end)
					{
						ret = _insert(root->right, val);
						if (ret.second == false)
							return (ret);
					}
					else
					{
						root->right = _create_node(btree(root, val)); // create node
						ret = make_pair(iterator(root->right), true);
					}
					if (!_is_balanced(root))
					{
						if (_key_comp(root->right->data.first, val.first))
							root = _rotate_left(root);
						else
							root = _rotate_right_left(root);
					}
				}
				else
					return (make_pair(iterator(root), false));

				return (ret);
			}

			void _append_end_node(btree *node)
			{
				node->right = _end;
				_end->parent = node;
				_end->right = node;
			}

			btree* _create_node(const btree& val)
			{
				btree*	node;
				node = node_alloc(_alloc).allocate(1);
				node_alloc(_alloc).construct(node, val);
				return (node);
			}

			bool _is_balanced(btree *node) const
			{
				int balance = node->balance_factor();

				if (balance < -1 || balance > 1)
					return (false);
				return (true);
			}

			btree* _rotate_left(btree *root)
			{
				btree* pivot = root->right;

				root->right = pivot->left;
				if (pivot->left)
					pivot->left->parent = root;

				pivot->left = root;
				pivot->parent = root->parent;
				root->parent = pivot;

				if (pivot->parent)
				{
					if (pivot->parent->left == root)
						pivot->parent->left = pivot;
					else if (pivot->parent->right == root)
						pivot->parent->right = pivot;
				}
				else
					_root = pivot;

				root->balance_factor();
				root = pivot;
				return (root);
			}

			btree* _rotate_right(btree *root)
			{
				btree* pivot = root->left;

				root->left = pivot->right;
				if (pivot->right)
					pivot->right->parent = root;

				pivot->right = root;
				pivot->parent = root->parent;
				root->parent = pivot;

				if (pivot->parent)
				{
					if (pivot->parent->left == root)
						pivot->parent->left = pivot;
					else if (pivot->parent->right == root)
						pivot->parent->right = pivot;
				}
				else
					_root = pivot;

				root->balance_factor();
				root = pivot;
				return (root);
			}

			btree* _rotate_left_right(btree *root)
			{
				_rotate_left(root->left);
				root = _rotate_right(root);
				return (root);
			}

			btree* _rotate_right_left(btree *root)
			{
				_rotate_right(root->right);
				root = _rotate_left(root);
				return (root);
			}

			btree* _find(btree *root, const key_type& k) const
			{
				if (!root || root == _end)
					return (_end);

				if (_key_comp(k, root->data.first))
					return _find(root->left, k);
				else if (_key_comp(root->data.first, k))
					return _find(root->right, k);
				else
					return (root);
			}

			bool _erase(btree *node)
			{
				btree	*tmp = node; 
				btree	*child;

				if (!node->left && !node->right) // no child
				{
					node = node->parent;
					if (node->left == tmp)
						node->left = NULL;
					else
						node->right= NULL;
				}
				else if (node->left && node->right) // 2 children
				{
					// find infix successor
					if (node->balance_factor() == 1)
					{
						child = node->right;
						while (child->left)
							child = child->left;

						// infix node takes node's children
						child->left = node->left;
						node->left->parent = child;
						if (child->right && child->parent != node)
						{
							child->parent->left = child->right;
							child->right->parent = child->parent;
						}
						else
							child->parent->left = NULL; // removes infix node from his parent

						if (child != node->right)
						{
							child->right = node->right;
							node->right->parent = child;
						}
					}
					else // find infix predecessor
					{
						child = node->left;
						while (child->right)
							child = child->right;

						// infix node takes node's children
						child->right = node->right;
						node->right->parent = child;

						if (child->left && child->parent != node)
						{
							child->parent->right = child->left;
							child->left->parent = child->parent;
						}
						else
							child->parent->right = NULL; // removes infix node from his parent

						if (child != node->left)
						{
							child->left = node->left;
							node->left->parent = child;
						}
					}
					
					// node's parent point to infix node
					if (node->parent)
					{
						if (node->parent->left == node)
							node->parent->left = child;
						else
							node->parent->right = child;
					}

					// save pointer to child's parent for depth recalculation
					if (child->parent != node)
						node = child->parent;
					else
						node = child;
					// infix node's parent is now node's parent
					child->parent = tmp->parent;

				}
				else // 1 child
				{
					if (node->left)
						child = node->left;
					else
						child = node->right;

					// parent pointe sur child
					if (node->parent)
					{
						if (node->parent->left == node)
							node->parent->left = child;
						else
							node->parent->right = child;
					}
					node = node->parent;
				}

				// modify depth for all nodes affected
				while (node)
				{
					int balance = node->balance_factor();

					if (balance > 1)
					{
						// Z is right child
						balance = node->right->balance_factor();
						if (balance >= 0)
							_rotate_left(node);
						else if (balance < 0)
							_rotate_right_left(node);
					}
					else if (balance < -1)
					{
						// Z is left child
						balance = node->left->balance_factor();
						if (balance <= 0)
							_rotate_right(node);
						else if (balance > 0)
							_rotate_left_right(node);						
					}
					node = node->parent; // next node
				}

				if (tmp == _root)
					_root = child;

				// destroy node
				node_alloc(_alloc).destroy(tmp);
				node_alloc(_alloc).deallocate(tmp, 1);

				return (true);
			}

			void _clear(btree *root)
			{
				if (!root)
					return ;

				_clear(root->left);
				_clear(root->right);

				node_alloc(_alloc).destroy(root);
				node_alloc(_alloc).deallocate(root, 1);
			}

			btree*			_root;
			btree*			_begin;
			btree*			_end;
			size_type		_size;
			key_compare		_key_comp;
			allocator_type	_alloc;
	};
}

#endif
