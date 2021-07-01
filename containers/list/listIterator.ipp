/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listIterator.ipp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:36:49 by mamartin          #+#    #+#             */
/*   Updated: 2021/06/28 23:19:25 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listIterator.hpp"

namespace ft
{
	// Iterator class for ft::list =============================================
	template <class T>
	listIterator<T>::listIterator() :
		_ptr(NULL) {}
	
	template <class T>
	listIterator<T>::listIterator(Node *ptr) :
		_ptr(ptr) {}

	template <class T>
	listIterator<T>::listIterator(const listIterator &rhs)
	{
		*this = rhs;
	}
	
	template <class T>
	typename listIterator<T>::Node*
	listIterator<T>::getNode() const
	{
		return (_ptr);
	}


	template <class T>
	listIterator<T>&
	listIterator<T>::operator=(const listIterator& rhs)
	{
		_ptr = rhs._ptr;
		return (*this);
	}
	
	template <class T>
	listIterator<T>&
	listIterator<T>::operator++()
	{
		_ptr = _ptr->next;
		return (*this);
	}
	
	template <class T>
	listIterator<T>
	listIterator<T>::operator++(int n)
	{
		listIterator	tmp(*this);

		(void)n;
		operator++();
		return (tmp);
	}
	
	template <class T>
	listIterator<T>&
	listIterator<T>::operator--()
	{
		_ptr = _ptr->prev;
		return (*this);
	}
	
	template <class T>
	listIterator<T>
	listIterator<T>::operator--(int n)
	{
		listIterator	tmp(*this);

		(void)n;
		operator--();
		return (tmp);		
	}
	
	template <class T>
	typename listIterator<T>::reference
	listIterator<T>::operator*() const
	{
		return (_ptr->data);
	}
	
	template <class T>
	typename listIterator<T>::pointer
	listIterator<T>::operator->() const
	{
		return (&(_ptr->data));
	}
	
	template <class T>
	bool
	listIterator<T>::operator==(const listIterator& rhs) const
	{
		return (_ptr == rhs._ptr);
	}
	
	template <class T>
	bool
	listIterator<T>::operator!=(const listIterator& rhs) const
	{
		return (_ptr != rhs._ptr);
	}

	// Const iterator class for ft::list =======================================
	template <class T>
	const_listIterator<T>::const_listIterator() :
		_ptr(NULL) {}
	
	template <class T>
	const_listIterator<T>::const_listIterator(Node *ptr) :
		_ptr(ptr) {}

	template <class T>
	const_listIterator<T>::const_listIterator(const const_listIterator &rhs)
	{
		*this = rhs;
	}
	
	template <class T>
	const_listIterator<T>&
	const_listIterator<T>::operator=(const const_listIterator& rhs)
	{
		_ptr = rhs._ptr;
		return (*this);
	}
	
	template <class T>
	const_listIterator<T>&
	const_listIterator<T>::operator++()
	{
		_ptr = _ptr->next;
		return (*this);
	}
	
	template <class T>
	const_listIterator<T>
	const_listIterator<T>::operator++(int n)
	{
		const_listIterator	tmp(*this);

		(void)n;
		operator++();
		return (tmp);
	}
	
	template <class T>
	const_listIterator<T>&
	const_listIterator<T>::operator--()
	{
		_ptr = _ptr->prev;
		return (*this);
	}
	
	template <class T>
	const_listIterator<T>
	const_listIterator<T>::operator--(int n)
	{
		const_listIterator	tmp(*this);

		(void)n;
		operator--();
		return (tmp);		
	}
	
	template <class T>
	typename const_listIterator<T>::reference
	const_listIterator<T>::operator*() const
	{
		return (_ptr->data);
	}
	
	template <class T>
	typename const_listIterator<T>::pointer
	const_listIterator<T>::operator->() const
	{
		return (&(_ptr->data));
	}
	
	template <class T>
	bool
	const_listIterator<T>::operator==(const const_listIterator& rhs) const
	{
		return (_ptr == rhs._ptr);
	}
	
	template <class T>
	bool
	const_listIterator<T>::operator!=(const const_listIterator& rhs) const
	{
		return (_ptr != rhs._ptr);
	}
}
