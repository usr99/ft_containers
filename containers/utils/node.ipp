/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.ipp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:54:07 by mamartin          #+#    #+#             */
/*   Updated: 2021/06/18 22:46:01 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.hpp"

namespace ft
{
	// node structure for ft::list =============================================

	template <class T>
	listNode<T>::listNode() :
		data(T()), prev(NULL), next(NULL) {}

	template <class T>
	listNode<T>::listNode(listNode *prev, listNode *next) :
		data(T()), prev(prev), next(next) {}

	template <class T>
	listNode<T>::listNode(const T& val, listNode *previous, listNode *next) :
		data(val), prev(previous), next(next) {}

	template <class T>
	listNode<T>::listNode(const listNode& rhs)
	{
		*this = rhs;
		prev = rhs.prev;
		next = rhs.next;
	}

	template <class T>
	listNode<T>&
	listNode<T>::operator=(const listNode& rhs)
	{
		data = rhs.data;
		return (*this);
	}
	
	// =========================================================================
}
