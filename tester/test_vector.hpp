/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 02:06:14 by mamartin          #+#    #+#             */
/*   Updated: 2021/09/03 02:00:43 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../containers/vector/vector.hpp"
#include "utils.hpp"

namespace vector
{
	struct test
	{
		test() :
			x(0), y(0) {}
		test(int x, int y) :
			x(x), y(y) {}

		bool	operator==(const struct test& rhs) const
		{
			return ((x == rhs.x) && (y == rhs.y));
		}

		int	x;
		int	y;
	};

	std::ostream&	operator<<(std::ostream& os, const struct test& val)
	{
		os << val.x << "/" << val.y;
		return (os);
	}

	std::string		str[5] = {"salut", "coucou", "bonjour", "hey", "yo"};
	struct test		val(1528, 8496);

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	constructors(std::ofstream& output, std::ofstream& time)
	{
		output << "$ constructors" << std::endl;
		time << "$ constructors" << std::endl;

		struct timeval	tv;

		gettimeofday(&tv, NULL);

		T<int>			v1;
		T<struct test>	v2(814, val);
		T<std::string>	v3(str, str + 5);
		T<struct test>	v4(v2);

		print_exec_tm(time, tv);	

		output << v1.size() << " " << v2.size() << " " << v3.size() << " " << v4.size() << std::endl;
		
		typename T<std::string>::iterator it3 = v3.begin();
		typename T<struct test>::iterator it4 = v4.begin();

		while (it3 != v3.end())
		{
			output << *it3 << " ";
			it3++;
		}
		output << std::endl;

		while (it4 != v4.end())
		{
			output << it4->x << " " << it4->y << " ";
			it4++;
		}
		output << std::endl;
	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	begin_end(std::ofstream& output, std::ofstream& time)
	{
		output << "$ begin & end (& reverse)" << std::endl;
		time << "$ begin & end (& reverse)" << std::endl;

		struct timeval	tv;

		T<struct test>	v1;
		T<struct test>	v2(154, val);
		T<std::string>	v3(str, str + 5);

		gettimeofday(&tv, NULL);

		output << std::boolalpha;
		output << (v1.begin() == v1.end()) << std::endl;
		output << (v1.rbegin() == v1.rend()) << std::endl;

		output << (*v2.begin() == *v2.rend()) << std::endl;
		output << (*v2.end() == *v2.rbegin()) << std::endl;

		for (typename T<std::string>::reverse_iterator rit = v3.rbegin() ; rit != v3.rend() ; rit++)
			output << *rit << " ";
		output << std::endl;

		print_exec_tm(time, tv);
	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	size(std::ofstream& output, std::ofstream& time)
	{
		output << "$ size" << std::endl;
		time << "$ size" << std::endl;

		struct timeval	tv;

		T<struct test>	v1;
		T<struct test>	v2(154, val);
		T<std::string>	v3(str, str + 5);

		gettimeofday(&tv, NULL);
		output << v1.size() << " " << v2.size() << " " << v3.size() << std::endl;
		print_exec_tm(time, tv);
	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	max_size(std::ofstream& output, std::ofstream& time)
	{
		output << "$ max_size" << std::endl;
		time << "$ max_size" << std::endl;

		struct timeval	tv;

		T<struct test>	v1;
		T<struct test>	v2(154, val);
		T<std::string>	v3(str, str + 5);

		gettimeofday(&tv, NULL);
		output << v1.max_size() << " " << v2.max_size() << " " << v3.max_size() << std::endl;
		print_exec_tm(time, tv);
	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	resize(std::ofstream& output, std::ofstream& time)
	{
		output << "$ resize" << std::endl;
		time << "$ resize" << std::endl;

		struct timeval	tv;

		T<struct test>	v1;
		T<struct test>	v2(154, val);
		T<std::string>	v3(str, str + 5);

		output << v1.size() << " " << v2.size() << " " << v3.size() << std::endl;
		gettimeofday(&tv, NULL);
		v1.resize(189);
		//v2.resize(0);
		//v3.resize(1234);
		print_exec_tm(time, tv);
		output << v1.size() << " " << v2.size() << " " << v3.size() << std::endl;
	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	capacity(std::ofstream& output, std::ofstream& time)
	{
		output << "$ capacity" << std::endl;
		time << "$ capacity" << std::endl;

		struct timeval	tv;

		T<struct test>	v1;
		T<struct test>	v2(154, val);
		T<std::string>	v3(str, str + 5);

		gettimeofday(&tv, NULL);
		output << v1.capacity() << " " << v2.capacity() << " " << v3.capacity() << std::endl;
		print_exec_tm(time, tv);
	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	empty(std::ofstream& output, std::ofstream& time)
	{
		output << "$ empty" << std::endl;
		time << "$ empty" << std::endl;

		struct timeval	tv;

		T<struct test>	v1;
		T<struct test>	v2(154, val);
		T<std::string>	v3(str, str + 5);

		gettimeofday(&tv, NULL);
		output << v1.empty() << " " << v2.empty() << " " << v3.empty() << std::endl;
		print_exec_tm(time, tv);

		v1.resize(25);
		v2.resize(25);
		v3.resize(25);

		gettimeofday(&tv, NULL);
		output << v1.empty() << " " << v2.empty() << " " << v3.empty() << std::endl;
		print_exec_tm(time, tv);
	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	reserve(std::ofstream& output, std::ofstream& time)
	{
		output << "$ reserve" << std::endl;
		time << "$ reserve" << std::endl;

		struct timeval	tv;

		T<struct test>	v1;
		T<struct test>	v2(154, val);
		T<std::string>	v3(str, str + 5);

		output << v1.capacity() << " " << v2.capacity() << " " << v3.capacity() << std::endl;

		gettimeofday(&tv, NULL);
		v1.reserve(25);
		v2.reserve(200);
		v3.reserve(0);
		print_exec_tm(time, tv);

		output << v1.capacity() << " " << v2.capacity() << " " << v3.capacity() << std::endl;
	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	brackets(std::ofstream& output, std::ofstream& time)
	{
		output << "$ operator[]" << std::endl;
		time << "$ operator[]" << std::endl;

		struct timeval	tv;

		T<int>	v2(154, 52);
		T<std::string>	v3(str, str + 5);

		gettimeofday(&tv, NULL);
		for (int i = 0 ; i < 154 ; i++)
			output << v2[i] << " ";
		output << std::endl;
		for (int i = 0 ; i < 5 ; i++)
			output << v3[i] << " ";
		output << std::endl;
		print_exec_tm(time, tv);
	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	at(std::ofstream& output, std::ofstream& time)
	{
		output << "$ at" << std::endl;
		time << "$ at" << std::endl;

		struct timeval	tv;

		T<struct test>	v1;
		T<int>			v2(154, 52);
		T<std::string>	v3(str, str + 5);

		gettimeofday(&tv, NULL);
		for (int i = 0 ; i < 154 ; i++)
			output << v2.at(i) << " ";
		output << std::endl;
		for (int i = 0 ; i < 5 ; i++)
			output << v3.at(i) << " ";
		output << std::endl;
		print_exec_tm(time, tv);

		gettimeofday(&tv, NULL);
		try
		{
			v1.at(3);
			v2.at(-1);
			v3.at(5);
		}
		catch(const std::exception& e)
		{
			output << e.what() << '\n';
		}
		print_exec_tm(time, tv);

		gettimeofday(&tv, NULL);
		try
		{
			v2.at(-1);
		}
		catch(const std::exception& e)
		{
			output << e.what() << '\n';
		}
		print_exec_tm(time, tv);

		gettimeofday(&tv, NULL);
		try
		{
			v3.at(5);
		}
		catch(const std::exception& e)
		{
			output << e.what() << '\n';
		}
		print_exec_tm(time, tv);
	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	front_back(std::ofstream& output, std::ofstream& time)
	{
		output << "$ front & back" << std::endl;
		time << "$ front & back" << std::endl;

		struct timeval	tv;

		T<int>	v2(154, 18);
		T<std::string>	v3(str, str + 5);

		gettimeofday(&tv, NULL);
		output << v2.front() << " " << v3.front() << std::endl;
		output << v2.back() << " " << v3.back() << std::endl;
		print_exec_tm(time, tv);

		v2.pop_back();
		v3.pop_back();

		gettimeofday(&tv, NULL);
		output << v2.front() << " " << v3.front() << std::endl;
		output << v2.back() << " " << v3.back() << std::endl;
		print_exec_tm(time, tv);

		v2.pop_back();
		v3.pop_back();

		gettimeofday(&tv, NULL);
		output << v2.front() << " " << v3.front() << std::endl;
		output << v2.back() << " " << v3.back() << std::endl;
		print_exec_tm(time, tv);
	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	assign(std::ofstream& output, std::ofstream& time)
	{
		output << "$ assign" << std::endl;
		time << "$ assign" << std::endl;

		struct timeval	tv;

		T<struct test>	v1;
		T<struct test>	v2(154, val);
		T<std::string>	v3(str, str + 5);

		gettimeofday(&tv, NULL);
		v1.assign(v2.begin(), v2.end());
		print_exec_tm(time, tv);

		gettimeofday(&tv, NULL);
		v2.assign(v2.begin(), v2.begin());
		print_exec_tm(time, tv);

		gettimeofday(&tv, NULL);
		v3.assign(18, "cookie");
		print_exec_tm(time, tv);

		for (size_t i = 0 ; i < v1.size() ; i++)
			output << v1.at(i) << " ";
		output << std::endl;

		for (size_t i = 0 ; i < v2.size() ; i++)
			output << v2.at(i) << " ";
		output << std::endl;

		for (size_t i = 0 ; i < v3.size() ; i++)
			output << v3.at(i) << " ";
		output << std::endl;
	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	push_back(std::ofstream& output, std::ofstream& time)
	{
		output << "$ push_back" << std::endl;
		time << "$ push_back" << std::endl;

		struct timeval	tv;

		T<int>	v1;
		T<int>	v2;

		for (int i = 0 ; i < 300 ; i++)
		{
			gettimeofday(&tv, NULL);
			v1.push_back(i);
			print_exec_tm(time, tv);
			gettimeofday(&tv, NULL);
			v2.push_back(v1.at(0));
			print_exec_tm(time, tv);
		}

		for (size_t i = 0 ; i < v1.size() ; i++)
			output << v1.at(i) << " ";
		output << std::endl;

		for (size_t i = 0 ; i < v2.size() ; i++)
			output << v2.at(i) << " ";
		output << std::endl;
	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	pop_back(std::ofstream& output, std::ofstream& time)
	{
		output << "$ pop_back" << std::endl;
		time << "$ pop_back" << std::endl;

		struct timeval	tv;

		T<int>			v1(300, 28);
		T<std::string>	v2(1000, "salut");

		while (!v1.empty())
		{
			output << v1.back() << " ";
			gettimeofday(&tv, NULL);
			v1.pop_back();
			print_exec_tm(time, tv);
		}
		output << std::endl;

		while (!v2.empty())
		{
			output << v2.back() << " ";
			gettimeofday(&tv, NULL);
			v2.pop_back();
			print_exec_tm(time, tv);
		}
		output << std::endl;
	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	insert(std::ofstream& output, std::ofstream& time)
	{
		output << "$ insert" << std::endl;
		time << "$ insert" << std::endl;

		struct timeval	tv;
		struct test		tt(25,18);

		T<struct test>	v1;
		T<struct test>	v2(154, val);
		T<std::string>	v3(str, str + 5);
		
		for (int i = 0 ; i < 100 ; i++)
		{
			gettimeofday(&tv, NULL);
			v1.insert(v1.end(), v2.back());
			print_exec_tm(time, tv);
			gettimeofday(&tv, NULL);
			v2.insert(v2.begin() + 5, 5, tt);
			print_exec_tm(time, tv);
			gettimeofday(&tv, NULL);
			v3.insert(v3.end(), str, str + 5);
			print_exec_tm(time, tv);
		}

		for (size_t i = 0 ; i < v1.size() ; i++)
			output << v1.at(i) << " ";
		output << std::endl;

		for (size_t i = 0 ; i < v2.size() ; i++)
			output << v2.at(i) << " ";
		output << std::endl;

		for (size_t i = 0 ; i < v3.size() ; i++)
			output << v3.at(i) << " ";
		output << std::endl;
	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	erase(std::ofstream& output, std::ofstream& time)
	{
		output << "$ erase" << std::endl;
		time << "$ erase" << std::endl;

		struct timeval	tv;

		T<struct test>	v2(154, val);
		T<std::string>	v3(str, str + 5);
		
		for (int i = 0 ; i < 50 ; i++)
		{
			gettimeofday(&tv, NULL);
			v2.erase(v2.begin(), v2.begin() + 1);
			print_exec_tm(time, tv);
		}

		gettimeofday(&tv, NULL);
		v2.erase(v2.begin(), v2.end());
		print_exec_tm(time, tv);

		gettimeofday(&tv, NULL);
		v3.erase(v3.begin() + 2);
		print_exec_tm(time, tv);	

		for (size_t i = 0 ; i < v3.size() ; i++)
			output << v3.at(i) << " ";
		output << std::endl;

		for (size_t i = 0 ; i < v2.size() ; i++)
			output << v2.at(i) << " ";
		output << std::endl;
	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	swap(std::ofstream& output, std::ofstream& time)
	{
		output << "$ swap" << std::endl;
		time << "$ swap" << std::endl;

		struct timeval	tv;

		T<struct test>	v1;
		T<struct test>	v2(154, val);
		
		gettimeofday(&tv, NULL);
		v1.swap(v2);
		print_exec_tm(time, tv);

		output << v1.size() << " " << v2.size() << std::endl;
		for (size_t i = 0 ; i < v1.size() ; i++)
			output << v1.at(i) << " ";
		output << std::endl;
	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	clear(std::ofstream& output, std::ofstream& time)
	{
		output << "$ clear" << std::endl;
		time << "$ clear" << std::endl;

		struct timeval	tv;

		T<struct test>	v1;
		T<struct test>	v2(154, val);
		T<std::string>	v3(str, str + 5);

		gettimeofday(&tv, NULL);
		v1.clear();
		print_exec_tm(time, tv);		

		gettimeofday(&tv, NULL);
		v2.clear();
		print_exec_tm(time, tv);

		gettimeofday(&tv, NULL);
		v3.clear();
		print_exec_tm(time, tv);

		output << v1.size() << " " << v2.size() << " " << v3.size() << std::endl;	
	}

# if defined(FT)
#  define CONTAINER ft
# else
#  define CONTAINER std
# endif

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	swap2(std::ofstream& output, std::ofstream& time)
	{
		output << "$ swap (non-member)" << std::endl;
		time << "$ swap (non-member)" << std::endl;

		struct timeval	tv;

		T<struct test>	v1;
		T<struct test>	v2(154, val);
		
		gettimeofday(&tv, NULL);
		CONTAINER::swap(v1, v2);
		print_exec_tm(time, tv);

		output << v1.size() << " " << v2.size() << std::endl;
		for (size_t i = 0 ; i < v1.size() ; i++)
			output << v1.at(i) << " ";
		output << std::endl;
	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	get_allocator(std::ofstream& output, std::ofstream& time)
	{
		output << "$ get_allocator" << std::endl;
		time << "$ get_allocator" << std::endl;

		struct timeval	tv;

		T<struct test>	v1;
		T<struct test>	v2(154, val);
		T<std::string>	v3(str, str + 5);

		gettimeofday(&tv, NULL);
		output << v1.get_allocator().max_size() << " " << v2.get_allocator().max_size() << " " << v3.get_allocator().max_size() << std::endl;
		print_exec_tm(time, tv);
	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	operators(std::ofstream& output, std::ofstream& time)
	{
		output << "$ relational operators" << std::endl;
		time << "$ relational operators" << std::endl;

		struct timeval	tv;

		T<float>		v1(516, 42.4221);
		T<float>		v2(516, 898.236);
		T<std::string>	v3(str, str + 2);
		T<std::string>	v4(str, str + 5);

		gettimeofday(&tv, NULL);

		output << std::boolalpha;
		output << (v1 == v2) << " " << (v1 != v2) << std::endl;
		output << (v1 < v2) << " " << (v1 <= v2) << std::endl;
		output << (v1 > v2) << " " << (v1 >= v2) << std::endl;

		output << (v3 == v4) << " " << (v3 != v4) << std::endl;
		output << (v3 < v4) << " " << (v3 <= v4) << std::endl;
		output << (v3 > v4) << " " << (v3 >= v4) << std::endl;

		print_exec_tm(time, tv);
	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	iterators(std::ofstream& output, std::ofstream& time)
	{
		struct timeval				tv;
		T<int>						vector_int;
		T<struct test>				vector_struct((size_t)3, test(21, 42));

		output << "$ iterators" << std::endl;
		time << "$ iterators" << std::endl;

		gettimeofday(&tv, NULL);

		typename T<int>::iterator			a;
		typename T<int>::iterator			b(a);
		typename T<int>::iterator			c = a;
		typename T<struct test>::iterator	d = vector_struct.begin();

		output << std::boolalpha << (a == b) << " " << (a != b) << std::endl;

		vector_int.push_back(50);
		vector_int.push_back(18);
		vector_int.push_back(32);
		vector_int.push_back(27);
		vector_int.push_back(6);
		vector_int.push_back(72);
		vector_int.push_back(83);
		a = vector_int.begin();
		output << *a << std::endl;
		output << d->x << std::endl;

		*a = 22;
		output << *a << std::endl;

		++a;
		b++;
		output << (a == b) << " " << *a++ << std::endl;

		--a;
		b--;
		output << (a == b) << " " << *a-- << std::endl;

		c = a + 2;
		b = 2 + a;
		a = c - 1;
		output << *a << " " << *b << " " << *c << " ";
		typename T<int>::iterator::difference_type e = c - a;
		output << e << std::endl;

		output << (a < b) << " " << (a > b) << " " << (a <= b) << " " << (a >= b) << std::endl;

		a += 2;
		output << *a << " ";
		a -= 3;
		output << *a << std::endl;

		a = vector_int.begin();
		output << a[5] << std::endl;
		
		print_exec_tm(time, tv);
	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	test(std::ofstream& output, std::ofstream& time)
	{
		output << "$$$ VECTOR" << std::endl;
		time << "$$$ VECTOR" << std::endl;
		constructors<T>(output, time); time << std::endl;
		begin_end<T>(output, time); time << std::endl;
		size<T>(output, time); time << std::endl;
		max_size<T>(output, time); time << std::endl;
		resize<T>(output, time); time << std::endl;
		capacity<T>(output, time); time << std::endl;
		empty<T>(output, time); time << std::endl;
		reserve<T>(output, time); time << std::endl;
		brackets<T>(output, time); time << std::endl;
		at<T>(output, time); time << std::endl;
		front_back<T>(output, time); time << std::endl;
		assign<T>(output, time); time << std::endl;
		push_back<T>(output, time); time << std::endl;
		pop_back<T>(output, time); time << std::endl;
		insert<T>(output, time); time << std::endl;
		erase<T>(output, time); time << std::endl;
		swap<T>(output, time); time << std::endl;
		clear<T>(output, time); time << std::endl;
		swap2<T>(output, time); time << std::endl;
		get_allocator<T>(output, time); time << std::endl;
		iterators<T>(output, time); time << std::endl;
		operators<T>(output, time); time << std::endl;
	}
}
