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

using ft::map;
using ft::vector;
using std::cout;
using std::endl;
using std::string;

int	main(void) {
	ft::map<int, int> test;
	std::cout << test.max_size() << std::endl;
	std::cout << test.empty() << std::endl;
	test.insert(ft::pair< int, int>(2, 2));
	test.insert(ft::pair<int, int>(2, 2));
	std::cout << test.size() << std::endl;
	test.insert(ft::pair< int, int>(3, 3));
	std::cout << test.size() << std::endl;
	test.insert(ft::pair< int, int>(12, 3));
	std::cout << test.size() << std::endl;
	test.insert(ft::pair< int, int>(13, 3));
	std::cout << test.size() << std::endl;
	test.insert(ft::pair< int, int>(-12, 3));
	// test.insert(ft::pair< int, int>(35, 3));
	test.insert(ft::pair< int, int>(1, 1));
	test.insert(ft::pair< int, int>(-3, 1));
	std::cout << test.empty() << std::endl;
	for (size_t i = 0; i < 20; i++)
	{
		test.insert(ft::pair<int, int>(std::rand(), 1));
	}
	std::cout << test.size() << std::endl;
	
	// // test.insert(ft::pair< int, int>(235, 1));
	// // test.call_print();
	ft::map<int, int>::iterator b	= test.begin();
	ft::map<int, int>::iterator e	= test.end();
	while (b != e)
	{
		std::cout << (*b).first << std::endl;
		b++;
	}
	b--;
	std::cout << (*b).first << std::endl;
	map<int, int>::const_reverse_iterator rb = test.rbegin();
	map<int, int>::const_reverse_iterator re = test.rend();
	while (rb != re) {
		std::cout << (*rb).first << std::endl;
		rb++;
	}
	std::cout << test.max_size() << std::endl;
	std::cout << (*test.find(2)).second << std::endl;
	std::cout << test[-12] << std::endl;
	test[69] = 69;
	test[69] = 64;
	std::cout << test[69] << std::endl;
	rb = test.rbegin();
	re = test.rend();
	while (rb != re) {
		std::cout << (*rb).first << std::endl;
		rb++;
	}
	test.insert(test.begin(), ft::pair<int, int>(4234, 4));
	rb = test.rbegin();
	re = test.rend();
	while (rb != re) {
		std::cout << (*rb).first << std::endl;
		rb++;
	}
	std::cout << (test.find(4234))->second << std::endl;
	// std::cout << test[69] << std::endl;
	// std::cout << (*test.find(69)).second << std::endl;
	// system("leaks a.out");
	vector<ft::pair<int, int> > inserter;
	for (size_t i = 0; i < 20; i++)
	{
		inserter.push_back(ft::pair<int,int>(std::rand(), 1));
	}
	test.insert(inserter.begin(), inserter.end());
	rb = test.rbegin();
	re = test.rend();
	while (rb != re) {
		std::cout << (*rb).first << std::endl;
		rb++;
	}
	std::cout << "here" << std::endl;
	// test.erase(test.find(13));
	test.erase(test.find(-12));
	rb = test.rbegin();
	re = test.rend();
	// while (rb != re) {
	// 	std::cout << (*rb).first << std::endl;
	// 	rb++;
	// }
	return (0);
}

