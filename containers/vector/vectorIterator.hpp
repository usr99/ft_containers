/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:56:22 by mamartin          #+#    #+#             */
/*   Updated: 2021/06/29 19:40:16 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "../utils/iterator.hpp"

namespace ft
{
	// Iterator class for ft::vector ===========================================
	template <class T>
	class vectorIterator : public iterator<random_access_iterator_tag, T>
	{
		public:

			typedef iterator<bidirectional_iterator_tag, T>	Base;
			typedef typename Base::value_type				value_type;
			typedef typename Base::difference_type			difference_type;
			typedef typename Base::pointer					pointer;
			typedef typename Base::reference				reference;

			// constructors
			vectorIterator();							// default
			vectorIterator(value_type *ptr);			// from pointer
			vectorIterator(const vectorIterator &rhs);	// copy

			// operator overloads
			vectorIterator&			operator=(const vectorIterator& rhs);
			vectorIterator&			operator++();
			vectorIterator			operator++(int n);
			vectorIterator			operator+(difference_type n) const;
			vectorIterator&			operator+=(difference_type n);
			vectorIterator&			operator--();
			vectorIterator			operator--(int n);
			vectorIterator			operator-(difference_type n) const;
			vectorIterator&			operator-=(difference_type n);
			reference				operator*() const;
			reference				operator[](difference_type n) const;
			pointer					operator->() const;
			bool					operator==(const vectorIterator& rhs) const;
			bool					operator!=(const vectorIterator& rhs) const;
			bool					operator<(const vectorIterator& rhs) const;
			bool					operator<=(const vectorIterator& rhs) const;
			bool					operator>(const vectorIterator& rhs) const;
			bool					operator>=(const vectorIterator& rhs) const;

		private:

			value_type				*_ptr;
	};

	// Const iterator class for ft::vector ===========================================
	template <class T>
	class const_vectorIterator : public iterator<random_access_iterator_tag, T>
	{
		public:

			typedef iterator<bidirectional_iterator_tag, T>	Base;
			typedef typename Base::value_type				value_type;
			typedef typename Base::difference_type			difference_type;
			typedef typename Base::pointer					pointer;
			typedef typename Base::reference				reference;

			// constructors
			const_vectorIterator();									// default
			const_vectorIterator(value_type *ptr);					// from pointer
			const_vectorIterator(const const_vectorIterator &rhs);	// copy

			// operator overloads
			const_vectorIterator&	operator=(const const_vectorIterator& rhs);
			const_vectorIterator&	operator++();
			const_vectorIterator	operator++(int n);
			const_vectorIterator	operator+(difference_type n) const;
			const_vectorIterator&	operator+=(difference_type n);
			const_vectorIterator&	operator--();
			const_vectorIterator	operator--(int n);
			const_vectorIterator	operator-(difference_type n) const;
			const_vectorIterator&	operator-=(difference_type n);
			reference				operator*() const;
			reference				operator[](difference_type n) const;
			pointer					operator->() const;
			bool					operator==(const const_vectorIterator& rhs) const;
			bool					operator!=(const const_vectorIterator& rhs) const;
			bool					operator<(const const_vectorIterator& rhs) const;
			bool					operator<=(const const_vectorIterator& rhs) const;
			bool					operator>(const const_vectorIterator& rhs) const;
			bool					operator>=(const const_vectorIterator& rhs) const;

		private:

			value_type				*_ptr;
	};
}

# include "vectorIterator.ipp"

#endif
