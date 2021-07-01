/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 02:09:52 by mamartin          #+#    #+#             */
/*   Updated: 2021/06/28 23:38:57 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_HPP
# define SORT_HPP

# include <iostream>

namespace ft
{
	template <class value_type>
	struct equal
	{
		bool	operator()(const value_type &lhs, const value_type &rhs) { return (lhs == rhs); }

		template <class T>
		static bool	compare(const T &lhs, const T &rhs)
		{
			typename T::const_iterator	lit = lhs.begin();
			typename T::const_iterator	rit = rhs.begin();
	
			// check if sizes differ
			if (lhs.size() != rhs.size())
				return (false);
	
			// sequentially compare each element
			while (lit != lhs.end() && rit != rhs.end())
			{
				if (*lit != *rit) // lhs != rhs
					return (false);
				lit++;
				rit++;
			}
			return (true); // lhs == rhs
		}
	};

	template <class value_type>
	struct less_than
	{
		bool	operator()(const value_type &lhs, const value_type &rhs) { return (lhs < rhs); }

		template <class T>
		static bool	compare(const T &lhs, const T &rhs)
		{
			typename T::const_iterator	lit = lhs.begin();
			typename T::const_iterator	rit = rhs.begin();
	
			while (lit != lhs.end())
			{
				if (rit == rhs.end() || *rit < *lit)
					return (false); // rhs < lhs
				else if (*lit < *rit)
					return (true); // lhs < rhs
				lit++;
				rit++;
			}
			return (rit != rhs.end()); // compare sizes
		}
	};
}

#endif
