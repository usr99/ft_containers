/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.ipp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 23:42:44 by mamartin          #+#    #+#             */
/*   Updated: 2021/09/06 22:45:24 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapIterator.hpp"

namespace ft
{
	// Iterator class for ft::vector ===========================================
	template <class T>
	mapIterator<T>::mapIterator() :
		_ptr(NULL) {}

	template <class T>
	mapIterator<T>::mapIterator(node *ptr) :
		_ptr(ptr) {}

	template <class T>
	mapIterator<T>::mapIterator(const mapIterator &rhs) :
		_ptr(rhs._ptr) {}

	template <class T>
	typename mapIterator<T>::node*
	mapIterator<T>::get_node() const
	{
		return (_ptr);
	}

	template <class T>
	mapIterator<T>&
	mapIterator<T>::operator=(const mapIterator& rhs)
	{
		_ptr = rhs._ptr;
		return (*this);
	}
	
	template <class T>
	mapIterator<T>&
	mapIterator<T>::operator++()
	{
		if (!_ptr->right)
		{
			if (_ptr->parent->right == _ptr)
				_ptr = _ptr->parent;
			_ptr = _ptr->parent;
		}
		else
		{
			_ptr = _ptr->right;
			while (_ptr->left)
				_ptr = _ptr->left;
		}
		return (*this);
	}
	
	template <class T>
	mapIterator<T>
	mapIterator<T>::operator++(int n)
	{
		mapIterator<T> tmp = *this;

		(void)n;
		operator++();
		return (tmp);
	}
	
	template <class T>
	mapIterator<T>&
	mapIterator<T>::operator--()
	{
		if (!_ptr->left)
		{
			if (_ptr->parent->left == _ptr)
				_ptr = _ptr->parent;
			_ptr = _ptr->parent;
		}
		else
		{
			_ptr = _ptr->left;
			while (_ptr->right && _ptr->right != _ptr->parent)
				_ptr = _ptr->right;
		}
		return (*this);
	}
	
	template <class T>
	mapIterator<T>
	mapIterator<T>::operator--(int n)
	{
		mapIterator<T> tmp = *this;

		(void)n;
		operator--();
		return (tmp);
	}
	
	template <class T>
	typename mapIterator<T>::reference
	mapIterator<T>::operator*() const
	{
		return (_ptr->data);
	}
	
	template <class T>
	typename mapIterator<T>::pointer
	mapIterator<T>::operator->() const
	{
		return (&(_ptr->data));
	}
	
	template <class T>
	bool
	mapIterator<T>::operator==(const mapIterator& rhs) const
	{
		return (_ptr == rhs._ptr);
	}
	
	template <class T>
	bool
	mapIterator<T>::operator!=(const mapIterator& rhs) const
	{
		return (_ptr != rhs._ptr);
	}
}
