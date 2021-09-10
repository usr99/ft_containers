/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:18:16 by mamartin          #+#    #+#             */
/*   Updated: 2021/09/10 12:50:24 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <sstream>
# include <stdexcept>

# include "../utils/sort.hpp"
# include "../utils/type_traits.hpp"
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
			typedef vectorIterator<const value_type>			const_iterator;
			typedef reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef reverse_iterator<iterator>					reverse_iterator;
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
			vector(
				InputIterator first,
				typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last,
				const allocator_type& alloc = allocator_type()
				) : _array(NULL), _size(0), _size_available(0), _alloc(alloc)
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

			reverse_iterator rbegin()
			{
				return (reverse_iterator(--end()));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(--end()));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(--begin()));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(--begin()));
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
				{
					std::stringstream	ss;
					ss << "vector::_M_range_check: __n (which is ";
					ss << n << ") >= this->size() (which is " << size() << ")";
					throw std::out_of_range(ss.str());
				}
				return (_array[n]);
			}

			const_reference at(size_type n) const
			{
				if (n < 0 || n >= _size)
				{
					std::stringstream	ss;
					ss << "vector::_M_range_check: __n (which is ";
					ss << n << ") >= this->size() (which is " << size() << ")";
					throw std::out_of_range(ss.str());
				}
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
				
				if (_size + n > _size_available)
				{
					reserve(_size_available * 2 + n);
					position = begin() + i;
				}
	
				i = end() - position;
				iterator	it = end() + n - 1;

				while (i > 0)
				{
					*it = *(it - n);
					it--;
					i--;
				}

				for (size_type j = 0 ; j < n ; j++)
				{
					_alloc.construct(_array + (position - begin()), val);
					position++;
					_size++;
				}
			}

			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last)
			{
				InputIterator	tmp = first;
				size_t			n	= 0;

				while (first != last)
				{
					first++;
					n++;
				}

				typename iterator::difference_type	i = position - begin();
				
				if (_size + n > _size_available)
				{
					reserve(_size_available * 2 + n);
					position = begin() + i;
				}
	
				i = end() - position;
				iterator	it = end() + n - 1;

				while (i > 0)
				{
					*it = *(it - n);
					it--;
					i--;
				}

				first = tmp;
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
				value_type		*tmp_array;
				size_type		tmp_sz;
				allocator_type	tmp_alloc;

				tmp_array = _array; // swap arrays
				_array = x._array;
				x._array = tmp_array;

				tmp_sz = _size; // swap sizes
				_size = x._size;
				x._size = tmp_sz;
				
				tmp_sz = _size_available; // swap available sizes
				_size_available = x._size_available;
				x._size_available = tmp_sz;

				tmp_alloc = _alloc; // swap allocator objects
				_alloc = x._alloc;
				x._alloc = tmp_alloc;
			}

			void clear()
			{
				for (iterator it = --end() ; _size != 0 ; it--)
				{
					_alloc.destroy(_array + (it - begin()));
					_size--;
				}
			}

			allocator_type get_allocator() const
			{
				return (_alloc);
			}

		private:

			value_type*		_array;
			size_type		_size;
			size_type		_size_available;
			allocator_type	_alloc;
	
		// lhs == rhs
		friend bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()) && lhs._size == rhs._size);
		}

		// !(lhs == rhs)
		friend bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (!ft::equal(lhs.begin(), lhs.end(), rhs.begin()) || lhs._size != rhs._size);
		}

		// lhs < rhs
		friend bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

		// !(rhs < lhs)
		friend bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (!ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
		}

		// rhs < lhs		
		friend bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
		}

		// !(lhs < rhs)
		friend bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (!ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}
	};

	template <class T, class Alloc>
  	void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}
}

#endif
