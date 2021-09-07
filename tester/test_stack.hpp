/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:38:32 by mamartin          #+#    #+#             */
/*   Updated: 2021/09/02 19:09:05 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <vector>

#include "../containers/stack/stack.hpp"
#include "utils.hpp"

#if CONTAINER == ft
# define UNDER_CNTR ft::vector
#elif
# define UNDER_CNTR std::deque
#endif

namespace stack
{
	template <template <class U, class container = UNDER_CNTR<U> > class T>
	void	constructor(std::ofstream& output, std::ofstream& time)
	{
		struct timeval	tv;

		UNDER_CNTR<int>			default_cntr((size_t)52, 100);
		std::vector<int>		myvector(25, 200);

		output << "$ default constructor" << std::endl;
		time << "$ default constructor" << std::endl;

		// empty stack (default container)
		gettimeofday(&tv, NULL);
		T<int> first;
		print_exec_tm(time, tv);

		// stack initialized to copy of default container
		gettimeofday(&tv, NULL);
		T<int> second(default_cntr);	
		print_exec_tm(time, tv);

		// empty stack using vector (STL one)
		gettimeofday(&tv, NULL);
		T<int, std::vector<int> > third;
		print_exec_tm(time, tv);

		// stack initialized to copy of vector
		gettimeofday(&tv, NULL);
		T<int, std::vector<int> > fourth(myvector);
		print_exec_tm(time, tv);

		output << "size of first: " << first.size() << std::endl;
		while (!first.empty())
		{
			output << first.top() << " ";
			first.pop();
		}

		output << "size of second: " << second.size() << std::endl;
		while (!second.empty())
		{
			output << second.top() << " ";
			second.pop();
		}
		output << std::endl;

		output << "size of third: " << third.size() << std::endl;
		while (!third.empty())
		{
			output << third.top() << " ";
			third.pop();
		}

		output << "size of first: " << fourth.size() << std::endl;
		while (!fourth.empty())
		{
			output << fourth.top() << " ";
			fourth.pop();
		}
		output << std::endl;		
	}

	template <template <class U, class container = UNDER_CNTR<U> > class T>
	void	empty(std::ofstream& output, std::ofstream& time)
	{
		struct timeval				tv;
		bool						ret;
		int							tab[25] = {0};
		std::vector<int>			myvector(tab, tab + 25);
		T<int, std::vector<int> >	stack(myvector);
		T<char>						empty;

		output << std::endl << "$ empty()" << std::endl;
		time << std::endl << "$ empty()" << std::endl;

		while (stack.size())
		{
			gettimeofday(&tv, NULL);
			ret = stack.empty();
			print_exec_tm(time, tv);

			output << std::boolalpha << ret << " ";
			stack.pop();
		}

		gettimeofday(&tv, NULL);
		ret = stack.empty();
		print_exec_tm(time, tv);

		while (!ret)
		{
			gettimeofday(&tv, NULL);
			ret = stack.empty();
			print_exec_tm(time, tv);
			output << std::boolalpha << ret << " ";
			stack.pop();
		}
		output << std::endl;
	}

	template <template <class U, class container = UNDER_CNTR<U> > class T>
	void	size(std::ofstream& output, std::ofstream& time)
	{
		struct timeval				tv;
		size_t						size;

		std::string					tab[] = {"hey", "salut", "stack de string", "!!!"};
		ft::vector<std::string>		myvector(tab, tab + 4);
		T<std::string>				stack(myvector);
		
		ft::vector<long>			empty_vect;
		T<long>						empty_stack(empty_vect);

		output << std::endl << "$ size()" << std::endl;
		time << std::endl << "$ size()" << std::endl;

		gettimeofday(&tv, NULL);
		size = stack.size();
		print_exec_tm(time, tv);
		output << size << " ";

		stack.push("coucou");
		stack.push("nouvelle chaine");

		gettimeofday(&tv, NULL);
		size = stack.size();
		print_exec_tm(time, tv);
		output << size << " ";

		while (!stack.empty())
		{
			gettimeofday(&tv, NULL);
			size = stack.size();
			print_exec_tm(time, tv);
			output << size << " ";
			stack.pop();
		}

		gettimeofday(&tv, NULL);
		size = empty_stack.size();
		print_exec_tm(time, tv);
		output << size << std::endl;
	}

	template <template <class U, class container = UNDER_CNTR<U> > class T>
	void	top(std::ofstream& output, std::ofstream& time)
	{
		struct timeval			tv;
		ft::vector<std::string>	container(3, "str");
		T<std::string>			stack(container);
		std::string				tmp;
		
		output << std::endl << "$ top()" << std::endl;
		time << std::endl << "$ top()" << std::endl;

		gettimeofday(&tv, NULL);
		tmp = stack.top(); // str
		print_exec_tm(time, tv);
		output << tmp << std::endl;

		stack.push("coucou");

		gettimeofday(&tv, NULL);
		tmp = stack.top(); // coucou
		print_exec_tm(time, tv);
		output << tmp << std::endl;

		stack.push("héhé");
		stack.push("supprimable");
		stack.pop();

		gettimeofday(&tv, NULL);
		tmp = stack.top(); // héhé
		print_exec_tm(time, tv);
		output << tmp << std::endl;
	}

	template <template <class U, class container = UNDER_CNTR<U> > class T>
	void	push(std::ofstream& output, std::ofstream& time)
	{
		struct timeval	tv;
		T<long>			stack;

		output << std::endl << "$ push()" << std::endl;
		time << std::endl << "$ push()" << std::endl;

		output << stack.size() << std::endl;
		gettimeofday(&tv, NULL);
		stack.push(-48184545452757);
		print_exec_tm(time, tv);
		output << stack.top() << std::endl;
		output << stack.size() << std::endl;

		gettimeofday(&tv, NULL);
		stack.push(9878713132);
		print_exec_tm(time, tv);
		output << stack.top() << std::endl;
		output << stack.size() << std::endl;

		gettimeofday(&tv, NULL);
		stack.push(12341586);
		print_exec_tm(time, tv);
		output << stack.top() << std::endl;
		output << stack.size() << std::endl;
	}

	template <template <class U, class container = UNDER_CNTR<U> > class T>
	void	pop(std::ofstream& output, std::ofstream& time)
	{
		struct timeval		tv;
		long				tab[] = {-48184545452757, 9878713132, 12341586};
		UNDER_CNTR<long>	cntr(tab, tab + 3);
		T<long>				stack(cntr);

		output << std::endl << "$ pop()" << std::endl;
		time << std::endl << "$ pop()" << std::endl;

		output << stack.size() << std::endl;
		output << stack.top() << std::endl;
		gettimeofday(&tv, NULL);
		stack.pop();
		print_exec_tm(time, tv);
		output << stack.top() << std::endl;
		output << stack.size() << std::endl;

		gettimeofday(&tv, NULL);
		stack.pop();
		print_exec_tm(time, tv);
		output << stack.top() << std::endl;
		output << stack.size() << std::endl;

		gettimeofday(&tv, NULL);
		stack.pop();
		print_exec_tm(time, tv);
		output << stack.size() << std::endl;
	}

	template <template <class U, class container = UNDER_CNTR<U> > class T>
	void	operators(std::ofstream& output, std::ofstream& time)
	{
		struct timeval		tv;
		bool				ret[3][6];

		output << std::endl << "$ operators" << std::endl;
		time << std::endl << "$ operators" << std::endl;
		output << std::boolalpha;
		
		// empty stacks tests
		T<long>	empty1;
		T<long>	empty2;
		
		gettimeofday(&tv, NULL);
		ret[0][0] = (empty1 == empty2);	// operator==
		print_exec_tm(time, tv);
		gettimeofday(&tv, NULL);	
		ret[0][1] = (empty1 != empty2);	// operator!=
		print_exec_tm(time, tv);
		gettimeofday(&tv, NULL);	
		ret[0][2] = (empty1 < empty2);	// operator<
		print_exec_tm(time, tv);
		gettimeofday(&tv, NULL);	
		ret[0][3] = (empty1 <= empty2);	// operator<=
		print_exec_tm(time, tv);
		gettimeofday(&tv, NULL);	
		ret[0][4] = (empty1 > empty2);	// operator>
		print_exec_tm(time, tv);
		gettimeofday(&tv, NULL);	
		ret[0][5] = (empty1 >= empty2);	// operator>=
		print_exec_tm(time, tv);


		// equal elements but sizes differs
		std::string				str[] = {"salut", "je", "suis", "le", "tableau", "!"};
		ft::vector<std::string>	vec(str, str + 6);
		T<std::string>			first(vec);
		T<std::string>			second(vec);
		first.pop() ; first.pop();

		gettimeofday(&tv, NULL);
		ret[1][0] = (first == second);	// operator==
		print_exec_tm(time, tv);
		gettimeofday(&tv, NULL);	
		ret[1][1] = (first != second);	// operator!=
		print_exec_tm(time, tv);
		gettimeofday(&tv, NULL);	
		ret[1][2] = (first < second);	// operator<
		print_exec_tm(time, tv);
		gettimeofday(&tv, NULL);	
		ret[1][3] = (first <= second);	// operator<=
		print_exec_tm(time, tv);
		gettimeofday(&tv, NULL);	
		ret[1][4] = (first > second);	// operator>
		print_exec_tm(time, tv);
		gettimeofday(&tv, NULL);	
		ret[1][5] = (first >= second);	// operator>=
		print_exec_tm(time, tv);		

		// totally different stacks
		std::string				str2[] = {"salut", "je", "suis", "le", "nouveau", "tableau", "!"};
		ft::vector<std::string>	vec2(str2, str2 + 7);
		T<std::string>			third(vec);
		T<std::string>			fourth(vec2);
		
		gettimeofday(&tv, NULL);
		ret[2][0] = (third == fourth);	// operator==
		print_exec_tm(time, tv);
		gettimeofday(&tv, NULL);	
		ret[2][1] = (third != fourth);	// operator!=
		print_exec_tm(time, tv);
		gettimeofday(&tv, NULL);	
		ret[2][2] = (third < fourth);	// operator<
		print_exec_tm(time, tv);
		gettimeofday(&tv, NULL);	
		ret[2][3] = (third <= fourth);	// operator<=
		print_exec_tm(time, tv);
		gettimeofday(&tv, NULL);	
		ret[2][4] = (third > fourth);	// operator>
		print_exec_tm(time, tv);
		gettimeofday(&tv, NULL);	
		ret[2][5] = (third >= fourth);	// operator>=
		print_exec_tm(time, tv);

		for (int i = 0 ; i < 3 ; i++)
		{
			for (int j = 0 ; j < 6 ; j++)
				output << ret[i][j] << " ";
			output << std::endl;
		}
	}

	template <template <class U, class container = UNDER_CNTR<U> > class T>
	void	test(std::ofstream& output, std::ofstream& time)
	{
		output << "$$$ STACK" << std::endl;
		time << "$$$ STACK" << std::endl;
		constructor<T>(output, time);
		empty<T>(output, time);
		size<T>(output, time);
		top<T>(output, time);
		push<T>(output, time);
		pop<T>(output, time);
		operators<T>(output, time);
	}
}
