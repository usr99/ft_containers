/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 00:16:07 by user42            #+#    #+#             */
/*   Updated: 2021/06/07 22:06:56 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "queue.hpp"

int main()
{
	std::deque<int> mydeque(3, 100);   // deque with 3 elements
	std::vector<int> myvector(2, 200); // vector with 2 elements

	ft::queue<int> first;			// empty queue
	ft::queue<int> second(mydeque); // queue initialized to copy of deque

	ft::queue<int, std::vector<int>> third; // empty queue using vector
	ft::queue<int, std::vector<int>> fourth(myvector);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';

	std::cout << std::boolalpha << first.empty() << '\n';
	std::cout << std::boolalpha << second.empty() << '\n';
	std::cout << std::boolalpha << third.empty() << '\n';
	std::cout << std::boolalpha << fourth.empty() << '\n';
}
