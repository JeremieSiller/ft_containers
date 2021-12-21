#ifndef MAP_HPP
# define MAP_HPP

#include <memory>
#include <functional>
#include <map>

namespace ft {
	template<
	class Key,
	    class T,
	    class Compare = std::less<Key>, //???
	    class Allocator = std::allocator<std::pair<const Key, T> >
	> class map {

	};
}

#endif