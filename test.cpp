#if 0
	#include "vector.hpp"
#else
	#include <vector>
	namespace ft = std;
#endif
#include <iostream>

int	main(void) {
	ft::vector<int> test(100000000000);

	std::cout << test.max_size() << std::endl;
	std::cout << test.size() << std::endl;
	std::cout << test.capacity() << std::endl;
	//std::cout << test[99999] << std::endl;
}