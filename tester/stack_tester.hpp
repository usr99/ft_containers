/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tester.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:58:33 by mamartin          #+#    #+#             */
/*   Updated: 2021/06/28 23:03:43 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TESTER_HPP
# define STACK_TESTER_HPP

# include <iostream>
# include <sstream>
# include <stack>
# include <vector>
# include "../containers/stack/stack.hpp"

namespace stack
{
	template <template<class U, class = std::deque<U> > class T>
	std::string constructor()
	{
		std::deque<int>				mydeque(3, 100);
		std::vector<int>			myvector(2, 200);
		std::stringstream			ss;

		// construct from default container (deque)
		T<int>						first;
		T<int>						second(mydeque);
		// construct from vector
		T<int, std::vector<int> >	third;
		T<int, std::vector<int> >	fourth(myvector);

		// put stacks sizes in string stream
		ss << first.size() << std::endl;
		ss << second.size() << std::endl;
		ss << third.size() << std::endl;
		ss << fourth.size() << std::endl;

		return (ss.str()); // return output
	}

	template <template <class U, class = std::deque<U> > class T>
	std::string empty()
	{
		std::stringstream	ss;
		T<int>				stack;
		int					sum = 0;

		for (int i = 1; i <= 10; i++)
			stack.push(i); // push integers into queue
		while (!stack.empty()) // calculate sum
		{
			sum += stack.top(); // add first element in queue
			stack.pop(); // pop it
		}
		ss << sum; // put sum in string stream
		return (ss.str());
	}

	template <template <class U, class = std::deque<U> > class T>
	std::string size()
	{
		std::stringstream	ss;
		T<int>				stack;

		ss << stack.size(); // get size
		for (int i = 0; i < 5; i++)
			stack.push(i); // push 5 elements
		ss << stack.size();
		stack.pop(); // pop first element
		ss << stack.size();
		return (ss.str());
	}

	template <template <class U, class = std::deque<U> > class T>
	std::string top()
	{
		std::stringstream	ss;
		T<int>				stack;

		// push values
		stack.push(10);
		stack.push(20); // now on top
		stack.top() -= 5; // 20 - 5 = 15
		ss << stack.top(); // put top element (15)
		return (ss.str());
	}

	template <template <class U, class = std::deque<U> > class T>
	std::string push_pop()
	{
		std::stringstream	ss;
		T<int>				stack;

		for (int i = 0; i < 5; ++i)
			stack.push(i); // push 5 integers
		while (!stack.empty()) // write stack in string stream
		{
			ss << ' ' << stack.top(); // write top element
			stack.pop(); // pop it
		}
		return (ss.str());
	}

	template <template <class U, class = std::deque<U> > class T>
	std::string operators()
	{
		std::stringstream							ss;
		T<std::string, std::vector<std::string> >	stack1;
		T<std::string, std::vector<std::string> >	stack2;

		// push same string in both queues
		for (int i = 0 ; i < 10 ; i++)
		{
			stack1.push("string1");
			stack2.push("string1");
		}
		// add different string to second queue
		stack2.push("string2");

		ss << (stack1 == stack2);	// false
		ss << (stack1 != stack2);	// true
		ss << (stack1 < stack2);	// true
		ss << (stack1 <= stack2);	// true
		ss << (stack1 > stack2);	// false
		ss << (stack1 >= stack2);	// false

		return (ss.str());
	}
}

#endif
