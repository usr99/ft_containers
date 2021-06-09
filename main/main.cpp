/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 00:16:07 by user42            #+#    #+#             */
/*   Updated: 2021/06/09 19:50:59 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_tester.hpp"
#include "queue_tester.hpp"

void	test_stack();
void	test_queue();
void	test(const std::string &ft, const std::string &std);

int main()
{
	test_stack();
	test_queue();
	return (0);
}

void test_stack()
{
	std::cout << "\033[35;01m" << "--- ft::stack" << "\033[0m" << std::endl;
	std::cout << "Constructor :\t";
	test(stack::constructor<ft::stack>(), stack::constructor<std::stack>()); // constructor
	std::cout << "empty :\t\t";
	test(stack::empty<ft::stack>(), stack::empty<std::stack>()); // empty()
	std::cout << "size :\t\t";
	test(stack::size<ft::stack>(), stack::size<std::stack>()); // size()
	std::cout << "top :\t\t";
	test(stack::top<ft::stack>(), stack::top<std::stack>()); // top ()
	std::cout << "push & pop :\t";
	test(stack::push_pop<ft::stack>(), stack::push_pop<std::stack>()); // push() and pop()
	std::cout << "operators :\t";
	test(stack::operators<ft::stack>(), stack::operators<std::stack>()); // non members operators
}

void test_queue()
{
	std::cout << "\033[35;01m" << "--- ft::queue" << "\033[0m" << std::endl;
	std::cout << "Constructor :\t";
	test(queue::constructor<ft::queue>(), queue::constructor<std::queue>()); // constructor
	std::cout << "empty :\t\t";
	test(queue::empty<ft::queue>(), queue::empty<std::queue>()); // empty()
	std::cout << "size :\t\t";
	test(queue::size<ft::queue>(), queue::size<std::queue>()); // size()
	std::cout << "front :\t\t";
	test(queue::front<ft::queue>(), queue::front<std::queue>()); // front()
	std::cout << "back :\t\t";
	test(queue::back<ft::queue>(), queue::back<std::queue>()); // back()
	std::cout << "push & pop :\t";
	test(queue::push_pop<ft::queue>(), queue::push_pop<std::queue>()); // push() and pop()
	std::cout << "operators :\t";
	test(queue::operators<ft::queue>(), queue::operators<std::queue>()); // non members operators
}

void test(const std::string &ft, const std::string &std)
{
	if (ft.compare(std) == 0) // no diff print OK
		std::cout << "[" << "\033[32m" << "OK" << "\033[0m" << "]" << std::endl;
	else // print both strings to compare
	{
		std::cout << "[" << "\033[31m" << "KO" << "\033[0m" << "]" << std::endl;
		std::cout << "\033[33m" << "ft:  " << ft << "\033[0m" << std::endl;
		std::cout << "\033[33m" << "std: " << std << "\033[0m" << std::endl;
	}
}
