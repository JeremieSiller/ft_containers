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
	// cout << "end: " << *test.end() << std::endl;
	cout << "-------------------------------" << endl;
	cout << "try out of range: (-1)" << endl;
	// try {
	// 	// T	val = test[-1];
	// 	cout << "doesnt throw error" << endl;
	// }
	// catch (std::exception const &e)
	// {
	// 	cout << "throws error" << endl;
	// }
	// cout << "-------------------------------" << endl;
	// cout << "try out of range: (size)" << endl;
	// try {
	// 	T	val = test.at(test.size());
	// 	cout << "doesnt throw error" << endl;
	// }
	// catch (std::exception const &e)
	// {
	// 	cout << "throws error" << endl;
	// }
	cout << "-------------------------------" << endl;
	cout << "printing front value: " << endl;
	cout << "front: " << test.front() << endl;
	cout << "-------------------------------" << endl;
}

class testClass {
public:
	std::string str;
	int	val;
private:
	testClass &operator=(testClass const &in) { return *this; };
public:
	testClass() : val() { }
	testClass(int v) : val(v) { }
	~testClass() { }
};

int	main(void)
{
	vector<int>	x(10, 9);
	print_vector<int>(x);
	x.resize(22, 13);
	print_vector<int>(x);
	x.push_back(97);
	print_vector<int>(x);
	x.pop_back();
	print_vector<int>(x);
	while (x.size())
	{
		x.pop_back();
		print_vector<int>(x);
	}
	print_vector<int>(x);
	x.assign(5, 3);
	print_vector<int>(x);
	x.insert((x.begin()), 1, 72);
	print_vector(x);
	x.insert(++(x.begin()), 1, 73);
	print_vector(x);
	x.insert((x.end()), 1, 432);
	print_vector(x);
	x.insert(--(x.end()), 1, 90);
	print_vector(x);
	std::cout << *x.insert(--x.end(), 33) << std::endl;
	std::cout << *x.erase(--(x.end())) << std::endl;
	print_vector(x);
	std::cout << *x.erase(++x.begin(), --x.end()) << std::endl;
	print_vector(x);
	std::cout << *x.erase(++x.begin(), --x.end()) << std::endl;
	print_vector(x);
	vector<int>	t;
	t = x;
	print_vector(t);
	t.push_back(-2353);
	print_vector(t);
	t.push_back(-2323);
	print_vector(t);
	t.push_back(12312);
	print_vector(t);
	x = t;
	print_vector(x);
	print_vector(t);
	t.push_back(-123);
	x[0] = 666;
	std::cout << *x.begin() << std::endl;
	std::cout << *t.begin() << std::endl;
	x.swap(t);
	std::cout << *x.begin() << std::endl;
	std::cout << *t.begin() << std::endl;
	print_vector(x);
	print_vector(t);
	std::cout << x.size() << std::endl;
	std::cout << t.size() << std::endl;
	std::cout << (t != x) << std::endl;
	std::cout << (t == x) << std::endl;
	std::cout << (t < x) << std::endl;
	std::cout << (t > x) << std::endl;
	std::cout << (t <= x) << std::endl;
	std::cout << (t >= x) << std::endl;
	t = x;
	std::cout << (t != x) << std::endl;
	std::cout << (t == x) << std::endl;
	std::cout << (t < x) << std::endl;
	std::cout << (t <= x) << std::endl;
	std::cout << (t > x) << std::endl;
	std::cout << (t >= x) << std::endl;
	t.push_back(-123);
	swap(x, t);
	print_vector(x);
	std::cout << (t != x) << std::endl;
	std::cout << (t == x) << std::endl;
	std::cout << (t < x) << std::endl;
	std::cout << (t <= x) << std::endl;
	std::cout << (t > x) << std::endl;
	std::cout << (t >= x) << std::endl;
	print_vector(t);
	vector<int> d(t.begin(), t.end());
	print_vector(d);
	d.assign(x.begin(), x.end());
	print_vector(d);
	d.assign(t.begin(), t.end());
	print_vector(d);
	d.assign(3, 11);
	print_vector(d);
	d.insert(++d.begin(), 7, -4);
	print_vector(d);
	print_vector(t);
	d.reserve(100);
	d.insert(d.begin(), t.begin(), t.end());
	print_vector(d);
	d.insert(d.end(), t.begin(), t.end());
	print_vector(d);
	d.insert(d.end() - 4, t.begin(), t.end());
	d.insert(d.end() - 4, t.begin(), t.end());
	d.insert(d.end() - 4, t.begin(), t.end());
	d.insert(d.end() - 4, t.begin(), t.end());
	d.insert(d.end() - 4, t.begin(), t.end());
	d.insert(d.end() - 4, t.begin(), t.end());
	d.insert(d.end() - 4, t.begin(), t.end());
	d.insert(d.end() - 4, t.begin(), t.end());
	print_vector(d);
	d.reserve(1000000);
	d.resize(1231, 234);
	d.resize(123100000, 234);
	d.resize(12, 44);
	{
		vector<int>::reverse_iterator	rbegin = d.rbegin();
		vector<int>::reverse_iterator	rend = d.rend();
		while (rbegin != rend)
		{
			std::cout << *rbegin << std::endl;
			*rbegin = 2345;
			rbegin++;
		}
	}
	vector<int>::const_reverse_iterator	rbegin = d.rbegin();
	vector<int>::const_reverse_iterator	rend = d.rend();
	while (rbegin != rend)
	{
		std::cout << *rbegin << std::endl;
		rbegin++;
	}
}
