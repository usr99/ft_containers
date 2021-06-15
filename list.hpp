/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 09:44:02 by mamartin          #+#    #+#             */
/*   Updated: 2021/06/15 12:46:55 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# define <iterator>

namespace ft
{
	template <class T, class Alloc = allocator<T>>
	class list
	{
		public:

 			// member types
			typedef T															value_type;
			typedef Alloc														allocator_type;
			typedef allocator_type::reference									reference;
			typedef allocator_type::const_reference								const_reference;
			typedef allocator_type::pointer										pointer;
			typedef allocator_type::const_pointer								const_pointer;
			typedef std::iterator<bidirectional_iterator_tag, value_type>		iterator;
			typedef std::iterator<bidirectional_iterator_tag, const value_type>	const_iterator;
			typedef std::reverse_iterator<iterator>								reverse_iterator;
			typedef std::reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef std::iterator_traits<iterator>::difference_type				difference_type;
			typedef size_t														size_type;

			// constructors
			list(const allocator_type &alloc = allocator_type());
			list(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type());
			template <class InputIterator>
				list(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type());
			list(const list &x);

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

		private:

		// non member overloads
		friend void	swap(list<T, Alloc> &x, list<T, Alloc> &y);
		friend bool	operator==(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs);
		friend bool	operator!=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs);
		friend bool	operator<(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs);
		friend bool	operator<=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs);
		friend bool	operator>(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs);
		friend bool	operator>=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs);
	};
}

# include "list.ipp"

#endif
