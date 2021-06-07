/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 00:16:07 by user42            #+#    #+#             */
/*   Updated: 2021/06/07 21:20:17 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "stack.hpp"

int main()
{
	std::deque<int> mydeque(3, 100);   // deque with 3 elements
	std::vector<int> myvector(2, 200); // vector with 2 elements

	ft::stack<int> first;			// empty stack
	ft::stack<int> second(mydeque); // stack initialized to copy of deque

	ft::stack<int, std::vector<int>> third; // empty stack using vector
	ft::stack<int, std::vector<int>> fourth(myvector);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';

	std::cout << std::boolalpha << first.empty() << '\n';
	std::cout << std::boolalpha << second.empty() << '\n';
	std::cout << std::boolalpha << third.empty() << '\n';
	std::cout << std::boolalpha << fourth.empty() << '\n';
}
