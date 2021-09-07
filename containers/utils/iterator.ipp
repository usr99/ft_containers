/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.ipp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 23:36:03 by mamartin          #+#    #+#             */
/*   Updated: 2021/07/09 16:37:12 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterator.hpp"

namespace ft
{
	template <class Iterator>
	reverse_iterator<Iterator>::reverse_iterator() :
		_it(iterator_type()) {}

	template <class Iterator>
	reverse_iterator<Iterator>::reverse_iterator(iterator_type it) :
		_it(it) {}

	template <class Iterator>
	template <class Iter>
		reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<Iter>& rev_it) :
		_it(rev_it._it) {}

	template <class Iterator>
	typename reverse_iterator<Iterator>::iterator_type
	reverse_iterator<Iterator>::base() const
	{
		return (_it);
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::reference
	reverse_iterator<Iterator>::operator*() const
	{
		return (_it.operator*());
	}

	template <class Iterator>
	reverse_iterator<Iterator>
	reverse_iterator<Iterator>::operator+(difference_type n) const
	{
		reverse_iterator	tmp(*this);

		tmp._it = tmp._it + n;
		return (tmp);
	}

	template <class Iterator>
	reverse_iterator<Iterator>&
	reverse_iterator<Iterator>::operator++()
	{
		_it--;
		return (*this);
	}

	template <class Iterator>
	reverse_iterator<Iterator>
	reverse_iterator<Iterator>::operator++(int n)
	{
		reverse_iterator	tmp(*this);

		(void)n;
		operator++();
		return (tmp);
	}

	template <class Iterator>
	reverse_iterator<Iterator>&
	reverse_iterator<Iterator>::operator+=(difference_type n)
	{
		*this = operator+(n);
		return (*this);
	}

	template <class Iterator>
	reverse_iterator<Iterator>
	reverse_iterator<Iterator>::operator-(difference_type n) const
	{
		reverse_iterator	tmp(*this);
		
		tmp._it = tmp._it - n;
		return (tmp);
	}

	template <class Iterator>
	reverse_iterator<Iterator>&
	reverse_iterator<Iterator>::operator--()
	{
		_it++;
		return (*this);
	}

	template <class Iterator>
	reverse_iterator<Iterator>
	reverse_iterator<Iterator>::operator--(int n)
	{
		reverse_iterator	tmp(*this);

		(void)n;
		operator--();
		return (tmp);
	}

	template <class Iterator>
	reverse_iterator<Iterator>&
	reverse_iterator<Iterator>::operator-=(difference_type n)
	{
		*this = operator-(n);
		return (*this);
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::pointer
	reverse_iterator<Iterator>::operator->() const
	{
		return (_it.operator->());
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::reference
	reverse_iterator<Iterator>::operator[](difference_type n) const
	{
		return (_it[n]);
	}

	template <class Iterator>
  	reverse_iterator<Iterator>
	operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{
		return (rev_it + n);
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type
	operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (rhs.base() - lhs.base());
	}
}
