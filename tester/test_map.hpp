/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 02:06:14 by mamartin          #+#    #+#             */
/*   Updated: 2021/09/10 19:00:57 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../containers/map/map.hpp"
#include "utils.hpp"

namespace map
{
	template <template <class Key, class U, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, U> > > class T>
	void	constructors(std::ofstream& output, std::ofstream& time)
	{
		output << "$ constructors" << std::endl;
		time << "$ constructors" << std::endl;

		struct timeval	tv;

		ft::pair<float, std::string>	p[50];

		for (int i = 0 ; i < 50 ; i++)
			p[i] = ft::make_pair(i + 0.21, "test");

		gettimeofday(&tv, NULL);
		T<int, size_t>			m1;
		print_exec_tm(time, tv);	

		gettimeofday(&tv, NULL);
		T<float, std::string>	m2(p, p + 50);
		print_exec_tm(time, tv);	

		gettimeofday(&tv, NULL);
		T<float, std::string>	m3(m2);
		print_exec_tm(time, tv);	

		output << m1.size() << " " << m2.size() << " " << m3.size() << std::endl;
		
		typename T<float, std::string>::iterator it2 = m2.begin();
		typename T<float, std::string>::iterator it3 = m3.begin();

		while (it2 != m2.end())
		{
			output << it2->first << " " << it2->second << " ";
			it2++;
		}
		output << std::endl;

		while (it3 != m3.end())
		{
			output << it3->first << " " << it3->second << " ";
			it3++;
		}
		output << std::endl;
	}

#if 0

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

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	key_comp(std::ofstream& output, std::ofstream& time)
	{

	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	value_comp(std::ofstream& output, std::ofstream& time)
	{

	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	find(std::ofstream& output, std::ofstream& time)
	{

	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	count(std::ofstream& output, std::ofstream& time)
	{

	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	lower_bound(std::ofstream& output, std::ofstream& time)
	{

	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	upper_bound(std::ofstream& output, std::ofstream& time)
	{

	}

	template <template <class U, class Alloc = std::allocator<U> > class T>
	void	equal_range(std::ofstream& output, std::ofstream& time)
	{

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

#endif


	template <template <class Key, class U, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, U> > > class T>
	void	test(std::ofstream& output, std::ofstream& time)
	{
		output << "$$$ MAP" << std::endl;
		time << "$$$ MAP" << std::endl;
		constructors<T>(output, time); time << std::endl;
		//begin_end<T>(output, time); time << std::endl;
		//empty<T>(output, time); time << std::endl;
		//size<T>(output, time); time << std::endl;
		//max_size<T>(output, time); time << std::endl;
		//brackets<T>(output, time); time << std::endl;
		//insert<T>(output, time); time << std::endl;
		//erase<T>(output, time); time << std::endl;
		//swap<T>(output, time); time << std::endl;
		//clear<T>(output, time); time << std::endl;
		//key_comp<T>(output, time); time << std::endl;
		//value_comp<T>(output, time); time << std::endl;
		//find<T>(output, time); time << std::endl;
		//count<T>(output, time); time << std::endl;
		//lower_bound<T>(output, time); time << std::endl;
		//upper_bound<T>(output, time); time << std::endl;
		//equal_range<T>(output, time); time << std::endl;
		//get_allocator<T>(output, time); time << std::endl;
		//iterators<T>(output, time); time << std::endl;
	}
}
