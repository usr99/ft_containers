/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 23:37:43 by mamartin          #+#    #+#             */
/*   Updated: 2021/09/11 01:33:47 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "../utils/iterator.hpp"
# include "../utils/bst.hpp"

namespace ft
{
	// Iterator class for ft::map ==============================================
	template <class T>
	class mapIterator : public iterator<bidirectional_iterator_tag, T>
	{
		public:

			typedef iterator<bidirectional_iterator_tag, T>	Base;
			typedef typename Base::value_type				value_type;
			typedef typename Base::difference_type			difference_type;
			typedef typename Base::pointer					pointer;
			typedef typename Base::reference				reference;
			typedef avl_tree<value_type>					node;

			// constructors
			mapIterator();							// default
			mapIterator(node *ptr);					// from pointer
			mapIterator(const mapIterator &rhs);	// copy

			node* 			get_node() const;

			// operator overloads
			mapIterator&	operator=(const mapIterator& rhs);
			mapIterator&	operator++();
			mapIterator		operator++(int n);
			mapIterator&	operator--();
			mapIterator		operator--(int n);
			reference		operator*() const;
			pointer			operator->() const;
			bool			operator==(const mapIterator& rhs) const;
			bool			operator!=(const mapIterator& rhs) const;

		private:

			node* 			_ptr;
	};

	// Iterator const specialization for ft::map ===============================
	template <class T>
	class mapIterator<const T> : public iterator<bidirectional_iterator_tag, const T>
	{
		public:

			typedef iterator<bidirectional_iterator_tag, T>	Base;
			typedef typename Base::value_type				value_type;
			typedef typename Base::difference_type			difference_type;
			typedef typename Base::pointer					pointer;
			typedef typename Base::reference				reference;
			typedef const avl_tree<value_type>				node;

			// constructors
			mapIterator();							// default
			mapIterator(node *ptr);					// from pointer
			mapIterator(const mapIterator &rhs);	// copy

			node* 			get_node() const;

			// operator overloads
			mapIterator&		operator=(const mapIterator& rhs);
			mapIterator&		operator++();
			mapIterator			operator++(int n);
			mapIterator&		operator--();
			mapIterator			operator--(int n);
			const value_type&	operator*() const;
			const value_type*	operator->() const;
			bool				operator==(const mapIterator& rhs) const;
			bool				operator!=(const mapIterator& rhs) const;

		private:

			node* 			_ptr;
	};
}

# include "mapIterator.ipp"

#endif
