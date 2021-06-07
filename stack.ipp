/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.ipp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:24:26 by mamartin          #+#    #+#             */
/*   Updated: 2021/06/07 21:51:46 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"

namespace ft
{
	// member functions

	template <class T, class container>
	stack<T, container>::stack(const container_type &ctnr)
	{
		this->_cntr = ctnr;
	}

	template <class T, class container>
	bool stack<T, container>::empty() const
	{
		return (this->_cntr.empty());
	}

	template <class T, class container>
	typename stack<T, container>::size_type stack<T, container>::size() const
	{
		return (this->_cntr.size());
	}

	template <class T, class container>
	typename stack<T, container>::value_type &stack<T, container>::top()
	{
		return (this->_cntr.back());
	}

	template <class T, class container>
	const typename stack<T, container>::value_type &stack<T, container>::top() const
	{
		return (this->_cntr.back());
	}

	template <class T, class container>
	void stack<T, container>::push(const value_type &val)
	{
		this->_cntr.push_back(val);
	}

	template <class T, class container>
	void stack<T, container>::pop()
	{
		this->_cntr.pop_back();
	}

	// non member operators

	template <class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.cntr == rhs.cntr);
	}

	template <class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.cntr != rhs.cntr);
	}

	template <class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.cntr < rhs.cntr);
	}

	template <class T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.cntr <= rhs.cntr);
	}

	template <class T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.cntr > rhs.cntr);
	}

	template <class T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.cntr >= rhs.cntr);
	}
}
