#ifdef FOURTY_TWO
	#include <stack.hpp>
#else
	#include <stack>
	namespace ft = std;
#endif
#include <iostream>
#include <stdlib.h>
#include <cstdlib>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error, usage:\n";
		std::cerr << "./stack [random seed = unsigned long]" << std::endl;
	}
	unsigned long	r =   strtoul(argv[1], NULL, 10);
	std::srand(r);
	ft::stack<int> test;
	for (int i = 0; i < 100; i++)
	{
		test.push(std::rand() % 100);
	}
	while (test.empty() == false)
	{
		std::cout << test.top() << std::endl;
		test.pop();
	}
	
}