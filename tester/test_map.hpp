/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 02:06:14 by mamartin          #+#    #+#             */
/*   Updated: 2021/09/14 22:33:05 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../containers/map/map.hpp"
#include "utils.hpp"

# if defined(FT)
#  define CONTAINER ft
# else
#  define CONTAINER std
# endif

CONTAINER::map<float, long>			gm0;
CONTAINER::map<int, std::string>	gm1;
CONTAINER::map<int, std::string>	gm2;
struct timeval						tv;

namespace map
{
	template <template <class Key, class U, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, U> > > class T>
	void	constructors(std::ofstream& output, std::ofstream& time)
	{
		output << "$ constructors" << std::endl;
		time << "$ constructors" << std::endl;

		CONTAINER::pair<float, std::string>	p[50];

		for (int i = 0 ; i < 50 ; i++)
			p[i] = CONTAINER::make_pair(i + 0.21, "test");

		for (int i = 0 ; i < 50 ; i++)
		{
			gettimeofday(&tv, NULL);
			T<int, size_t>			m1;
			print_exec_tm(time, tv);

			gettimeofday(&tv, NULL);
			T<float, std::string>	m2(p, p + 50);
			print_exec_tm(time, tv);	

			gettimeofday(&tv, NULL);
			T<float, std::string>	m3(m2);
			print_exec_tm(time, tv);
			
			for (typename T<float, std::string>::iterator it = m3.begin() ; it != m3.end() ; it++)
				output << it->first << "/" << it->second << " ";
		}
		output << std::endl;
		
		gm1.insert(p, p+50);
		gm2 = gm1;
	}

	template <template <class Key, class U, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, U> > > class T>
	void	begin_end(std::ofstream& output, std::ofstream& time)
	{
		output << "$ begin & end (& reverse)" << std::endl;
		time << "$ begin & end (& reverse)" << std::endl;

		output << std::boolalpha;
		gettimeofday(&tv, NULL);
		output << (gm1.begin() == gm1.end()) << std::endl;
		print_exec_tm(time, tv);
		gettimeofday(&tv, NULL);
		output << (gm1.rbegin() == gm1.rend()) << std::endl;
		print_exec_tm(time, tv);

		gettimeofday(&tv, NULL);
		output << (*gm2.begin() == *gm2.rend()) << std::endl;
		print_exec_tm(time, tv);
		gettimeofday(&tv, NULL);
		output << (*gm2.end() == *gm2.rbegin()) << std::endl;
		print_exec_tm(time, tv);

		for (typename T<int, std::string>::reverse_iterator rit = gm2.rbegin() ; rit != gm2.rend() ; rit++)
			output << rit->first << "/" << rit->second << " ";
		output << std::endl;
	}

	template <template <class Key, class U, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, U> > > class T>
	void	empty(std::ofstream& output, std::ofstream& time)
	{
		output << "$ empty" << std::endl;
		time << "$ empty" << std::endl;

		gettimeofday(&tv, NULL);
		output << gm0.empty() << " " << gm1.empty() << " " << gm2.empty() << std::endl;
		print_exec_tm(time, tv);

		gm0.insert(CONTAINER::make_pair(78.415, 9999999999999));
		gm1.insert(CONTAINER::make_pair(98, "ahah"));
		gm2.clear();

		gettimeofday(&tv, NULL);
		output << gm0.empty() << " " << gm1.empty() << " " << gm2.empty() << std::endl;
		print_exec_tm(time, tv);
	}

	template <template <class Key, class U, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, U> > > class T>
	void	size(std::ofstream& output, std::ofstream& time)
	{
		output << "$ size" << std::endl;
		time << "$ size" << std::endl;

		gettimeofday(&tv, NULL);
		output << gm0.size() << " " << gm1.size() << " " << gm2.size() << std::endl;
		print_exec_tm(time, tv);
	}

	template <template <class Key, class U, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, U> > > class T>
	void	max_size(std::ofstream& output, std::ofstream& time)
	{
		output << "$ max_size" << std::endl;
		time << "$ max_size" << std::endl;

		gettimeofday(&tv, NULL);
		output << gm0.max_size() << " " << gm1.max_size() << " " << gm2.max_size() << std::endl;
		print_exec_tm(time, tv);
	}

	template <template <class Key, class U, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, U> > > class T>
	void	brackets(std::ofstream& output, std::ofstream& time)
	{
		output << "$ operator[]" << std::endl;
		time << "$ operator[]" << std::endl;

		gm2.insert(gm1.rbegin(), gm1.rend());

		for (size_t i = 0 ; i < gm1.size() ; i++)
		{
			gettimeofday(&tv, NULL);
			output << gm1[i] << " ";
			print_exec_tm(time, tv);
			gettimeofday(&tv, NULL);
			output << gm2[i] << " ";
			print_exec_tm(time, tv);
		}
		output << std::endl;
	}

	template <template <class Key, class U, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, U> > > class T>
	void	insert(std::ofstream& output, std::ofstream& time)
	{
		output << "$ insert" << std::endl;
		time << "$ insert" << std::endl;

		srand(17841684);

		for (int i = 0 ; i < 10 ; i++)
		{
			CONTAINER::pair<int, std::string>	p = CONTAINER::make_pair(std::rand(), std::string("fzekw").substr(std::rand()%5, (5 - std::rand()%5)));
			CONTAINER::pair<float, long>		t[100];

			for (int j = 0 ; j < 100 ; j++)
				t[j] = CONTAINER::make_pair(std::rand() + std::rand()*0.1515, std::rand());

			gettimeofday(&tv, NULL);
			gm0.insert(t, t+100);
			print_exec_tm(time, tv);
			
			gettimeofday(&tv, NULL);
			gm1.insert(p);
			print_exec_tm(time, tv);
			
			typename T<int, std::string>::iterator	pos = gm1.lower_bound(p.first);
			gettimeofday(&tv, NULL);
			gm2.insert(pos, p);
			print_exec_tm(time, tv);
		}

		for (typename T<float, long>::iterator it = gm0.begin() ; it != gm0.end() ; it++)
			output << it->first << "/" << it->second << " ";
		output << std::endl;

		for (typename T<int, std::string>::iterator it = gm1.begin() ; it != gm1.end() ; it++)
			output << it->first << "/" << it->second << " ";
		output << std::endl;

		for (typename T<int, std::string>::iterator it = gm2.begin() ; it != gm2.end() ; it++)
			output << it->first << "/" << it->second << " ";
		output << std::endl;
	}

	template <template <class Key, class U, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, U> > > class T>
	void	erase(std::ofstream& output, std::ofstream& time)
	{
		output << "$ erase" << std::endl;
		time << "$ erase" << std::endl;

		while (!gm0.empty())
		{
			gettimeofday(&tv, NULL);
			gm0.erase(gm0.begin());
			print_exec_tm(time, tv);
		}

		gettimeofday(&tv, NULL);
		gm1.erase(gm1.begin(), gm1.end());
		print_exec_tm(time, tv);

		size_t	sz = gm2.size();
		for (size_t i = 0 ; i < sz ; i++)
		{
			typename T<int, std::string>::iterator	it = gm2.begin();
			int										index = std::rand() % gm2.size();

			for (int j = 0 ; j < index ; j++)
				it++;

			gettimeofday(&tv, NULL);
			gm2.erase(it->first);
			print_exec_tm(time, tv);
		}

		output << gm0.size() << " " << gm1.size() << " " << gm2.size() << std::endl;
		for (typename T<int, std::string>::iterator it = gm2.begin() ; it != gm2.end() ; it++)
			output << it->first << "/" << it->second << " ";
	}

	template <template <class Key, class U, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, U> > > class T>
	void	swap(std::ofstream& output, std::ofstream& time)
	{
		output << "$ swap" << std::endl;
		time << "$ swap" << std::endl;

		for (int i = 0 ; i < 10 ; i++)
		{
			CONTAINER::pair<float, long>		t[100];
			for (int j = 0 ; j < 100 ; j++)
				t[j] = CONTAINER::make_pair(std::rand() + std::rand()*0.1515, std::rand());
			gm0.insert(t, t+100);
			gm1.insert(CONTAINER::make_pair(std::rand(), std::string("fzekw").substr(std::rand()%5, (5 - std::rand()%5))));
			gm2.insert(CONTAINER::make_pair(std::rand(), std::string("fzekw").substr(std::rand()%5, (5 - std::rand()%5))));
		}

		for (int i = 0 ; i < 100 ; i++)
		{
			gettimeofday(&tv, NULL);
			gm1.swap(gm2);
			print_exec_tm(time, tv);
		}

		output << gm0.size() << " " << gm1.size() << " " << gm2.size() << std::endl;
		for (typename T<int, std::string>::iterator it = gm2.begin() ; it != gm2.end() ; it++)
			output << it->first << "/" << it->second << " ";
		output << std::endl;
	}

	template <template <class Key, class U, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, U> > > class T>
	void	clear(std::ofstream& output, std::ofstream& time)
	{
		output << "$ clear" << std::endl;
		time << "$ clear" << std::endl;

		gettimeofday(&tv, NULL);
		gm0.clear();
		print_exec_tm(time, tv);		

		gettimeofday(&tv, NULL);
		gm1.clear();
		print_exec_tm(time, tv);

		gettimeofday(&tv, NULL);
		gm2.clear();
		print_exec_tm(time, tv);

		output << gm0.size() << " " << gm1.size() << " " << gm2.size() << std::endl;	
	}

	template <template <class Key, class U, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, U> > > class T>
	void	key_comp(std::ofstream& output, std::ofstream& time)
	{
		output << "$ key_comp" << std::endl;
		time << "$ key_comp" << std::endl;

		for (int i = 0 ; i < 10 ; i++)
		{
			CONTAINER::pair<float, long>		t[100];
			for (int j = 0 ; j < 100 ; j++)
				t[j] = CONTAINER::make_pair(std::rand() + std::rand()*0.1515, std::rand());
			gm0.insert(t, t+100);
			gm1.insert(CONTAINER::make_pair(std::rand(), std::string("fzekw").substr(std::rand()%5, (5 - std::rand()%5))));
			gm2.insert(CONTAINER::make_pair(std::rand() % 25, std::string("fzekw").substr(std::rand()%5, (5 - std::rand()%5))));
		}

		typename T<int, std::string>::iterator it1 = gm1.begin();
		typename T<int, std::string>::iterator it2 = gm2.begin();
		
		while (it1 != gm1.end() && it2 != gm2.end())
		{
			gettimeofday(&tv, NULL);
			typename CONTAINER::map<int, std::string>::key_compare cmp = gm1.key_comp();
			print_exec_tm(time, tv);

			output << cmp(it1->first, it2->first) << " ";
			it1++; it2++;
		}
		output << std::endl;
	}

	template <template <class Key, class U, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, U> > > class T>
	void	value_comp(std::ofstream& output, std::ofstream& time)
	{
		output << "$ value_comp" << std::endl;
		time << "$ value_comp" << std::endl;

		typename T<int, std::string>::iterator it1 = gm1.begin();
		typename T<int, std::string>::iterator it2 = gm2.begin();
		
		while (it1 != gm1.end() && it2 != gm2.end())
		{
			gettimeofday(&tv, NULL);
			typename CONTAINER::map<int, std::string>::value_compare cmp = gm1.value_comp();
			print_exec_tm(time, tv);

			output << cmp(*it1, *it2) << " ";
			it1++; it2++;
		}
		output << std::endl;
	}

	template <template <class Key, class U, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, U> > > class T>
	void	find(std::ofstream& output, std::ofstream& time)
	{
		output << "$ find" << std::endl;
		time << "$ find" << std::endl;

		for (int i = 0 ; i < 25 ; i++)
		{
			typename T<int, std::string>::iterator ret;

			gettimeofday(&tv, NULL);
			ret = gm2.find(i);
			print_exec_tm(time, tv);
			if (ret != gm2.end())
				output << "true ";	
			else
				output << "false ";	
		}
		output << std::endl;
	}

	template <template <class Key, class U, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, U> > > class T>
	void	count(std::ofstream& output, std::ofstream& time)
	{
		output << "$ count" << std::endl;
		time << "$ count" << std::endl;

		for (int i = 0 ; i < 25 ; i++)
		{
			typename T<int, std::string>::size_type ret;

			gettimeofday(&tv, NULL);
			ret = gm2.count(i);
			print_exec_tm(time, tv);
			output << ret << " ";	
		}
		output << std::endl;
	}

	template <template <class Key, class U, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, U> > > class T>
	void	lower_bound(std::ofstream& output, std::ofstream& time)
	{
		output << "$ lower_bound" << std::endl;
		time << "$ lower_bound" << std::endl;

		for (int i = 0 ; i < 100 ; i++)
		{
			gm1.insert(CONTAINER::make_pair(std::rand(), std::string("fzekw").substr(std::rand()%5, (5 - std::rand()%5))));
			gm2.insert(CONTAINER::make_pair(std::rand(), std::string("fzekw").substr(std::rand()%5, (5 - std::rand()%5))));
		}

		for (int i = 0 ; i < 100 ; i++)
		{
			typename T<int, std::string>::iterator it;
			gettimeofday(&tv, NULL);
			it = gm1.lower_bound(std::rand());
			print_exec_tm(time, tv);
			if (it != gm1.end())
				output << it->first << " ";
			else
				output << "end ";
		}
		output << std::endl;
	}

	template <template <class Key, class U, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, U> > > class T>
	void	upper_bound(std::ofstream& output, std::ofstream& time)
	{
		output << "$ upper_bound" << std::endl;
		time << "$ upper_bound" << std::endl;

		for (int i = 0 ; i < 100 ; i++)
		{
			typename T<int, std::string>::iterator it;
			gettimeofday(&tv, NULL);
			it = gm2.upper_bound(std::rand());
			print_exec_tm(time, tv);
			if (it != gm2.end())
				output << it->first << " ";
			else
				output << "end ";
		}
		output << std::endl;
	}

	template <template <class Key, class U, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, U> > > class T>
	void	equal_range(std::ofstream& output, std::ofstream& time)
	{
		output << "$ equal_range" << std::endl;
		time << "$ equal_range" << std::endl;

		for (int i = 0 ; i < 100 ; i++)
		{
			CONTAINER::pair<typename T<int, std::string>::iterator, typename T<int, std::string>::iterator> p;
			gettimeofday(&tv, NULL);
			int e = std::rand();
			p = gm2.equal_range(e);
			print_exec_tm(time, tv);
			if (p.first == gm2.end())
				output << "end";
			else
				output << p.first->first;
			output << "/";
			if (p.second == gm2.end())
				output << "end";
			else
				output << p.second->first;	
			output << " ";
		}
		output << std::endl;
	}

	template <template <class Key, class U, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, U> > > class T>
	void	get_allocator(std::ofstream& output, std::ofstream& time)
	{
		output << "$ get_allocator" << std::endl;
		time << "$ get_allocator" << std::endl;

		gettimeofday(&tv, NULL);
		output << gm0.get_allocator().max_size() << " " << gm1.get_allocator().max_size() << " " << gm2.get_allocator().max_size() << std::endl;
		print_exec_tm(time, tv);
	}

	template <template <class Key, class U, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, U> > > class T>
	void	iterators(std::ofstream& output, std::ofstream& time)
	{
		output << "$ iterators" << std::endl;
		time << "$ iterators" << std::endl;

		print_exec_tm(time, tv);

		gettimeofday(&tv, NULL);
		typename T<int, std::string>::iterator a;
		print_exec_tm(time, tv);
		gettimeofday(&tv, NULL);
		typename T<int, std::string>::iterator b(gm1.end());
		print_exec_tm(time, tv);
		gettimeofday(&tv, NULL);
		typename T<int, std::string>::iterator c = gm1.begin();
		print_exec_tm(time, tv);

		gettimeofday(&tv, NULL);
		output << (b == c) << " " << (b != c) << std::endl;
		print_exec_tm(time, tv);
		gettimeofday(&tv, NULL);
		output << (*c).first << " " << c->second << std::endl;
		print_exec_tm(time, tv);

		gettimeofday(&tv, NULL);
		output << (*b == *c) << std::endl;
		print_exec_tm(time, tv);

		b = c;
		gettimeofday(&tv, NULL);
		b++;
		print_exec_tm(time, tv);
		gettimeofday(&tv, NULL);
		++c;
		print_exec_tm(time, tv);
		output << (b == c) << " " << (b != c) << std::endl;

		b = c;
		gettimeofday(&tv, NULL);
		b--;
		print_exec_tm(time, tv);
		gettimeofday(&tv, NULL);
		--c;
		print_exec_tm(time, tv);
		output << (b == c) << " " << (b != c) << std::endl;
	}

	template <template <class Key, class U, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, U> > > class T>
	void	test(std::ofstream& output, std::ofstream& time)
	{
		output << "$$$ MAP" << std::endl;
		time << "$$$ MAP" << std::endl;
		constructors<T>(output, time); time << std::endl;
		begin_end<T>(output, time); time << std::endl;
		empty<T>(output, time); time << std::endl;
		size<T>(output, time); time << std::endl;
		max_size<T>(output, time); time << std::endl;
		brackets<T>(output, time); time << std::endl;
		insert<T>(output, time); time << std::endl;
		erase<T>(output, time); time << std::endl;
		swap<T>(output, time); time << std::endl;
		clear<T>(output, time); time << std::endl;
		key_comp<T>(output, time); time << std::endl;
		value_comp<T>(output, time); time << std::endl;
		find<T>(output, time); time << std::endl;
		count<T>(output, time); time << std::endl;
		lower_bound<T>(output, time); time << std::endl;
		upper_bound<T>(output, time); time << std::endl;
		equal_range<T>(output, time); time << std::endl;
		get_allocator<T>(output, time); time << std::endl;
		iterators<T>(output, time); time << std::endl;
	}
}
