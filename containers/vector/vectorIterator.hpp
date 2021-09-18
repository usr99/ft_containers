/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:56:22 by mamartin          #+#    #+#             */
/*   Updated: 2021/09/17 22:30:16 by mamartin         ###   ########.fr       */
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

			operator vectorIterator<const T>() const { return vectorIterator<const T>(_ptr); }

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

 		friend
		vectorIterator<T>
		operator+(typename vectorIterator<T>::difference_type n, const vectorIterator<T>& it)
		{
			return (it + n);
		}

		friend
		typename vectorIterator<T>::difference_type
		operator-(const vectorIterator<T>& lhs, const vectorIterator<T>& rhs)
		{
			return (lhs._ptr - rhs._ptr);
		}
	};
}

# include "vectorIterator.ipp"

#endif
