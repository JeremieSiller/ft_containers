#if 1
	#include "vector.hpp"
	#include <vector>
#else
	#include <vector>
	namespace ft = std;
#endif
#include <iostream>

int main() {

	std::vector<char> st(100);

	std::vector<int>::iterator begin = st.begin();
	std::vector<int>::iterator end = st.end();
	for (int i = 0; begin != end; i++, begin++)
	{
		*begin = i;
	}
	
	ft::vector<int> test((size_t)10, 10);
	ft::vector<int>::const_iterator beg = test.begin();
	ft::vector<int>::const_iterator en = test.end();
	while (beg != en)
	{
		std::cout << *beg << " ";
		beg++;
	}
	std::cout << std::endl;
	
	// std::cout << test.size() << std::endl;
	// std::cout << test.capacity() << std::endl;
	// // test.clear();
	// // std::cout << test.size() << std::endl;
	// // std::cout << test.capacity() << std::endl;
	// //test.push_back(-69);
	// std::cout << *(--test.end())<< std::endl;
	// std::cout << test.end() - test.begin() << std::endl;
	// std::cout << test.end().base() - test.begin().base() << std::endl;
	// //test.resize(300, 2);
	// std::cout << test.end().base() - test.begin().base() << std::endl;
	// std::cout << *(--test.end()) << std::endl;
  return 0;
}