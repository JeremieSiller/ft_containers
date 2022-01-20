#ifdef FT
	#include "../containers/map.hpp"
	#include "../containers/vector.hpp"
#else
	#include <vector>
	#include <map>
	namespace ft=std;
#endif

#include <cstdlib>
#include <iostream>
#include <string>
#include <limits.h>
#include <stdlib.h>
#include <cstdlib>
#include <set>

using ft::map;
using ft::vector;
using std::cout;
using std::endl;
using std::string;

int	main(void) {
	ft::map<int, int> test;
	for (size_t i = 0; i < 5000; i++)
	{
		test[rand() % 50000] = i;
	}
	for (size_t i = 0; i < 20; i++)
	{
		ft::pair<ft::map<int,int>::iterator, ft::map<int, int>::iterator> eq = test.equal_range(rand() % 1234);
		while (eq.first != eq.second)
		{
			std::cout << eq.first->first << endl;
			eq.first++;
		}
		// std::cout << eq.first->first << endl;
	}
	

	std::cout << "begin: " << test.begin()->first << endl;
	for (size_t i = 0; i < 40; i++)
	{
		if (test.upper_bound(i) != test.end()) {
			if (test.upper_bound(i)->first == 10)
				std::cerr << "upper_bound i: " << i << endl;
			cout << test.upper_bound(i)->first << endl;
		}
		if (test.lower_bound(i) != test.end())
			if (test.lower_bound(i)->first == 10)
				std::cerr << "lower_bound i: " << i << endl;
			cout << test.lower_bound(i)->first << endl;
	}
	
	ft::map<int, int>::reverse_iterator rbg = test.rbegin();
	ft::map<int, int>::reverse_iterator rbe = test.rend();
	while (rbg != rbe)
	{
		cout << rbg->first << " ";
		rbg++;
	}
	cout << endl;
	cout << test.upper_bound(17)->first << endl;
	
	// cout << test.empty() << endl;
	test.insert(ft::pair<const int, int>(10,1));
	test.insert(ft::pair<const int, int>(11,5));
	cout << test.size() << endl;
	// cout << test.empty() << endl;
	test.insert(ft::pair<int, int>(20,1));
	test.insert(ft::pair<int, int>(15,1));
	test.insert(ft::pair<int, int>(25,1));
	test.insert(ft::pair<int, int>(0,1));
	test.insert(ft::pair<int, int>(5,1));
	test.insert(ft::pair<int, int>(-5,1));
	ft::map<int, int>::iterator b = test.begin();
	ft::map<int, int>::iterator e = test.end();
	b = test.begin();
	e = test.end();
	while (b != e) {
		cout << test.size() << endl;
		cout << b->first << ", " << b->second << endl;
		b++;
	}
	b = test.begin();
	for (size_t i = 0; i < 1000000; i++)
	{
		test.insert(ft::pair<int, int>(std::rand() % 100000, i));
		cout << test.size() << endl;
	}
	for (size_t i = 0; i < 1000000; i++)
	{
		test.erase(std::rand() % 1000000);
		if (i % 3 == 0)
			test.insert(ft::pair<int, int>(std::rand() % 10000, i));
		if (i  % 100000 == 0)
			test.clear();

		cout << test.size() << endl;
	}
	for (size_t i = 0; i < 2000; i++)
	{
		b = test.begin();
		for (size_t i = 0; i < rand() % 50; i++)
		{
			b++;
		}
		test.erase(b);
		std::cout  << test.size() << endl;
		// test.insert(ft::make_pair(rand(), i));
		// test.find(rand());
		test[rand()] = i;
	}
	b = test.begin();
	e = test.end();
	while (e != b) {
		std::cout << b->first << std::endl;
		b++;
	}
	e--;
	std::cout << e->first << std::endl;
	b = test.begin();
	e = test.end();
	for (size_t i = 0; i < 200; i++)
	{
		b++;
		e--;
		std::cout << test.count(rand()) << std::endl;
	}
	test.erase(b, e);
	for (size_t i = 0; i < 10000; i++)
	{
		ft::map<int, int>::iterator g = test.find(std::rand() % 10000);
		if (g != test.end()) {
			cout << g->first << endl;
		}
		b = test.lower_bound(rand());
		if (b != test.end())
			cout << b->first << endl;
		b = test.upper_bound(rand());
		if (b != test.end())
			cout << b->first << endl;
		ft::pair<ft::map<int,int>::iterator, ft::map<int, int>::iterator> eq = test.equal_range(i);
		while (eq.first != eq.second)
		{
				std::cout << eq.first->first << endl;
			eq.first++;
		}
		// std::cout << eq.first->first << endl;
	}
	ft::map<int, int> test2(test.begin(), test.end());
	// std::cerr << "not till here" <<endl;


	ft::map<int, int> test3(test2);
	b = test3.begin();
	e = test3.end();

	test2.swap(test3);
	b = test2.begin();
	e = test2.end();
	while (b != e) {
		cout << test3.size() << endl;
		cout << b->first << ", " << b->second << endl;
		b++;
	}
	// --------------------
	ft::map<int, int>::key_compare k = test.key_comp();
	ft::map<int, int>::value_compare v = test.value_comp();
	ft::map<int, int>::const_reverse_iterator	rb = test3.rbegin();
	ft::map<int, int>::const_reverse_iterator	re = test3.rend();
	while (rb != re)
	{
		cout << rb->first << ", " << rb->second << endl;
		rb++;
	}
	cout << "max_size: " << test.max_size();
	{
		ft::map<int, std::string> max_testing;
		cout << max_testing.max_size();
	}
	{
		ft::map<std::string, std::string> max_testing;
		cout << max_testing.max_size();
	}
	{
		ft::map<long, std::string> max_testing;
		cout << max_testing.max_size();
	}
	{
		ft::map<char, std::string> max_testing;
		cout << max_testing.max_size();
	}
	cout << endl;
	ft::map<int, int>::mapped_type &x = test[-1];
	x = -78;
	std::cout << test[-1] << std::endl;
	std::cout << x << std::endl;
	cout << endl;
	test.erase(10);
	b = test.begin();
	e = test.end();
	while (b != e) {
		cout << b->first << " ";
		b++;
	}
	cout << endl;
	// std::cout << test.empty() << std::endl;
	// test.insert(ft::pair< int, int>(2, 2));
	test.insert(ft::pair<int, int>(2, 2));
	std::cout << test.size() << std::endl;
	test.insert(ft::pair< int, int>(5, 5));
	std::cout << test.size() << std::endl;
	test.insert(ft::pair< int, int>(-12, 3));
	std::cout << test.size() << std::endl;
	test.insert(ft::pair< int, int>(3, 3));
	test.insert(ft::pair< int, int>(9, 3));
	test.insert(ft::pair< int, int>(4, 3));
	b = test.begin();
	e = test.end();
	while (b != e) {
		cout << b->first << " ";
		b++;
	}
	std::cout << test.empty() << std::endl;
	// for (size_t i = 0; i < 20; i++)
	// {
	// 	test.insert(ft::pair<int, int>(std::rand(), 1));
	// }
	// std::cout << test.size() << std::endl;
	
	// // // test.insert(ft::pair< int, int>(235, 1));
	// // // test.call_print();
	// ft::map<int, int>::iterator b	= test.begin();
	// ft::map<int, int>::iterator e	= test.end();
	// while (b != e)
	// {
	// 	std::cout << (*b).first << std::endl;
	// 	b++;
	// }
	// b--;
	// std::cout << (*b).first << std::endl;
	// while (rb != re) {
	// 	std::cout << (*rb).first << std::endl;
	// 	rb++;
	// }
	// std::cout << test.max_size() << std::endl;
	// std::cout << (*test.find(2)).second << std::endl;
	// std::cout << test[-12] << std::endl;
	// test[69] = 69;
	// test[69] = 64;
	// std::cout << test[69] << std::endl;
	// rb = test.rbegin();
	// re = test.rend();
	// while (rb != re) {
	// 	std::cout << (*rb).first << std::endl;
	// 	rb++;
	// }
	// test.insert(test.begin(), ft::pair<int, int>(4234, 4));
	// rb = test.rbegin();
	// re = test.rend();
	// while (rb != re) {
	// 	std::cout << (*rb).first << std::endl;
	// 	rb++;
	// }
	// std::cout << (test.find(4234))->second << std::endl;
	// // std::cout << test[69] << std::endl;
	// // std::cout << (*test.find(69)).second << std::endl;
	// // system("leaks a.out");
	// vector<ft::pair<int, int> > inserter;
	// for (size_t i = 0; i < 20; i++)
	// {
	// 	inserter.push_back(ft::pair<int,int>(std::rand(), 1));
	// }
	// test.insert(inserter.begin(), inserter.end());
	// rb = test.rbegin();
	// re = test.rend();
	// while (rb != re) {
	// 	std::cout << (*rb).first << std::endl;
	// 	rb++;
	// }
	// std::cout << "here" << std::endl;
	// // test.erase(test.find(13));
	std::cout << "------" << std::endl;
	while (rb != re) {
		std::cout << (*rb).first << " ";
		rb++;
	}
	cout << endl;
	test.erase(test.find(5));
	rb = test.rbegin();
	re = test.rend();
	while (rb != re) {
		std::cout << (*rb).first << " ";
		rb++;
	}
	cout << endl;
	test.erase(test.find(3));
	rb = test.rbegin();
	re = test.rend();
	while (rb != re) {
		std::cout << (*rb).first << " ";
		rb++;
	}
	cout << endl;
	test.erase(test.find(-12));
	rb = test.rbegin();
	re = test.rend();
	while (rb != re) {
		std::cout << (*rb).first << " ";
		rb++;
	}
	cout << endl;
	std::cout << test.erase(4) << std::endl;
	rb = test.rbegin();
	re = test.rend();
	while (rb != re) {
		std::cout << (*rb).first << " ";
		rb++;
	}
	std::cout << "==" << (test == test3) << std::endl;
	// 	cout << test.size() << endl;

	// cout << endl;
	// test.erase(test.find(2));
	// rb = test.rbegin();
	// re = test.rend();
	// while (rb != re) {
	// 	cout << test.size() << endl;
	// 	std::cout << (*rb).first << " ";
	// 	rb++;
	// }
	// cout << endl;
	// test.erase(test.find(1));
	// rb = test.rbegin();
	// re = test.rend();
	// while (rb != re) {
	// 	std::cout << (*rb).first << " ";
	// 	rb++;
	// }
	// test.erase(test.find(-3));
	// rb = test.rbegin();
	// re = test.rend();
	// while (rb != re) {
	// 	std::cout << (*rb).first << " ";
	// 	rb++;
	// }
	// cout << endl;
	// std::cout << "------" << std::endl;
	// std::cout << test.empty() << std::endl;
	// test.insert(ft::pair< int, int>(2, 2));
	// test.insert(ft::pair<int, int>(2, 2));
	// std::cout << test.size() << std::endl;
	// test.insert(ft::pair< int, int>(5, 5));
	// 	cout << test.size() << endl;
	// std::cout << test.size() << std::endl;
	// test.insert(ft::pair< int, int>(-12, 3));
	// std::cout << test.size() << std::endl;
	// test.insert(ft::pair< int, int>(3, 3));
	// test.insert(ft::pair< int, int>(9, 3));
	// test.insert(ft::pair< int, int>(4, 3));
	// rb = test.rbegin();
	// 	cout << test.size() << endl;
	// re = test.rend();
	// while (rb != re) {
	// 	std::cout << (*rb).first << " ";
	// 	rb++;
	// }
	// std::cout << std::endl;
	// // test.erase(test.find(5));
	// test.erase(++test.begin(), --test.end());
	// rb = test.rbegin();
	// re = test.rend();
	// std::cout << std::endl;
	// while (rb != re) {
	// 	std::cout << (*rb).first << " ";
	// 	rb++;
	// }
	// std::cout << std::endl;
	// std::cout << "---" << std::endl;
	// test.erase(test.begin(), test.end());
	// rb = test.rbegin();
	// re = test.rend();
	// while (rb != re) {
	// 	std::cout << (*rb).first << " ";
	// 	cout << test.size() << endl;
	// 	rb++;
	// }
	// cout << endl;
	// test.insert(ft::pair<int, int>(4, 5));
	// 	cout << test.size() << endl;
	// rb = test.rbegin();
	// re = test.rend();
	// std::cout << std::endl;
	// while (rb != re) {
	// 	std::cout << (*rb).first << " ";
	// 	rb++;
	// }
	// std::cout << std::endl;
	// // system("leaks out");
	// test[235] = 13;
	// test[0] = 11;
	// std::cout << test.size() << endl;
	// ft::map<int, int> t2;

	// t2.insert(ft::pair<int, int>(1234, 231));
	// t2.insert(ft::pair<int, int>(564, 231));
	// t2.insert(ft::pair<int, int>(124, 231));
	// t2.insert(ft::pair<int, int>(152334, 231));
	// t2.insert(ft::pair<int, int>(1234, 231));
	// t2.insert(ft::pair<int, int>(17654, 231));
	// test.swap(t2);
	// test.clear();
	// rb = test.rbegin();
	// re = test.rend();
	// while (rb != re)
	// {
	// 	std::cout << (*rb).first << endl;
	// 	rb++;
	// }
	
	return (0);
}

