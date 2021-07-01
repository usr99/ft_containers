/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:21:23 by mamartin          #+#    #+#             */
/*   Updated: 2021/06/28 23:09:59 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_ITERATOR_HPP
# define LIST_ITERATOR_HPP

# include "../utils/iterator.hpp"
# include "../utils/node.hpp"

namespace ft
{
	// Iterator class for ft::list =============================================
	template <class T>
	class listIterator : public iterator<bidirectional_iterator_tag, T>
	{
		public:

			typedef iterator<bidirectional_iterator_tag, T>	Base;
			typedef typename Base::value_type				value_type;
			typedef typename Base::difference_type			difference_type;
			typedef typename Base::pointer					pointer;
			typedef typename Base::reference				reference;
			typedef listNode<value_type>					Node;

			// constructors
			listIterator();							// default
			listIterator(Node *ptr);				// from pointer
			listIterator(const listIterator &rhs);	// copy

			// getter
			Node*					getNode() const;

			// operator overloads
			listIterator&			operator=(const listIterator& rhs);
			listIterator&			operator++();
			listIterator			operator++(int n);
			listIterator&			operator--();
			listIterator			operator--(int n);
			reference				operator*() const;
			pointer					operator->() const;
			bool					operator==(const listIterator& rhs) const;
			bool					operator!=(const listIterator& rhs) const;

		private:

			Node					*_ptr;
	};

	// Const iterator class for ft::list =======================================
	template <class T>
	class const_listIterator : public iterator<bidirectional_iterator_tag, const T>
	{
		public:

			typedef iterator<bidirectional_iterator_tag, T>	Base;
			typedef typename Base::value_type				value_type;
			typedef typename Base::difference_type			difference_type;
			typedef typename Base::pointer					pointer;
			typedef typename Base::reference				reference;
			typedef listNode<value_type>					Node;

			// constructors
			const_listIterator();								// default
			const_listIterator(Node *ptr);						// from pointer
			const_listIterator(const const_listIterator &rhs);	// copy

			// operator overloads
			const_listIterator&		operator=(const const_listIterator& rhs);
			const_listIterator&		operator++();
			const_listIterator		operator++(int n);
			const_listIterator&		operator--();
			const_listIterator		operator--(int n);
			reference				operator*() const;
			pointer					operator->() const;
			bool					operator==(const const_listIterator& rhs) const;
			bool					operator!=(const const_listIterator& rhs) const;

		private:
		
			Node					*_ptr;
	};
}

# include "listIterator.ipp"

#endif
