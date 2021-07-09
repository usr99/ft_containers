/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 23:59:21 by user42            #+#    #+#             */
/*   Updated: 2021/07/01 13:45:06 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "../vector/vector.hpp"

namespace ft
{
	template <class T, class container = ft::vector<T> >
	class stack
	{
		public:

			// member types
			typedef T			value_type;
			typedef container	container_type;
			typedef size_t		size_type;

			explicit stack(const container_type &ctnr = container_type()); // constructor
			
			// member functions
			bool				empty() const;
			size_type			size() const;
			value_type			&top();
			const value_type	&top() const;
			void				push(const value_type &val);
			void				pop();

		private:

			container_type 		_cntr;

		// non member operators
		friend bool operator==(const stack<T, container> &lhs, const stack<T, container> &rhs)	{ return (lhs._cntr == rhs._cntr); }
		friend bool operator!=(const stack<T, container> &lhs, const stack<T, container> &rhs)	{ return (lhs._cntr != rhs._cntr); }
		friend bool operator<(const stack<T, container> &lhs, const stack<T, container> &rhs)	{ return (lhs._cntr < rhs._cntr); }
		friend bool operator<=(const stack<T, container> &lhs, const stack<T, container> &rhs)	{ return (lhs._cntr <= rhs._cntr); }
		friend bool operator>(const stack<T, container> &lhs, const stack<T, container> &rhs)	{ return (lhs._cntr > rhs._cntr); }
		friend bool operator>=(const stack<T, container> &lhs, const stack<T, container> &rhs)	{ return (lhs._cntr >= rhs._cntr); }
	};
}

# include "stack.ipp"

#endif
