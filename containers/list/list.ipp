/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.ipp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:39:12 by mamartin          #+#    #+#             */
/*   Updated: 2021/06/28 23:45:08 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"

namespace ft
{
	// default constructor
	template <class T, class Alloc>
	list<T, Alloc>::list(const allocator_type &alloc) :
		_alloc(alloc), _size(0)
	{
		// alloc sentinel node
		_list = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(_list, Node(_list, _list));
	}

	// fill constructor
	template <class T, class Alloc>
	list<T, Alloc>::list(size_type n, const value_type &val, const allocator_type &alloc) :
		_alloc(alloc), _size(0)
	{
		_list = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(_list, Node(_list, _list));
		insert(begin(), n, val);
	}

	// range constructor
	template <class T, class Alloc>
	template <class InputIterator>
	list<T, Alloc>::list(InputIterator first, InputIterator last, const allocator_type &alloc) :
		_alloc(alloc), _size(0)
	{
		_list = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(_list, Node(_list, _list));
		insert(begin(), first, last);
	}

	// copy constructor
	template <class T, class Alloc>
	list<T, Alloc>::list(const list &x) :
		_alloc(x._alloc), _size(0)
	{
		_list = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(_list, Node(_list, _list));
		insert(begin(), x.begin(), x.end());
	}

	// destructor
	template <class T, class Alloc>
	list<T, Alloc>::~list()
	{
		clear();
		node_alloc(_alloc).deallocate(_list, 1);
	}

	template <class T, class Alloc>
	typename list<T, Alloc>::iterator
	list<T, Alloc>::begin()
	{
		return (iterator(_list->next));
	}

	template <class T, class Alloc>
	typename list<T, Alloc>::const_iterator
	list<T, Alloc>::begin() const
	{
		return (const_iterator(_list->next));
	}

	template <class T, class Alloc>
	typename list<T, Alloc>::iterator
	list<T, Alloc>::end()
	{
		return (iterator(_list));
	}

	template <class T, class Alloc>
	typename list<T, Alloc>::const_iterator
	list<T, Alloc>::end() const
	{
		return (const_iterator(_list));
	}

	template <class T, class Alloc>
	typename list<T, Alloc>::reverse_iterator
	list<T, Alloc>::rbegin()
	{
		iterator	it = end();

		return (reverse_iterator(--it));
	}

	template <class T, class Alloc>
	typename list<T, Alloc>::reverse_iterator
	list<T, Alloc>::rend()
	{
		return (reverse_iterator(end()));
	}

	template <class T, class Alloc>
	bool
	list<T, Alloc>::empty() const
	{
		return (!_size);
	}
	
	template <class T, class Alloc>
	typename list<T, Alloc>::size_type
	list<T, Alloc>::size() const
	{
		return (_size);
	}

	template <class T, class Alloc>
	typename list<T, Alloc>::size_type
	list<T, Alloc>::max_size() const
	{
		return (node_alloc(_alloc).max_size());
	}

	template <class T, class Alloc>
	typename list<T, Alloc>::reference		
	list<T, Alloc>::front()
	{
		return (_list->next->data);
	}
	
	template <class T, class Alloc>
	typename list<T, Alloc>::const_reference
	list<T, Alloc>::front() const
	{
		return (_list->next->data);
	}
	
	template <class T, class Alloc>
	typename list<T, Alloc>::reference		
	list<T, Alloc>::back()
	{
		return (_list->prev->data);
	}
	
	template <class T, class Alloc>
	typename list<T, Alloc>::const_reference
	list<T, Alloc>::back() const
	{
		return (_list->prev->data);
	}

	template <class T, class Alloc>
	template <class InputIterator>
	void
	list<T, Alloc>::assign(InputIterator first, InputIterator last)
	{
		clear();
		insert(begin(), first, last);
	}
	
	template <class T, class Alloc>
	void
	list<T, Alloc>::assign(size_type n, const value_type &val)
	{
		clear();
		insert(begin(), n, val);
	}

	template <class T, class Alloc>
	void
	list<T, Alloc>::push_front(const value_type &val)
	{
		insert(begin(), val);
	}
	
	template <class T, class Alloc>
	void
	list<T, Alloc>::pop_front()
	{
		erase(begin());
	}

	template <class T, class Alloc>
	void
	list<T, Alloc>::push_back(const value_type &val)
	{
		insert(end(), val);
	}
	
	template <class T, class Alloc>
	void
	list<T, Alloc>::pop_back()
	{
		erase(--end());
	}

	template <class T, class Alloc>
	typename list<T, Alloc>::iterator
	list<T, Alloc>::insert(iterator position, const value_type &val)
	{
		Node	*newNode;
		Node	*node;
		
		node = position.getNode(); // get node from iterator
		newNode = node_alloc(_alloc).allocate(1); // alloc new node
		node_alloc(_alloc).construct(newNode, Node(val, node->prev, node));
		node->prev->next = newNode; // insert new node
		node->prev = newNode;
		_size++;
		return (iterator(newNode)); // return iterator to new node
	}

	template <class T, class Alloc>
	void
	list<T, Alloc>::insert(iterator position, size_type n, const value_type &val)
	{
		for (size_type i = 0 ; i < n ; i++)
			insert(position, val);
	}

	template <class T, class Alloc>
	template <class InputIterator>
	void
	list<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last)
	{
		while (first != last)
		{
			insert(position, *first);
			first++;
		}
	}

	template <class T, class Alloc>
	typename list<T, Alloc>::iterator
	list<T, Alloc>::erase(iterator position)
	{
		Node	*target;

		target = position.getNode(); // get node from iterator
		position++;
		target->prev->next = target->next; // unlink node
		target->next->prev = target->prev;
		node_alloc(_alloc).deallocate(target, 1);
		_size--;
		return (position); // return iterator to next element
	}

	template <class T, class Alloc>
	typename list<T, Alloc>::iterator
	list<T, Alloc>::erase(iterator first, iterator last)
	{
		while (first != last)
		{
			erase(first);
			first++;
		}
		return (last);
	}

	template <class T, class Alloc>
	void
	list<T, Alloc>::swap(list& x)
	{
		iterator	it = begin();
		splice(begin(), x); // insert x at the beginning of the list
		x.splice(x.begin(), *this, it, end()); // insert list in x
	}

	template <class T, class Alloc>
	void
	list<T, Alloc>::resize(size_type n, value_type val)
	{
		if (n < _size) // too big
		{
			while (_size != n)
				pop_back(); // destroy last elements
		}
		else // too small
		{
			while (_size != n)
				push_back(val); // add elements
		}
	}

	template <class T, class Alloc>
	void
	list<T, Alloc>::clear()
	{
		while (!empty())
			pop_back();
	}

	template <class T, class Alloc>
	void
	list<T, Alloc>::splice(iterator position, list &x)
	{
		Node		*start;
		Node		*end;

		// get nodes from iterators
		start = position.getNode();		// where to insert in list
		end = x.end().getNode()->prev;	// last element of x

		// link beginning of x
		start->prev->next = x._list->next;
		x._list->next->prev = start->prev;
		
		// link end of x 
		start->prev = end;
		end->next = start;

		// x is now an empty list
		x._list->next = x._list;
		x._list->prev = x._list;
		x._size = 0;

		_size += x.size();
	}
	
	template <class T, class Alloc>
	void
	list<T, Alloc>::splice(iterator position, list &x, iterator i)
	{
		Node		*where;
		Node		*node;

		// get nodes from iterators
		where = position.getNode();	// where to insert in list
		node = i.getNode();			// node to insert
		
		// unlink node from x
		node->prev->next = node->next;
		node->next->prev = node->prev;

		// link node to list
		node->next = where;
		node->prev = where->prev;
		
		// link list to node
		where->prev->next = node;
		where->prev = node;
		
		_size++;
		x._size--;
	}
	
	template <class T, class Alloc>
	void
	list<T, Alloc>::splice(iterator position, list &x, iterator first, iterator last)
	{
		while (first != last)
		{
			iterator	tmp = first;

			tmp++; // iterator to next element in x
			splice(position, x, first); // element is removed
			first = tmp;
		}
	}

	template <class T, class Alloc>
	void
	list<T, Alloc>::remove(const value_type &val)
	{
		for (iterator it = begin() ; it != end() ; it++)
		{
			if (*it == val)
				it = erase(it);
		}
	}

	template <class T, class Alloc>
	template <class Predicate>
	void
	list<T, Alloc>::remove_if(Predicate pred)
	{
		iterator	it = begin();
		
		while (it != end())
		{
			if (pred(*it) == true)
				it = erase(it);
			else
				it++;
		}		
	}

	template <class T, class Alloc>
	void
	list<T, Alloc>::unique()
	{
		unique(ft::equal<value_type>()); // compare with operator==
	}

	template <class T, class Alloc>
	template <class BinaryPredicate>
	void
	list<T, Alloc>::unique(BinaryPredicate binary_pred)
	{
		iterator	curr = ++begin();
		iterator	prev = begin();
		iterator	tmp;

		while (curr != end())
		{
			if (binary_pred(*curr, *prev) == true)
				curr = erase(curr); // erase duplicates
			else
			{
				prev++;
				curr++;
			}
		}		
	}

	template <class T, class Alloc>
	void
	list<T, Alloc>::merge(list &x)
	{
		merge(x, ft::less_than<value_type>()); // compare with operator<
	}

	template <class T, class Alloc>
	template <class Compare>
	void
	list<T, Alloc>::merge(list &x, Compare comp)
	{
		iterator	i = begin();
		iterator	j = x.begin();

		while (i != end() && j != x.end())
		{
			if (!comp(*i, *j))
			{
				iterator	tmp = j;

				tmp++;
				splice(i, x, j);
				j = tmp;
			}
			else
				i++;
		}
		if (x.size() != 0)
			splice(end(), x);
	}

	template <class T, class Alloc>
	void
	list<T, Alloc>::sort()
	{
		sort(ft::less_than<value_type>()); // compare with operator<
	}

	template <class T, class Alloc>
	template <class Compare>
	void
	list<T, Alloc>::sort(Compare comp)
	{
		/*
		merge sort
		O(n) = nlog(n)
		stable
		https://fr.wikipedia.org/wiki/Tri_fusion
		*/
		_mergeSort(_list, _size, comp);
	}
	
	template <class T, class Alloc>
	void
	list<T, Alloc>::reverse()
	{
		Node	*lst;

		lst = _list;
		for (size_type i = 0 ; i <= _size ; i++)
		{
			Node	*tmp = lst->next;

			// swap next and prev pointers
			lst->next = lst->prev;
			lst->prev = tmp;
			lst = lst->next;
		}
	}

	template <class T, class Alloc>
	list<T, Alloc>&
	list<T, Alloc>::operator=(const list &x)
	{
		assign(x.begin(), x.end());
		return (*this);
	}
	
	template <class T, class Alloc>
	template <class Compare>
	typename list<T, Alloc>::Node*
	list<T, Alloc>::_mergeSort(Node *first, size_type n, Compare comp)
	{
		size_type	second_sz	= n / 2; 
		size_type	first_sz	= n - second_sz; 
		Node*		second		= first;

		if (first_sz >= 2)
		{
			second = _mergeSort(first, first_sz, comp);
			if (second_sz >= 2)
				_mergeSort(second, second_sz, comp);
		}
		else
			second = first->next;

		second = _merge(first, first_sz, second, second_sz, comp);
		return (second);
	}
	
	template <class T, class Alloc>
	template <class Compare>
	typename list<T, Alloc>::Node*
	list<T, Alloc>::_merge(Node *first, size_type size1, Node *second, size_type size2, Compare comp)
	{
		while (true)
		{
			if (!comp(first->next->data, second->next->data))
			{
				Node	*tmp = second->next;

				second->next = tmp->next;
				tmp->next->prev = second;

				tmp->prev = first;
				tmp->next = first->next;
				
				first->next->prev = tmp;
				first->next = tmp;

				if (size2 == 1)
					break;
				size2--;
			}
			else
			{
				if (size1 == 1)
				{
					while (size2 >= 1)
					{
						second = second->next;
						size2--;
					}
					break;
				}
				size1--;
			}
			first = first->next;
		}
		return (second);
	}
}
