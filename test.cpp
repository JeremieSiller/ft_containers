#if 1
	#include "vector.hpp"
#else
	#include <vector>
	namespace ft = std;
#endif
#include <iostream>

int	main(void) {
	ft::vector<int> test(1000);

	std::cout << test.max_size() << std::endl;
	std::cout << test.size() << std::endl;
	std::cout << test.capacity() << std::endl;
	test[10] = -100;
	test[0] = 99;
	std::cout << test[10] << std::endl;
	std::cout << test.at(10) << std::endl;
	std::cout << test.front() << std::endl;
	ft::vector<int> test2 = test;
	std::cout << test2[10] << std::endl;
	std::cout << test2.at(10) << std::endl;
	std::cout << test2.front() << std::endl;
	test2.assign(1000, test[10]);
	std::cout << test2[1000] << std::endl;
}