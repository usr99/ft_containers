/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.ipp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 22:02:49 by mamartin          #+#    #+#             */
/*   Updated: 2021/06/18 19:26:09 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.hpp"

namespace ft
{
	template <class T, class container>
	queue<T, container>::queue(const container_type &ctnr)
	{
		this->_cntr = ctnr;
	}

	template <class T, class container>
	bool queue<T, container>::empty() const
	{
		return (this->_cntr.empty());
	}

	template <class T, class container>
	typename queue<T, container>::size_type queue<T, container>::size() const
	{
		return (this->_cntr.size());
	}

	template <class T, class container>
	typename queue<T, container>::value_type& queue<T, container>::front()
	{
		return (this->_cntr.front());
	}

	template <class T, class container>
	const typename queue<T, container>::value_type& queue<T, container>::front() const
	{
		return (this->_cntr.front());
	}

	template <class T, class container>
	typename queue<T, container>::value_type& queue<T, container>::back()
	{
		return (this->_cntr.back());
	}

	template <class T, class container>
	const typename queue<T, container>::value_type& queue<T, container>::back() const
	{
		return (this->_cntr.back());
	}

	template <class T, class container>
	void queue<T, container>::push(const value_type &val)
	{
		this->_cntr.push_back(val);
	}

	template <class T, class container>
	void queue<T, container>::pop()
	{
		this->_cntr.pop_front();
	}
}
