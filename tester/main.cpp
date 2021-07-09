/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 00:16:07 by user42            #+#    #+#             */
/*   Updated: 2021/07/09 02:05:48 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stack>

#include "test_stack.hpp"


#if defined(TESTER)

# if defined(FT)
#  define CONTAINER ft
	std::string		filename("ft");
# else
#  define CONTAINER std
	std::string		filename("stl");
# endif

int main()
{
	std::ofstream	output(filename.append(".out").c_str());
	std::ofstream	time(filename.append(".time").c_str());

	test_vector<CONTAINER::vector>(output, time);
	//test_map<CONTAINER::map>(output, time);
	stack::test<CONTAINER::stack>(output, time);

	output.close();
	time.close();

	return (0);
}

#elif defined(CHECKER)

# define FT			0
# define STL		1
# define OUTPUT		0
# define TIME		1
# define B_PURPLE	"\033[35;01m"	// bold
# define BOLD		"\033[01m"
# define YELLOW		"\033[33m"
# define B_GREEN	"\033[32;01m"	// bold
# define B_RED		"\033[31;01m"	// bold
# define RESET		"\033[00m"

// prototypes
void	print_container_name(std::string cntr_name);
void	print_function_name(std::string func_name, std::ifstream time_fs[2]);
void	print_result(std::string ft, std::string stl);
void	print_separator(char sep, int size);
float	compare_time(std::ifstream time_fs[2]);
float	get_avg_time(std::ifstream& file);

int	main()
{
	std::ifstream	files[2][2];	// file streams array

	// open output files from tester
	files[OUTPUT][FT].open("ft.out");
	files[OUTPUT][STL].open("stl.out");
	files[TIME][FT].open("ft.out.time");
	files[TIME][STL].open("stl.out.time");

	while (!files[OUTPUT][STL].eof()) // read stl output
	{
		std::string	str[2][2];
		size_t		ret;

		// read a line from output files
		std::getline(files[OUTPUT][FT], ft);
		std::getline(files[OUTPUT][STL], stl);

		if ((ret = stl.find("= ", 0)) != std::string::npos) // character '=' is present
		{
			// read a line from output files
			std::getline(files[TIME][FT], ft_time);
			std::getline(files[TIME][STL], stl_time);

			if (ret == 0) // only one '=' means it is a function name
				print_function_name(stl, files[TIME]);
			else // more means it's a container
				print_container_name(stl);
		}
		else // no '=' means it's the result of a test
			print_result(ft, stl);
	}

	// close files
	files[OUTPUT][FT].close();
	files[OUTPUT][STL].close();
	files[TIME][FT].close();
	files[TIME][STL].close();

	return (0);
}

/*
** print container name in purple
** add a line with character '=' for aesthetic purpose
*/

void print_container_name(std::string name)
{
	std::cout << B_PURPLE;
	std::cout << std::endl << "=== " << name.substr(4) << " ";
	for (size_t i = 0 ; i < 80 - name.length() - 1 ; i++)
		std::cout << "=";
	std::cout << RESET << std::endl;	
}

/*
** print function name (duh)
** add separator lines before and after functione name
** also print the average ratio of time complexity between ft containers
** and official ones
*/

void print_function_name(std::string func_name, std::ifstream time_fs[2])
{
	float diff = compare_time(time_fs);

	print_separator('-', 80);
	std::cout << BOLD << func_name.substr(2) << " ";
	if (diff <= 20.f)
		std::cout << B_GREEN << "x" << diff << RESET << std::endl;
	else
		std::cout << B_RED << "x" << diff << RESET << std::endl;
	print_separator('-', 80);
}

/*
** print "size" characters and a newline
*/

void print_separator(char sep, int size)
{
	for (int i = 0 ; i < size ; i++)
		std::cout << sep;
	std::cout << std::endl;
}

/*
** compare results
** if equals prints OK
** else prints KO and show outputs
*/

void print_result(std::string ft, std::string stl)
{
	if (stl.compare(ft) == 0)
		std::cout << B_GREEN << "[OK]" << RESET << std::endl;
	else
	{
		std::cout << B_RED << "[KO]" << std::endl;
		std::cout << YELLOW << "ft:\t" << ft << std::endl;
		std::cout << "stl:\t" << stl << RESET << std::endl;
	}
}

/*
** print time complexity factor
** this factor is the number of times ft container is slower than stl one
** for the same task
*/

float compare_time(std::ifstream time_fs[2])
{
	float	time[2];

	time[FT] = get_avg_time(time_fs[FT]);
	time[STL] = get_avg_time(time_fs[STL]);

	if (time[STL] == time[FT])
		return (1);
	else if (time[STL] == 0)
		return (time[FT]);
	return (time[FT] / time[STL]);
}

/*
** read file until it reaches an empty line
** return average execution time from several function calls
*/

float get_avg_time(std::ifstream& file)
{
	std::string	str;
	float		i 		= 0;
	float		time	= 0;

	do
	{
		std::getline(file, str);
		time += atof(str.data());
		i++;
	} while (str.length() != 0);
	
	return (time / i);
}

#endif
