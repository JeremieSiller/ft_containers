#if 1
	#include "vector.hpp"
#else
	#include <vector>
	namespace ft = std;
#endif
#include <iostream>

struct int_
{
	private:
		int	i;
	public:
		int_(): i(-1) { }
		int	get() { return (i); }
};

std::ostream	&operator<<(std::ostream &o, int_ i) {
	o << i.get();
	return o;
}


// int	main(void) {
// 	// ft::vector<int> test(1000);

// 	// std::cout << test.max_size() << std::endl;
// 	// std::cout << test.size() << std::endl;
// 	// std::cout << test.capacity() << std::endl;
// 	// test[10] = -100;
// 	// test[0] = 99;
// 	// std::cout << test[10] << std::endl;
// 	// std::cout << test.at(10) << std::endl;
// 	// std::cout << test.front() << std::endl;
// 	// ft::vector<int> test2 = test;
// 	// std::cout << test2[10] << std::endl;
// 	// std::cout << test2.at(10) << std::endl;
// 	// std::cout << test2.front() << std::endl;
// 	// std::cout << "---------" << std::endl;
// 	// std::cout << test[10] << std::endl; 
// 	// test2.assign(100000, test[10]);
// 	// std::cout << test2[1000] << std::endl;
// 	// ft::vector<int> test3(1000, 10);
// 	// std::cout << "---------" << std::endl;
// 	// std::cout << test3.capacity() << std::endl;
// 	// //test3.reserve(1020);
// 	// test3.push_back(69);
// 	// test3.push_back(69);
// 	// test3.push_back(69);
// 	// test3.push_back(69);
// 	// std::cout << test3.capacity() << std::endl;
// 	ft::vector<int> test(1000, 1);
// 	ft::vector<int>::reverse_iterator	begin = test.rbegin();
// 	ft::vector<int>::reverse_iterator	end = test.rend();
// 	*end = 10;
// 	while (begin != end)
// 	{
// 		std::cout << *begin  << "";
// 		begin++;
// 	}
// }

int main ()
{
	ft::vector<int_> test(100);

	ft::vector<int_>::const_iterator begin = test.begin();
	ft::vector<int_>::const_iterator end = test.end();
	while (begin != end)
	{
		std::cout << *begin << " ";
		begin++;
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