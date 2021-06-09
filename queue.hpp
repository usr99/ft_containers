/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 23:59:21 by user42            #+#    #+#             */
/*   Updated: 2021/06/09 19:17:54 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include <deque>

namespace ft
{
	template <class T, class container = std::deque<T>>
	class queue
	{
		public:

			// member types
			typedef T			value_type;
			typedef container	container_type;
			typedef size_t		size_type;

			queue(const container_type& ctnr = container_type()); // constructor
			
			// member functions
			bool				empty() const;
			size_type			size() const;
			value_type&			front();
			const value_type&	front() const;
			value_type&			back();
			const value_type&	back() const;
			void				push(const value_type& val);
			void				pop();

		private:

			container_type 		_cntr;

		// non member operators
		friend bool operator==(const queue<T, container> &lhs, const queue<T, container> &rhs)	{ return (lhs._cntr == rhs._cntr); }
		friend bool operator!=(const queue<T, container> &lhs, const queue<T, container> &rhs)	{ return (lhs._cntr != rhs._cntr); }
		friend bool operator<(const queue<T, container> &lhs, const queue<T, container> &rhs)	{ return (lhs._cntr < rhs._cntr); }
		friend bool operator<=(const queue<T, container> &lhs, const queue<T, container> &rhs)	{ return (lhs._cntr <= rhs._cntr); }
		friend bool operator>(const queue<T, container> &lhs, const queue<T, container> &rhs)	{ return (lhs._cntr > rhs._cntr); }
		friend bool operator>=(const queue<T, container> &lhs, const queue<T, container> &rhs)	{ return (lhs._cntr >= rhs._cntr); }
	};
}

# include "queue.ipp"

#endif
