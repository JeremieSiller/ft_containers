#ifndef STACK_HPP
# define STACK_HPP

#pragma once

#include <memory>

template <
	class T,
	class Allocator = std::allocator<T>
> class stack
{
private:
	/* data */
public:
	stack(/* args */);
	~stack();
};

//STACK_HPP
#endif