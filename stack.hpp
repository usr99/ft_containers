/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 23:59:21 by user42            #+#    #+#             */
/*   Updated: 2021/06/07 21:47:10 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <deque>

namespace ft
{
	template <class T, class container = std::deque<T>>
	class stack
	{
		public:

			// member types
			typedef T			value_type;
			typedef container	container_type;
			typedef size_t		size_type;

			stack(const container_type &ctnr = container_type()); // constructor
			
			// member functions
			bool				empty() const;
			size_type			size() const;
			value_type			&top();
			const value_type	&top() const;
			void				push(const value_type &val);
			void				pop();

		private:

			container_type 		_cntr;
	};
}

# include "stack.ipp"

#endif
