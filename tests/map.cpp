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

using ft::map;
using ft::vector;
using std::cout;
using std::endl;
using std::string;

int	main(void) {
	ft::map<int, int> test;
	cout << test.empty() << endl;
	test.insert(ft::pair<const int, int>(10,1));
	test.insert(ft::pair<const int, int>(10,5));
	cout << test.size() << endl;
	cout << test.empty() << endl;
	// test.insert(ft::pair<int, int>(20,1));
	// test.insert(ft::pair<int, int>(15,1));
	// test.insert(ft::pair<int, int>(25,1));
	// test.insert(ft::pair<int, int>(0,1));
	// test.insert(ft::pair<int, int>(5,1));
	// test.insert(ft::pair<int, int>(-5,1));
	ft::map<int, int>::const_iterator b = test.begin();
	ft::map<int, int>::const_iterator e = test.end();
	b = test.begin();
	e = test.end();
	while (b != e) {
		cout << test.size() << endl;
		cout << b->first << ", " << b->second << endl;
		b++;
	}
	for (size_t i = 0; i < 500; i++)
	{
		test.insert(ft::pair<int, int>(std::rand(), i));
		cout << test.size() << endl;
	}

	ft::map<int, int> test2(test.begin(), test.end());

	// test2.insert(test.end(), test.begin());

	ft::map<int, int> test3(test2);
	b = test3.begin();
	e = test3.end();
	while (b != e) {
		cout << test3.size() << endl;
		cout << b->first << ", " << b->second << endl;
		b++;
	}
	
	ft::map<int, int>::const_reverse_iterator	rb = test3.rbegin();
	ft::map<int, int>::const_reverse_iterator	re = test3.rend();
	while (rb != re)
	{
		cout << rb->first << ", " << rb->second << endl;
		rb++;
	}
	
	// cout << endl;
	// test.erase(10);
	// b = test.begin();
	// e = test.end();
	// while (b != e) {
	// 	cout << b->first << " ";
	// 	b++;
	// }
	// cout << endl;
	// std::cout << test.empty() << std::endl;
	// // test.insert(ft::pair< int, int>(2, 2));
	// test.insert(ft::pair<int, int>(2, 2));
	// std::cout << test.size() << std::endl;
	// test.insert(ft::pair< int, int>(5, 5));
	// std::cout << test.size() << std::endl;
	// test.insert(ft::pair< int, int>(-12, 3));
	// std::cout << test.size() << std::endl;
	// test.insert(ft::pair< int, int>(3, 3));
	// test.insert(ft::pair< int, int>(9, 3));
	// test.insert(ft::pair< int, int>(4, 3));
	// b = test.begin();
	// e = test.end();
	// while (b != e) {
	// 	cout << b->first << " ";
	// 	b++;
	// }
	// // std::cout << test.empty() << std::endl;
	// // for (size_t i = 0; i < 20; i++)
	// // {
	// // 	test.insert(ft::pair<int, int>(std::rand(), 1));
	// // }
	// // std::cout << test.size() << std::endl;
	
	// // // // test.insert(ft::pair< int, int>(235, 1));
	// // // // test.call_print();
	// // ft::map<int, int>::iterator b	= test.begin();
	// // ft::map<int, int>::iterator e	= test.end();
	// // while (b != e)
	// // {
	// // 	std::cout << (*b).first << std::endl;
	// // 	b++;
	// // }
	// // b--;
	// // std::cout << (*b).first << std::endl;
	// map<int, int>::const_reverse_iterator rb = test.rbegin();
	// map<int, int>::const_reverse_iterator re = test.rend();
	// // while (rb != re) {
	// // 	std::cout << (*rb).first << std::endl;
	// // 	rb++;
	// // }
	// // std::cout << test.max_size() << std::endl;
	// // std::cout << (*test.find(2)).second << std::endl;
	// // std::cout << test[-12] << std::endl;
	// // test[69] = 69;
	// // test[69] = 64;
	// // std::cout << test[69] << std::endl;
	// // rb = test.rbegin();
	// // re = test.rend();
	// // while (rb != re) {
	// // 	std::cout << (*rb).first << std::endl;
	// // 	rb++;
	// // }
	// // test.insert(test.begin(), ft::pair<int, int>(4234, 4));
	// // rb = test.rbegin();
	// // re = test.rend();
	// // while (rb != re) {
	// // 	std::cout << (*rb).first << std::endl;
	// // 	rb++;
	// // }
	// // std::cout << (test.find(4234))->second << std::endl;
	// // // std::cout << test[69] << std::endl;
	// // // std::cout << (*test.find(69)).second << std::endl;
	// // // system("leaks a.out");
	// // vector<ft::pair<int, int> > inserter;
	// // for (size_t i = 0; i < 20; i++)
	// // {
	// // 	inserter.push_back(ft::pair<int,int>(std::rand(), 1));
	// // }
	// // test.insert(inserter.begin(), inserter.end());
	// // rb = test.rbegin();
	// // re = test.rend();
	// // while (rb != re) {
	// // 	std::cout << (*rb).first << std::endl;
	// // 	rb++;
	// // }
	// // std::cout << "here" << std::endl;
	// // // test.erase(test.find(13));
	// std::cout << "------" << std::endl;
	// while (rb != re) {
	// 	std::cout << (*rb).first << " ";
	// 	rb++;
	// }
	// cout << endl;
	// test.erase(test.find(5));
	// rb = test.rbegin();
	// re = test.rend();
	// while (rb != re) {
	// 	std::cout << (*rb).first << " ";
	// 	rb++;
	// }
	// cout << endl;
	// test.erase(test.find(3));
	// rb = test.rbegin();
	// re = test.rend();
	// while (rb != re) {
	// 	std::cout << (*rb).first << " ";
	// 	rb++;
	// }
	// cout << endl;
	// test.erase(test.find(-12));
	// rb = test.rbegin();
	// re = test.rend();
	// while (rb != re) {
	// 	std::cout << (*rb).first << " ";
	// 	rb++;
	// }
	// cout << endl;
	// std::cout << test.erase(4) << std::endl;
	// rb = test.rbegin();
	// re = test.rend();
	// while (rb != re) {
	// 	std::cout << (*rb).first << " ";
	// 	rb++;
	// }
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
	// // test.erase(test.find(1));
	// // rb = test.rbegin();
	// // re = test.rend();
	// // while (rb != re) {
	// // 	std::cout << (*rb).first << " ";
	// // 	rb++;
	// // }
	// // test.erase(test.find(-3));
	// // rb = test.rbegin();
	// // re = test.rend();
	// // while (rb != re) {
	// // 	std::cout << (*rb).first << " ";
	// // 	rb++;
	// // }
	// // cout << endl;
	// std::cout << "------" << std::endl;
	// std::cout << test.empty() << std::endl;
	// // test.insert(ft::pair< int, int>(2, 2));
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
	
	// return (0);
}

