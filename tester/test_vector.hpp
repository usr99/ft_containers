/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 02:06:14 by mamartin          #+#    #+#             */
/*   Updated: 2021/07/09 02:09:34 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../containers/vector/vector.hpp"
#include "utils.hpp"

namespace vector
{
	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	test(std::ofstream& output, std::ofstream& time)
	{
		output << "=== VECTOR" << std::endl;
		time << "=== VECTOR" << std::endl;
	}
}
