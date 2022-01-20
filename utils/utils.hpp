#ifndef UTILS_HPP
# define UTILS_HPP

#pragma once

#include "iterator_traits.hpp"

namespace ft
{
	template<typename InputIterator>
		typename ft::iterator_traits<InputIterator>::difference_type
			distance(InputIterator first, InputIterator last) {
				typename ft::iterator_traits<InputIterator>::difference_type	count = 0;
					for (;first != last;) {
						count++;
						first++;
					}
				return count;
			}
		
	template<typename iterator, typename InputIterator>
		iterator	backward_copy(InputIterator first, InputIterator last, iterator position) {
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

	template<typename iterator, typename InputIterator>
		iterator	copy(InputIterator first, InputIterator last, iterator position) {
			while (first != last)
			{
				*position = *first;
				first++;
				position++;
			}
			return(position);
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

	template <class InputIterator1, class InputIterator2>
		bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
		{
			while (first1!=last1) {
				if (!(*first1 == *first2))
					return false;
			++first1; ++first2;
			}
			return true;
		}
	
	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
		bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
			while (first1!=last1) {
				if (!pred(*first1 == *first2))
					return false;
			++first1; ++first2;
			}
			return true;
		}
	
	template<typename Iterator>
		void	fill(Iterator first, Iterator last, typename ft::iterator_traits<Iterator>::value_type val)
		{
			for (;first != last; first++)
			{
				(*first) = val;
			}
		}
	
	template<typename T>
		void	swap(T &first, T& second) {
			T	tmp = first;
			first = second;
			second = tmp;
		}
} // namespace ft

#endif