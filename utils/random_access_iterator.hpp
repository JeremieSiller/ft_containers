#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#pragma once

#include "utils.hpp"

namespace ft
{
template<typename vector, typename val>
		class	random_access_iterator {
		public:
			typedef typename	vector::value_type				value_type;
			typedef typename	vector::size_type				difference_type;
			typedef				val*							pointer;
			typedef				val&							reference;
			typedef				ft::random_access_iterator_tag	iterator_category;
		public:
			random_access_iterator(random_access_iterator const &in) : _ptr(in._ptr) { }
			random_access_iterator(pointer ptr) : _ptr(ptr) { };
			pointer		base() const { return _ptr; }
			
			random_access_iterator& operator++() {
				_ptr++;
				return *this;
			}
			random_access_iterator operator++(int) {
				random_access_iterator	ret = *this;
				++(*this);
				return ret;
			}
			random_access_iterator& operator--() {
				_ptr--;
				return *this;
			}
			random_access_iterator operator--(int) {
				random_access_iterator	ret = *this;
				--(*this);
				return ret;
			}
			reference operator[] (size_t index) { return	*(_ptr + index); }
			pointer	operator->() { return _ptr; }
			reference	operator*() { return *_ptr;}
			random_access_iterator	operator=(random_access_iterator const &in) { _ptr = in._ptr; return *this; }
			int										operator-(random_access_iterator const &rhs) 	{ return (this->base() - rhs.base()); }
			int										operator+(random_access_iterator const &rhs) 	{ return (this->base() + rhs.base()); }
			random_access_iterator	operator+(int	const &value) 											{ return(this->base() + value); }
			random_access_iterator	operator-(int	const &value) 											{ return(this->base() - value); }
		private:
			pointer	_ptr;
		};
		template<typename vector, typename p>
			bool	operator!=(random_access_iterator<vector, p> const &lhs, random_access_iterator<vector, p> const &rhs) { return (rhs.base() != lhs.base()); }
		template<typename vector, typename p>
			bool	operator==(random_access_iterator<vector, p> const &lhs, random_access_iterator<vector, p> const &rhs) { return (rhs.base() == lhs.base()); }
		template<typename vector, typename p>
			bool	operator< (random_access_iterator<vector, p> const &lhs, random_access_iterator<vector, p> const &rhs) { return (rhs.base() < lhs.base()); }
		template<typename vector, typename p>
			bool	operator> (random_access_iterator<vector, p> const &lhs, random_access_iterator<vector, p> const &rhs) { return (rhs.base() > lhs.base()); }
		template<typename vector, typename p>
			bool	operator>=(random_access_iterator<vector, p> const &lhs, random_access_iterator<vector, p> const &rhs) { return (rhs.base() >= lhs.base()); }
		template<typename vector, typename p>
			bool	operator<=(random_access_iterator<vector, p> const &lhs, random_access_iterator<vector, p> const &rhs) { return (rhs.base() <= lhs.base()); }
} // namespace ft


#endif