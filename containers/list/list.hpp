/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 09:44:02 by mamartin          #+#    #+#             */
/*   Updated: 2021/06/29 17:48:22 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
# include "listIterator.hpp"
# include "../utils/node.hpp"
# include "../utils/sort.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class list
	{
		public:
			// member types
			typedef T													value_type;
			typedef Alloc												allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef listIterator<value_type>							iterator;
			typedef const_listIterator<value_type>						const_iterator;
			typedef reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef reverse_iterator<iterator>							reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type	difference_type;
			typedef size_t												size_type;

			// constructors
			explicit list(const allocator_type &alloc = allocator_type());														// default
			explicit list(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type());	// fill
			template <class InputIterator>
				list(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type());					// range
			list(const list &x);																								// copy

			~list(); // destructor

			// member functions
			// iterators
			iterator				begin();
			const_iterator			begin() const;
			iterator				end();
			const_iterator			end() const;
			reverse_iterator		rbegin();
			const_reverse_iterator	rbegin() const;
			reverse_iterator		rend();
			const_reverse_iterator	rend() const;
			// capacity
			bool					empty() const;
			size_type				size() const;
			size_type				max_size() const;
			// element access
			reference				front();
			const_reference			front() const;
			reference				back();
			const_reference			back() const;
			// modifiers
			template <class InputIterator>
				void				assign(InputIterator first, InputIterator last);
			void					assign(size_type n, const value_type &val);
			void					push_front(const value_type &val);
			void					pop_front();
			void					push_back(const value_type &val);
			void					pop_back();
			iterator				insert(iterator position, const value_type &val);
			void					insert(iterator position, size_type n, const value_type &val);
			template <class InputIterator>
				void				insert(iterator position, InputIterator first, InputIterator last);
			iterator				erase(iterator position);
			iterator				erase(iterator first, iterator last);
			void					swap(list &x);
			void					resize(size_type n, value_type val = value_type());
			void					clear();
			// operations
			void					splice(iterator position, list &x);
			void					splice(iterator position, list &x, iterator i);
			void					splice(iterator position, list &x, iterator first, iterator last);
			void					remove(const value_type &val);
			template <class Predicate>
				void				remove_if(Predicate pred);
			void					unique();
			template <class BinaryPredicate>
				void				unique(BinaryPredicate binary_pred);
			void					merge(list &x);
			template <class Compare>
				void				merge(list &x, Compare comp);
			void					sort();
			template <class Compare>
				void				sort(Compare comp);
			void					reverse();

			// member operators
			list&					operator=(const list &x);

		//private:

			typedef listNode<value_type>									Node;
			typedef typename allocator_type::template rebind<Node>::other	node_alloc;

			template <class Compare>
				Node*				_mergeSort(Node *first, size_type n, Compare comp);
			template <class Compare>
				Node*				_merge(Node *first, size_type size1, Node *second, size_type size2, Compare comp);

			Node					*_list;
			allocator_type			_alloc;
			size_type				_size;

		// non member overloads
		friend void	swap(list<T, Alloc> &x, list<T, Alloc> &y)
		{
			x.swap(y);
		}

		// lhs == rhs
		friend bool	operator==(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
		{
			return (ft::equal<T>::compare(lhs, rhs));
		}

		// !(lhs == rhs)
		friend bool	operator!=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
		{
			return (!ft::equal<T>::compare(lhs, rhs));
		}

		// lhs < rhs
		friend bool	operator<(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
		{
			return (ft::less_than<T>::compare(lhs, rhs));
		}

		// !(rhs < lhs)
		friend bool	operator<=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
		{
			return (!ft::less_than<T>::compare(rhs, lhs));
		}
		
		// rhs < lhs
		friend bool	operator>(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
		{
			return (ft::less_than<T>::compare(rhs, lhs));
		}
		
		// !(lhs < rhs)
		friend bool	operator>=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
		{
			return (!ft::less_than<T>::compare(lhs, rhs));
		}
	};
}

# include "list.ipp"

#endif
