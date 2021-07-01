/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_tester.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:58:33 by mamartin          #+#    #+#             */
/*   Updated: 2021/06/28 23:03:42 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_TESTER_HPP
# define QUEUE_TESTER_HPP

# include <iostream>
# include <sstream>
# include <queue>
# include <list>
# include "../containers/queue/queue.hpp"

namespace queue
{
	template <template<class U, class = std::deque<U> > class T>
	std::string constructor()
	{
		std::stringstream		ss;
		std::deque<int>			mydeck(3, 100);
		std::list<int>			mylist(2, 200);
		
		// construct from default container (deque)
		T<int>					first;
		T<int>					second(mydeck);
		// construct from list
		T<int, std::list<int> >	third; 
		T<int, std::list<int> >	fourth(mylist);

		// put stacks sizes in string stream
		ss << first.size();
		ss << second.size();
		ss << third.size();
		ss << fourth.size();

		return (ss.str()); // return output
	}

	template <template <class U, class = std::deque<U> > class T>
	std::string empty()
	{
		std::stringstream	ss;
		T<int> 				myqueue;
		int					sum = 0;

		for (int i = 1; i <= 10; i++)
			myqueue.push(i); // push integers into queue
		while (!myqueue.empty()) // calculate sum
		{
			sum += myqueue.front(); // add first element in queue
			myqueue.pop(); // pop it
		}
		ss << sum; // put sum in string stream
		return (ss.str());
	}

	template <template <class U, class = std::deque<U> > class T>
	std::string size()
	{
		std::stringstream	ss;
		T<int>				queue;

		ss << queue.size(); // get size
		for (int i = 0; i < 5; i++)
			queue.push(i); // push 5 elements
		ss << queue.size();
		queue.pop(); // pop first element
		ss << queue.size();
		return (ss.str());
	}

	template <template <class U, class = std::deque<U> > class T>
	std::string front()
	{
		std::stringstream	ss;
		T<int>				myqueue;

		// push values
		myqueue.push(77);
		myqueue.push(16); // this is now the back
		myqueue.front() -= myqueue.back(); // 77 - 16 = 61
		ss << myqueue.front(); // put front element (61)
		return (ss.str());
	}

	template <template <class U, class = std::deque<U> > class T>
	std::string back()
	{
		std::stringstream	ss;
		T<int>				myqueue;

		// push values
		myqueue.push(12);
		myqueue.push(75); // this is now the back
		myqueue.back() -= myqueue.front(); // 75 - 12 = 63
		ss << myqueue.back(); // put back element (63)
		return (ss.str());
	}

	template <template <class U, class = std::deque<U> > class T>
	std::string push_pop()
	{
		std::stringstream	ss;
		T<int>				myqueue;

		for (int i = 0 ; i < 10 ; i++)
			myqueue.push(i); // push 10 integers
		while (!myqueue.empty()) // write queue in string stream
		{
			ss << ' ' << myqueue.front(); // write front element
			myqueue.pop(); // pop it
		}
		return (ss.str());
	}

	template <template <class U, class = std::deque<U> > class T>
	std::string operators()
	{
		std::stringstream							ss;
		T<std::string, std::vector<std::string> >	queue1;
		T<std::string, std::vector<std::string> >	queue2;

		// push same string in both queues
		for (int i = 0 ; i < 10 ; i++)
		{
			queue1.push("string1");
			queue2.push("string1");
		}
		// add different string to second queue
		queue2.push("string2");

		ss << (queue1 == queue2);	// false
		ss << (queue1 != queue2);	// true
		ss << (queue1 < queue2);	// true
		ss << (queue1 <= queue2);	// true
		ss << (queue1 > queue2);	// false
		ss << (queue1 >= queue2);	// false

		return (ss.str());
	}
}

#endif
