#ifndef UTILS_HPP
# define UTILS_HPP

#pragma once

#include "iterator_traits.hpp"

namespace ft
{
	template<typename InputIterator>
		typename ft::iterator_traits<InputIterator>::difference_type
			distance(InputIterator const &lhs, InputIterator const &rhs) { return rhs.base() - lhs.base(); }
		
	template<typename iterator, typename InputIterator>
		iterator	copy(InputIterator first, InputIterator last, iterator position) {
			--first;
			--last;
			size_t n = ft::distance(first, last);
			position = position + n - 1;
			while (last != first)
			{
				*position = *last; 
				last--;
				position--;
			}
			return(position + n);
		}
		
	template<typename InputIterator>
		bool	lexicographical_compare(InputIterator lhs_begin, InputIterator lhs_end, InputIterator rhs_begin, InputIterator rhs_end)
		{
			for (; lhs_begin != lhs_end && rhs_begin != rhs_end; rhs_begin++, lhs_begin++)
			{
				if (*lhs_begin > *rhs_begin )
					return false;
				else if (*lhs_begin < *rhs_begin)
					return true;
			}
			if (lhs_begin == lhs_end && rhs_begin != rhs_end)
				return true;
			return false;
		}
	template<typename Iterator>
		void	fill(Iterator first, Iterator last, typename ft::iterator_traits<Iterator>::value_type val)
		{
			for (;first != last; first++)
			{
				(*first) = val;
			}
		}
	
} // namespace ft

#endif