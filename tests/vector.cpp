#ifdef FT
	#include "../containers/vector.hpp"
#else
	#include <vector>
	namespace ft=std;
#endif

#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
using ft::vector;
using std::cout;
using std::endl;

template<class T>
void	print_vector(vector<T> const &test)
{
	cout << "Printing all vector values: " << endl;
	typename vector<T>::const_iterator begin = test.begin();
	typename vector<T>::const_iterator end = test.end();
	while (begin != end)
	{
		cout << *begin;
		begin++;
		if (begin != end)
			cout << ", ";
	}
	cout << endl;
	cout << "-------------------------------" << endl;
	cout << "get stuff from vector: " << endl;
	cout << "capcity: " << test.capacity() << std::endl;
	cout << "size: " << test.size() << std::endl;
	cout << "max_size: " << test.max_size() << std::endl;
	cout << "begin: " << *test.begin() << std::endl;
	cout << "end: " << *test.end() << std::endl;
	cout << "-------------------------------" << endl;
	cout << "try out of range: (-1)" << endl;
	try {
		T	val = test[-1];
		cout << "doesnt throw error" << endl;
	}
	catch (std::exception const &e)
	{
		cout << "throws error: " << e.what() << endl;
	}
	cout << "-------------------------------" << endl;
	cout << "try out of range: (size)" << endl;
	try {
		T	val = test[test.size() + 1];
		cout << "doesnt throw error" << endl;
	}
	catch (std::exception const &e)
	{
		cout << "throws error: " << e.what() << endl;
	}
	cout << "-------------------------------" << endl;
	cout << "printing front value: " << endl;
	cout << "front: " << test.front() << endl;
	cout << "-------------------------------" << endl;
}

int	main(void)
{
	vector<int>	x(10, 10);
	x.resize(22, -10);
	print_vector<int>(x);
}
