/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.ipp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:21:18 by mamartin          #+#    #+#             */
/*   Updated: 2021/09/17 22:22:05 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorIterator.hpp"

namespace ft
{
	// Iterator class for ft::vector ===========================================
	template <class T>
	vectorIterator<T>::vectorIterator() :
		_ptr(NULL) {}

	template <class T>
	vectorIterator<T>::vectorIterator(value_type *ptr) :
		_ptr(ptr) {}

	template <class T>
	vectorIterator<T>::vectorIterator(const vectorIterator &rhs) :
		_ptr(rhs._ptr) {}

	template <class T>
	vectorIterator<T>&
	vectorIterator<T>::operator=(const vectorIterator& rhs)
	{
		_ptr = rhs._ptr;
		return (*this);
	}
	
	template <class T>
	vectorIterator<T>&
	vectorIterator<T>::operator++()
	{
		_ptr++;
		return (*this);
	}
	
	template <class T>
	vectorIterator<T>
	vectorIterator<T>::operator++(int n)
	{
		vectorIterator	tmp(*this);

		(void)n;
		operator++();
		return (tmp);
	}
	
	template <class T>
	vectorIterator<T>
	vectorIterator<T>::operator+(difference_type n) const
	{
		vectorIterator	tmp(*this);

		tmp._ptr += n;
		return (tmp);
	}

	template <class T>
	vectorIterator<T>&
	vectorIterator<T>::operator+=(difference_type n)
	{
		*this = operator+(n);
		return (*this);
	}

	template <class T>
	vectorIterator<T>&
	vectorIterator<T>::operator--()
	{
		_ptr--;
		return (*this);
	}
	
	template <class T>
	vectorIterator<T>
	vectorIterator<T>::operator--(int n)
	{
		vectorIterator	tmp(*this);

		(void)n;
		operator--();
		return (tmp);
	}
	
	template <class T>
	vectorIterator<T>
	vectorIterator<T>::operator-(difference_type n) const
	{
		vectorIterator	tmp(*this);
		
		tmp._ptr -= n;
		return (tmp);
	}

	template <class T>
	vectorIterator<T>&
	vectorIterator<T>::operator-=(difference_type n)
	{
		*this = operator-(n);
		return (*this);
	}

	template <class T>
	typename vectorIterator<T>::reference
	vectorIterator<T>::operator*() const
	{
		return (*_ptr);
	}
	
	template <class T>
	typename vectorIterator<T>::reference
	vectorIterator<T>::operator[](difference_type n) const
	{
		return (*(_ptr + n));
	}
	
	template <class T>
	typename vectorIterator<T>::pointer	
	vectorIterator<T>::operator->() const
	{
		return (_ptr);
	}	

	template <class T>
	bool
	vectorIterator<T>::operator==(const vectorIterator& rhs) const
	{
		return (_ptr == rhs._ptr);
	}
	
	template <class T>
	bool
	vectorIterator<T>::operator!=(const vectorIterator& rhs) const
	{
		return (_ptr != rhs._ptr);
	}

	template <class T>
	bool
	vectorIterator<T>::operator<(const vectorIterator& rhs) const
	{
		return (_ptr < rhs._ptr);
	}
	
	template <class T>
	bool
	vectorIterator<T>::operator<=(const vectorIterator& rhs) const
	{
		return (_ptr <= rhs._ptr);
	}
	
	template <class T>
	bool
	vectorIterator<T>::operator>(const vectorIterator& rhs) const
	{
		return (_ptr > rhs._ptr);
	}
	
	template <class T>
	bool
	vectorIterator<T>::operator>=(const vectorIterator& rhs) const
	{
		return (_ptr >= rhs._ptr);
	}
}
