/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:35:45 by mamartin          #+#    #+#             */
/*   Updated: 2021/09/09 17:46:40 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
# include "iterator_traits.hpp"

namespace ft
{
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

	template <class Iterator>
	class reverse_iterator
	{
		public:

			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;

			reverse_iterator();
			explicit reverse_iterator(iterator_type it);
			template <class Iter>
				reverse_iterator(const reverse_iterator<Iter>& rev_it);

			iterator_type		base() const;
			reference			operator*() const;
			reverse_iterator	operator+(difference_type n) const;
			reverse_iterator&	operator++();
			reverse_iterator	operator++(int n);
			reverse_iterator&	operator+=(difference_type n);
			reverse_iterator	operator-(difference_type n) const;
			reverse_iterator&	operator--();
			reverse_iterator	operator--(int n);
			reverse_iterator&	operator-=(difference_type n);
			pointer				operator->() const;
			reference			operator[](difference_type n) const;

		private:

			iterator_type		_it;

		friend bool				operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)	{ return (lhs._it == rhs._it); }
		friend bool				operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)	{ return (lhs._it != rhs._it); }
		friend bool				operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)		{ return (lhs._it > rhs._it); }
		friend bool				operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)	{ return (lhs._it >= rhs._it); }
		friend bool				operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)		{ return (lhs._it < rhs._it); }
		friend bool				operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)	{ return (lhs._it <= rhs._it); }
	};
}

# include "iterator.ipp"

#endif
