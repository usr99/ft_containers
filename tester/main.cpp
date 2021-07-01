/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 00:16:07 by user42            #+#    #+#             */
/*   Updated: 2021/06/30 00:19:50 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_tester.hpp"
#include "stack_tester.hpp"
#include "queue_tester.hpp"

#include "../containers/list/list.hpp"
#include "../containers/vector/vector.hpp"

void	test_list();
void	test_stack();
void	test_queue();
void	test(const std::string &ft, const std::string &std);

#define TMP	ft

int main()
{
	TMP::vector<int>			vect((size_t)5, 100);
	TMP::vector<int>::iterator	it;

	for (int i = 0 ; i < vect.size() ; i++)
		std::cout << vect[i] << std::endl;

	//test_list();
	//test_stack();
	//test_queue();
	return (0);
}

void test_list()
{
	std::cout << "\033[35;01m" << "--- ft::list" << "\033[0m" << std::endl;
	std::cout << "Constructor :\t";
	test(list::constructor<ft::list>(), list::constructor<std::list>()); // constructor
	std::cout << "begin & end :\t";
	test(list::begin_end<ft::list>(), list::begin_end<std::list>()); // begin() and end()
	std::cout << "rbegin & rend :\t";
	test(list::rbegin_rend<ft::list>(), list::rbegin_rend<std::list>()); // rbegin() and rend()
	std::cout << "empty :\t\t";
	test(list::empty<ft::list>(), list::empty<std::list>()); // empty()
	std::cout << "size :\t\t";
	test(list::size<ft::list>(), list::size<std::list>()); // size()
	std::cout << "max_size :\t";
	test(list::max_size<ft::list>(), list::max_size<std::list>()); // max_size()
	std::cout << "front :\t\t";
	test(list::front<ft::list>(), list::front<std::list>()); // front()
	std::cout << "back :\t\t";
	test(list::back<ft::list>(), list::back<std::list>()); // back()
	std::cout << "assign :\t";
	test(list::assign<ft::list>(), list::assign<std::list>()); // assign()
	std::cout << "push&pop front :";
	test(list::push_pop_front<ft::list>(), list::push_pop_front<std::list>()); // push_front and pop_front()
	std::cout << "push&pop back :\t";
	test(list::push_pop_back<ft::list>(), list::push_pop_back<std::list>()); // push_back and pop_back()
	std::cout << "insert :\t";
	test(list::insert<ft::list>(), list::insert<std::list>()); // insert()
	std::cout << "erase :\t\t";
	test(list::erase<ft::list>(), list::erase<std::list>()); // erase()
	std::cout << "swap :\t\t";
	test(list::swap<ft::list>(), list::swap<std::list>()); // swap()
	std::cout << "resize :\t";
	test(list::resize<ft::list>(), list::resize<std::list>()); // resize()
	std::cout << "clear :\t\t";
	test(list::clear<ft::list>(), list::clear<std::list>()); // clear()
	std::cout << "splice :\t";
	test(list::splice<ft::list>(), list::splice<std::list>()); // splice()
	std::cout << "remove :\t";
	test(list::remove<ft::list>(), list::remove<std::list>()); // remove()
	std::cout << "remove_if :\t";
	test(list::remove_if<ft::list>(), list::remove_if<std::list>()); // remove_if()
	std::cout << "unique :\t";
	test(list::unique<ft::list>(), list::unique<std::list>()); // unique()
	std::cout << "merge :\t\t";
	test(list::merge<ft::list>(), list::merge<std::list>()); // merge()
	std::cout << "sort :\t\t";
	test(list::sort<ft::list>(), list::sort<std::list>()); // sort()
	std::cout << "reverse :\t";
	test(list::reverse<ft::list>(), list::reverse<std::list>()); // reverse()
	std::cout << "operators :\t";
	test(list::operators<ft::list>(), list::operators<std::list>()); // operator=()
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
