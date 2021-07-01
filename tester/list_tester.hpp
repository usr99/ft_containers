/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tester.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 00:53:00 by mamartin          #+#    #+#             */
/*   Updated: 2021/06/28 23:37:08 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_TESTER_HPP
# define LIST_TESTER_HPP

# include <iostream>
# include <cmath>
# include <sstream>
# include <vector>

namespace list
{
	template <template <class U, class = std::allocator<U> > class T>
	std::string	constructor()
	{
		std::stringstream	ss;

		T<int>				first;                               // empty list of ints
  		T<int>				second((size_t)4,100);               // four ints with value 100
  		T<int>				third(second.begin(),second.end());  // iterating through second
  		T<int>				fourth(third);                       // a copy of third

  		// the iterator constructor can also be used to construct from arrays:
  		int					myints[] = {16,2,77,29};
  		T<int>				fifth(myints, myints + sizeof(myints) / sizeof(int));

  		for (typename T<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
  			ss << *it << ' ';

  		return (ss.str());
	}

	template <template <class U, class = std::allocator<U> > class T>
	std::string	begin_end()
	{
		std::stringstream	ss;

 		int					myints[] = {75,23,65,42,13};
 		T<int>				mylist(myints,myints+5);
		 
 		for (typename T<int>::iterator it = mylist.begin() ; it != mylist.end() ; ++it)
 			ss << ' ' << *it;
			 
  		return (ss.str());
	}

	template <template <class U, class = std::allocator<U> > class T>
	std::string	rbegin_rend()
	{
		std::stringstream	ss;
		T<int> 				mylist;
		
		for (int i = 1; i <= 5; ++i)
			mylist.push_back(i);

		for (typename T<int>::reverse_iterator rit = mylist.rbegin(); rit != mylist.rend(); ++rit)
			ss << ' ' << *rit;
			 
  		return (ss.str());
	}

	template <template <class U, class = std::allocator<U> > class T>
	std::string	empty()
	{
		std::stringstream	ss;
		T<int>				mylist;
		int					sum(0);

		for (int i = 1; i <= 10; ++i)
			mylist.push_back(i);

		while (!mylist.empty())
		{
			sum += mylist.front();
			mylist.pop_front();
		}
		ss << sum;
			 
  		return (ss.str());
	}

	template <template <class U, class = std::allocator<U> > class T>
	std::string	size()
	{
		std::stringstream	ss;
		T<int>				myints;
		
		ss << myints.size();

		for (int i = 0; i < 10; i++)
			myints.push_back(i);
		ss << myints.size();

		myints.insert(myints.begin(), (size_t)10, 100);
		ss << myints.size();

		myints.pop_back();
		ss << myints.size();
  		
		return (ss.str());
	}

	template <template <class U, class = std::allocator<U> > class T>
	std::string	max_size()
	{
		std::stringstream	ss;
		T<int>				mylist;

		ss << mylist.max_size();

		return (ss.str());
	}

	template <template <class U, class = std::allocator<U> > class T>
	std::string	front()
	{
		std::stringstream	ss;
		T<int>				mylist;

		mylist.push_back(77);
		mylist.push_back(22);
		mylist.front() -= mylist.back();

		ss << mylist.front();

		return (ss.str());
	}

	template <template <class U, class = std::allocator<U> > class T>
	std::string	back()
	{
		std::stringstream	ss;
		T<int>				mylist;

		mylist.push_back(10);
		while (mylist.back() != 0)
			mylist.push_back(mylist.back() - 1);

		for (typename T<int>::iterator it = mylist.begin() ; it != mylist.end() ; ++it)
			ss << ' ' << *it;

		return (ss.str());
	}

	template <template <class U, class = std::allocator<U> > class T>
	std::string	assign()
	{
		std::stringstream	ss;
		T<int>				first;
		T<int>				second;
		int					myints[] = {1776, 7, 4};

		first.assign((size_t)7, 100); // 7 ints with value 100
		second.assign(first.begin(), first.end()); // a copy of first
		first.assign(myints, myints + 3); // assigning from array

		ss << int(first.size());
		ss << int(second.size());

		return (ss.str());
	}

	template <template <class U, class = std::allocator<U> > class T>
	std::string	push_pop_front()
	{
		std::stringstream	ss;
		T<int>				mylist((size_t)2, 100); // two ints with a value of 100
		
		mylist.push_front(200);
		mylist.push_front(300);

		while (!mylist.empty())
		{
			ss << ' ' << mylist.front();
			mylist.pop_front();
		}

		return (ss.str());
	}

	template <template <class U, class = std::allocator<U> > class T>
	std::string	push_pop_back()
	{
		std::stringstream	ss;
		T<int>				mylist;

		mylist.push_back(100);
		mylist.push_back(200);
		mylist.push_back(300);

		while (!mylist.empty())
		{
			ss << ' ' << mylist.front();
			mylist.pop_back();
		}
		ss << mylist.size();

		return (ss.str());
	}

	template <template <class U, class = std::allocator<U> > class T>
	std::string	insert()
	{
		std::stringstream			ss;
		T<int>						mylist;
		typename T<int>::iterator	it;

		// set some initial values:
		for (int i = 1; i <= 5; ++i)
			mylist.push_back(i); // 1 2 3 4 5

		it = mylist.begin();
		++it; // it points now to number 2           ^

		mylist.insert(it, 10); // 1 10 2 3 4 5

		// "it" still points to number 2                      ^
		mylist.insert(it, (size_t)2, 20); // 1 10 20 20 2 3 4 5

		--it; // it points now to the second 20            ^

		std::vector<int>	myvector(2, 30);
		mylist.insert(it, myvector.begin(), myvector.end());
		// 1 10 20 30 30 20 2 3 4 5
		//               ^
		for (it = mylist.begin() ; it != mylist.end() ; ++it)
			ss << ' ' << *it;

		return (ss.str());
	}

	template <template <class U, class = std::allocator<U> > class T>
	std::string	erase()
	{
		std::stringstream			ss;
		T<int>						mylist;
		typename T<int>::iterator	it1, it2;

		// set some values:
		for (int i = 1; i < 10; ++i)
			mylist.push_back(i * 10);

		// 10 20 30 40 50 60 70 80 90
		it1 = it2 = mylist.begin(); // ^^
		for (int i = 0 ; i < 6 ; i++)
			++it2;
		++it1;						//    ^              ^

		it1 = mylist.erase(it1); // 10 30 40 50 60 70 80 90
								 //    ^           ^

		it2 = mylist.erase(it2); // 10 30 40 50 60 80 90
								 //    ^           ^

		++it1; //       ^        ^
		--it2; //       ^     ^

		mylist.erase(it1, it2); // 10 30 60 80 90
								//        ^

		for (it1 = mylist.begin(); it1 != mylist.end(); ++it1)
			ss << ' ' << *it1;

		return (ss.str());
	}

	template <template <class U, class = std::allocator<U> > class T>
	std::string	swap()
	{
		std::stringstream	ss;
		T<int>				first((size_t)3, 100);  // three ints with a value of 100
		T<int>				second((size_t)5, 200); // five ints with a value of 200

		first.swap(second);

		for (typename T<int>::iterator it = first.begin(); it != first.end(); it++)
			ss << ' ' << *it;
		ss << " | ";
		for (typename T<int>::iterator it = second.begin(); it != second.end(); it++)
			ss << ' ' << *it;

		return (ss.str());
	}

	template <template <class U, class = std::allocator<U> > class T>
	std::string	resize()
	{
		std::stringstream	ss;
		T<int>				mylist;

		// set some initial content:
		for (int i = 1; i < 10; ++i)
			mylist.push_back(i);

		mylist.resize(5);
		mylist.resize(8, 100);
		mylist.resize(12);

		for (typename T<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
			ss << ' ' << *it;

		return (ss.str());
	}

	template <template <class U, class = std::allocator<U> > class T>
	std::string	clear()
	{
		std::stringstream			ss;
		T<int>						mylist;
		typename T<int>::iterator	it;

		mylist.push_back(100);
		mylist.push_back(200);
		mylist.push_back(300);

		for (it = mylist.begin(); it != mylist.end(); ++it)
			ss << ' ' << *it;

		mylist.clear();
		mylist.push_back(1101);
		mylist.push_back(2202);

		for (it = mylist.begin(); it != mylist.end(); ++it)
			ss << ' ' << *it;

		return (ss.str());
	}

	template <template <class U, class = std::allocator<U> > class T>
	std::string	splice()
	{
		std::stringstream			ss;
		T<int>						mylist1, mylist2;
		typename T<int>::iterator	it;

		// set some initial values:
		for (int i = 1; i <= 4; ++i)
			mylist1.push_back(i); // mylist1: 1 2 3 4

		for (int i = 1; i <= 3; ++i)
			mylist2.push_back(i * 10); // mylist2: 10 20 30

		it = mylist1.begin();
		++it; // points to 2

		mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
									 // mylist2 (empty)
									 // "it" still points to 2 (the 5th element)

		mylist2.splice(mylist2.begin(), mylist1, it);
		// mylist1: 1 10 20 30 3 4
		// mylist2: 2
		// "it" is now invalid.
		it = mylist1.begin();
		for (int i = 0 ; i < 3 ; i++)
			it++; // "it" points now to 30

		mylist1.splice(mylist1.begin(), mylist1, it, mylist1.end());
		// mylist1: 30 3 4 1 10 20

		for (it = mylist1.begin(); it != mylist1.end(); ++it)
			ss << ' ' << *it;
		ss << '\n';

		for (it = mylist2.begin(); it != mylist2.end(); ++it)
			ss << ' ' << *it;
		ss << '\n';

		return (ss.str());
	}

	template <template <class U, class = std::allocator<U> > class T>
	std::string	remove()
	{
		std::stringstream	ss;
		int					myints[] = {17, 89, 7, 14};
		T<int>				mylist(myints, myints + 4);

		mylist.remove(89);

		for (typename T<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
			ss << ' ' << *it;
		ss << '\n';

		return (ss.str());
	}

	// a predicate implemented as a function:
	bool single_digit (const int& value) { return (value<10); }
	
	// a predicate implemented as a class:
	struct is_odd
	{
		bool operator() (const int& value) { return (value%2)==1; }
	};

	template <template <class U, class = std::allocator<U> > class T>
	std::string	remove_if()
	{
		std::stringstream	ss;
		int					myints[] = {15, 36, 7, 17, 20, 39, 4, 1};
		T<int>				mylist(myints, myints + 8); // 15 36 7 17 20 39 4 1

		mylist.remove_if(single_digit); // 15 36 17 20 39
		mylist.remove_if(is_odd()); // 36 20

		for (typename T<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
			ss << ' ' << *it;
		ss << '\n';

		return (ss.str());
	}

	// a binary predicate implemented as a function:
	bool same_integral_part (double first, double second) { return ( int(first)==int(second) ); }

	// a binary predicate implemented as a class:
	struct is_near
	{
		bool operator() (double first, double second) { return (std::fabs(first-second)<5.0); }
	};

	template <template <class U, class = std::allocator<U> > class T>
	std::string	unique()
	{
		std::stringstream	ss;
		double				mydoubles[] = {12.15, 2.72, 73.0, 12.77, 3.14,
							  12.77, 73.35, 72.25, 15.3, 72.25};
		T<double>			mylist(mydoubles, mydoubles + 10);

		mylist.sort(); //  2.72,  3.14, 12.15, 12.77, 12.77,
					   // 15.3,  72.25, 72.25, 73.0,  73.35

		mylist.unique(); //  2.72,  3.14, 12.15, 12.77
						 // 15.3,  72.25, 73.0,  73.35

		mylist.unique(same_integral_part); //  2.72,  3.14, 12.15
										   // 15.3,  72.25, 73.0

		mylist.unique(is_near()); //  2.72, 12.15, 72.25

		for (typename T<double>::iterator it = mylist.begin(); it != mylist.end(); ++it)
			ss << ' ' << *it;
		ss << '\n';

		return (ss.str());
	}

	// compare only integral part:
	bool mycomparison (double first, double second) { return(int(first) < int(second)); }

	template <template <class U, class = std::allocator<U> > class T>
	std::string	merge()
	{
		std::stringstream	ss;
		T<double>			first, second;

		first.push_back(3.1);
		first.push_back(2.2);
		first.push_back(2.9);

		second.push_back(3.7);
		second.push_back(7.1);
		second.push_back(1.4);

		first.sort();
		second.sort();
		first.merge(second);

		// (second is now empty)

		second.push_back(2.1);
		//first.merge(second, mycomparison);

		for (typename T<double>::iterator it = first.begin(); it != first.end(); ++it)
			ss << ' ' << *it;
		ss << '\n';

		return (ss.str());
	}

	// comparison, not case sensitive.
	bool compare_nocase(const std::string &first, const std::string &second)
	{
		unsigned int i = 0;
		while ((i < first.length()) && (i < second.length()))
		{
			if (tolower(first[i]) < tolower(second[i]))
				return true;
			else if (tolower(first[i]) > tolower(second[i]))
				return false;
			++i;
		}
		return (first.length() < second.length());
	}

	template <template <class U, class = std::allocator<U> > class T>
	std::string	sort()
	{
		std::stringstream					ss;
		T<std::string>						mylist;
		typename T<std::string>::iterator	it;

		mylist.push_back("one");
		mylist.push_back("two");
		mylist.push_back("Three");

		mylist.sort();

		for (it = mylist.begin(); it != mylist.end(); ++it)
			ss << ' ' << *it;
		ss << '\n';

		mylist.sort(compare_nocase);

		for (it = mylist.begin(); it != mylist.end(); ++it)
			ss << ' ' << *it;
		ss << '\n';

		return (ss.str());
	}

	template <template <class U, class = std::allocator<U> > class T>
	std::string	reverse()
	{
		std::stringstream	ss;
		T<int>				mylist;

		for (int i = 1; i < 10; ++i)
			mylist.push_back(i);
		mylist.reverse();

		for (typename T<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
			ss << ' ' << *it;
		ss << '\n';

		return (ss.str());
	}

	template <template <class U, class = std::allocator<U> > class T>
	std::string	operators()
	{
		std::stringstream	ss;

		T<int> first(3);  // list of 3 zero-initialized ints
		T<int> second(5); // list of 5 zero-initialized ints

		second = first;
		first = T<int>();

		ss << "Size of first: " << int(first.size()) << '\n';
		ss << "Size of second: " << int(second.size()) << '\n';
		
		int		tab[] = {10, 20, 30};
		T<int>	a(tab, tab + 3); // 10 20 30
		T<int>	b(a); // 10 20 30
		T<int>	c(a);

		c.reverse(); // 30 20 10

		if (a == b)
			ss << "a and b are equal\n";
		if (b != c)
			ss << "b and c are not equal\n";
		if (b < c)
			ss << "b is less than c\n";
		if (c > b)
			ss << "c is greater than b\n";
		if (a <= b)
			ss << "a is less than or equal to b\n";
		if (a >= b)
			ss << "a is greater than or equal to b\n";
			
		return (ss.str());
	}
}

#endif
