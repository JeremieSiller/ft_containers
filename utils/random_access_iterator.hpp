#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#pragma once

#include "utils.hpp"

namespace ft
{
template<typename _value, typename vector>
		class	random_access_iterator {
		public:
			typedef typename	vector::size_type				difference_type;
			// typedef	typename	vector::value_type				value_type;
			typedef				_value							value_type;
			typedef				value_type*								pointer;
			typedef				value_type&						reference;
			typedef				ft::random_access_iterator_tag	iterator_category;
		public:
			// random_access_iterator(random_access_iterator const &in) : _ptr(in._ptr) { }
			random_access_iterator() : _ptr() { };
			random_access_iterator(pointer ptr) : _ptr(ptr) { };
			random_access_iterator(const random_access_iterator<typename vector::value_type, vector> &in) : _ptr(in.base()) { }
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
			pointer	operator->() { return &(this->operator*()); }
			reference	operator*() { return *_ptr;}
			reference	operator*() const { return *_ptr;}
			random_access_iterator	operator=(random_access_iterator const &in) { _ptr = in._ptr; return *this; }
				int						operator-(random_access_iterator const &rhs) const	{ return ((this->base()) - (rhs.base())); }
			random_access_iterator	operator+(int	const &value) 								 const	{ return(this->base() + value); }
			random_access_iterator	operator-(int	const &value) 								 const	{ return(this->base() - value); }
			random_access_iterator	operator+=(int	const &value) {
				_ptr += value;
				return *this;
			}
			random_access_iterator	operator-=(int	const &value) {
				_ptr -= value;
				return *this;
			}
		private:
			pointer	_ptr;
		};
		template<typename p, typename vector>
			random_access_iterator<p, vector>	operator-(const int &lhs, random_access_iterator<p,vector> const &rhs) { return random_access_iterator<p,vector>(lhs - rhs.base()); }
		template<typename p, typename vector>
			random_access_iterator<p, vector>	operator+(const int &lhs, random_access_iterator<p,vector> const &rhs) { return random_access_iterator<p,vector>(lhs + rhs.base()); }
		template<typename p, typename vector>
			bool	operator!=(random_access_iterator<p, vector> const &lhs, random_access_iterator<p, vector> const &rhs) { return (rhs.base() != lhs.base()); }
		template<typename p, typename vector>
			bool	operator!=(random_access_iterator<const typename vector::value_type, vector> const &lhs, random_access_iterator<p, vector> const &rhs) { return (rhs.base() != lhs.base()); }
		template<typename p, typename vector>
			bool	operator!=(random_access_iterator<p, vector> const &lhs, random_access_iterator<const typename vector::value_type, vector> const &rhs) { return (rhs.base() != lhs.base()); }
		template<typename p, typename vector>
			bool	operator==(random_access_iterator<p, vector> const &lhs, random_access_iterator<p, vector> const &rhs) { return (rhs.base() == lhs.base()); }
		template<typename p, typename vector>
			bool	operator==(random_access_iterator<const typename vector::value_type, vector> const &lhs, random_access_iterator<p, vector> const &rhs) { return (rhs.base() == lhs.base()); }
		template<typename p, typename vector>
			bool	operator==(random_access_iterator<p, vector> const &lhs, random_access_iterator<const typename vector::value_type, vector> const &rhs) { return (rhs.base() == lhs.base()); }
		template<typename p, typename vector>
			bool	operator< (random_access_iterator<p, vector> const &lhs, random_access_iterator<p, vector> const &rhs) { return (lhs.base() < rhs.base()); }
		template<typename p, typename vector>
			bool	operator< (random_access_iterator<const typename vector::value_type, vector> const &lhs, random_access_iterator<p, vector> const &rhs) { return (lhs.base() < rhs.base()); }
		template<typename p, typename vector>
			bool	operator< (random_access_iterator<p, vector> const &lhs, random_access_iterator<const typename vector::value_type, vector> const &rhs) { return (lhs.base() < rhs.base()); }
		template<typename p, typename vector>
			bool	operator> (random_access_iterator<p, vector> const &lhs, random_access_iterator<p, vector> const &rhs) { return (lhs.base() > rhs.base()); }
		template<typename p, typename vector>
			bool	operator> (random_access_iterator<const typename vector::value_type, vector> const &lhs, random_access_iterator<p, vector> const &rhs) { return (lhs.base() > rhs.base()); }
		template<typename p, typename vector>
			bool	operator> (random_access_iterator<p, vector> const &lhs, random_access_iterator<const typename vector::value_type, vector> const &rhs) { return (lhs.base() > rhs.base()); }
		template<typename p, typename vector>
			bool	operator>=(random_access_iterator<p, vector> const &lhs, random_access_iterator<p, vector> const &rhs) { return (lhs.base() >= rhs.base()); }
		template<typename p, typename vector>
			bool	operator>=(random_access_iterator<const typename vector::value_type, vector> const &lhs, random_access_iterator<p, vector> const &rhs) { return (lhs.base() >= rhs.base()); }
		template<typename p, typename vector>
			bool	operator>=(random_access_iterator<p, vector> const &lhs, random_access_iterator<const typename vector::value_type, vector> const &rhs) { return (lhs.base() >= rhs.base()); }
		template<typename p, typename vector>
			bool	operator<=(random_access_iterator<p, vector> const &lhs, random_access_iterator<p, vector> const &rhs) { return (lhs.base() <= rhs.base()); }
		template<typename p, typename vector>
			bool	operator<=(random_access_iterator<const typename vector::value_type, vector> const &lhs, random_access_iterator<p, vector> const &rhs) { return (lhs.base() <= rhs.base()); }
		template<typename p, typename vector>
			bool	operator<=(random_access_iterator<p, vector> const &lhs, random_access_iterator<const typename vector::value_type, vector> const &rhs) { return (lhs.base() <= rhs.base()); }
} // namespace ft


#endif