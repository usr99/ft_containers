/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 02:07:44 by mamartin          #+#    #+#             */
/*   Updated: 2021/07/09 02:08:11 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <fstream>

void	print_exec_tm(std::ofstream& ofs, struct timeval& tv)
{
	long	time_diff = tv.tv_sec * 1000000 + tv.tv_usec;

	gettimeofday(&tv, NULL);
	ofs << (tv.tv_sec * 1000000 + tv.tv_usec) - time_diff << std::endl;
}
