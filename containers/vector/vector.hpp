/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:18:16 by mamartin          #+#    #+#             */
/*   Updated: 2021/07/05 18:04:10 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>

# include "../utils/sort.hpp"
# include "vectorIterator.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:

			// member types
			typedef	T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef vectorIterator<value_type>					iterator;
			typedef const_vectorIterator<value_type>			const_iterator;
			typedef reverse_iterator<iterator>					reverse_iterator;
			// const reverse
			typedef size_t										size_type;

			// default constructor
			explicit vector(const allocator_type& alloc = allocator_type()) :
				_array(NULL), _size(0), _size_available(0), _alloc(alloc) {}
			
			// fill constructor
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
				_array(NULL), _size(0), _size_available(0), _alloc(alloc)
			{
				insert(begin(), n, val);
			}
			
			// range constructor
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) :
				_array(NULL), _size(0), _size_available(0), _alloc(alloc)
			{
				insert(begin(), first, last);
			}

			// copy constructor
			vector(const vector& x) :
				_array(NULL), _size(0), _size_available(0), _alloc(x._alloc)
			{
				*this = x;
			}
			
			// destructor
			~vector()
			{
				clear();
				_alloc.deallocate(_array, _size_available);
			}

			vector& operator=(const vector& x)
			{
				assign(x.begin(), x.end());
				return (*this);
			}

			iterator begin()
			{
				return (iterator(_array));
			}

			const_iterator begin() const
			{
				return (const_iterator(_array));
			}

			iterator end()
			{
				return (iterator(_array + _size));
			}

			const_iterator end() const
			{
				return (const_iterator(_array + _size));
			}

			size_type size() const
			{
				return (_size);
			}

			size_type max_size() const
			{
				return (_alloc.max_size());
			}

			void resize(size_type n, value_type val = value_type())
			{
				if (n < _size)
				{
					while (_size != n)
						pop_back();
				}
				else
				{
					while (_size != n)
						push_back(val);
				}
			}

			size_type capacity() const
			{
				return (_size_available);
			}

			bool empty() const
			{
				return (!_size);
			}

			void reserve(size_type n)
			{
				if (n > _size_available)
				{
					if (n > max_size())
						throw std::length_error("vector::_M_fill_insert");

					value_type	*tmp;

					tmp = _alloc.allocate(n);
					for (size_type i = 0 ; i < _size ; i++)
						_alloc.construct(tmp + i, _array[i]);

					_alloc.deallocate(_array, _size_available);
					_array = tmp;
					_size_available = n;
				}
			}

			reference operator[](size_type n)
			{
				return (_array[n]);
			}

			const_reference operator[](size_type n) const
			{
				return (_array[n]);
			}

			reference at(size_type n)
			{
				if (n < 0 || n >= _size)
					throw std::out_of_range("vector::_M_range_check");
				return (_array[n]);
			}

			const_reference at(size_type n) const
			{
				if (n < 0 || n >= _size)
					throw std::out_of_range("vector::_M_range_check");
				return (_array[n]);
			}

			reference front()
			{
				return (_array[0]);
			}
			
			const_reference front() const
			{
				return (_array[0]);
			}

			reference back()
			{
				return (_array[_size - 1]);
			}
			
			const_reference back() const
			{
				return (_array[_size - 1]);
			}

			template <class InputIterator>
			void assign(InputIterator first, InputIterator last)
			{
				clear();
				insert(begin(), first, last);
			}

			void assign(size_type n, const value_type& val)
			{
				clear();
				insert(begin(), n, val);
			}

			void push_back(const value_type& val)
			{
				insert(end(), val);
			}

			void pop_back()
			{
				erase(--end());
			}

			iterator insert(iterator position, const value_type& val)
			{
				typename iterator::difference_type	i = end() - position;

				if (_size == _size_available)
					reserve(_size_available * 2 + 1);

				iterator	it = end();

				while (i > 0)
				{
					*it = *(it - 1);
					it--;
					i--;
				}

				_alloc.construct(_array + (it - begin()), val);
				_size++;
				return (it);
			}

			void insert(iterator position, size_type n, const value_type& val)
			{
				typename iterator::difference_type	i = position - begin();
				
				if (_size == _size_available)
					reserve(_size_available * 2 + n);

				position = begin() + i;
				for (size_type i = 0 ; i < n ; i++)
					position = insert(position, val);
			}

			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					position = insert(position, *first) + 1;
					first++;
				}
			}

			iterator erase(iterator position)
			{
				_alloc.destroy(_array + (position - begin()));
				for (iterator it = position ; it != end() - 1 ; ++it)
					*it = *(it + 1);
				_size--;
				return (position);
			}

			iterator erase(iterator first, iterator last)
			{
				typename iterator::difference_type	i;

				for (i = last - first ; i > 0 ; i--)
					first = erase(first);
				return (first);
			}

			void swap(vector& x)
			{
				// swap hein
				(void)x;
			}

			void clear()
			{
				while (!empty())
					pop_back();
			}

			allocator_type get_allocator() const
			{
				return (_alloc);
			}

		private:

			T*				_array;
			size_type		_size;
			size_type		_size_available;
			allocator_type	_alloc;
	};

	// lhs == rhs
	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	// !(lhs == rhs)
	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	// lhs < rhs
	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	// !(rhs < lhs)
	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}
	
	// rhs < lhs		
	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}

	// !(lhs < rhs)
	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
  	void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}
}

#endif
