#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# pragma once

# include "random_access_iterator.hpp"

namespace ft {
	template <typename iterator>
		class reverse_iterator {
		public:
			typedef typename	iterator::value_type		value_type;
			typedef typename	iterator::difference_type	difference_type;
			typedef typename	iterator::pointer			pointer;
			typedef typename	iterator::reference			reference;
			typedef typename	iterator::iterator_category	iterator_category;
		private:
			iterator _iterator;
		public:
			reverse_iterator() : _iterator() { }
			explicit reverse_iterator(iterator const &in) : _iterator(in) { }
			template<typename Iter>
				reverse_iterator(reverse_iterator<Iter> const &in) : _iterator(in.base()) { }
			~reverse_iterator() {}
			iterator		base() const { return _iterator; }
			reverse_iterator	&operator++() {
				--_iterator;
				return *this;
			}
			reverse_iterator	operator++(int) {
				reverse_iterator	ret = *this;
				++(*this);
				return ret;
			}
			reverse_iterator	&operator--() {
				++_iterator;
				return *this;
			}
			reverse_iterator	operator--(int) {
				reverse_iterator	ret = *this;
				--(*this);
				return ret;
			}
			reference	operator[](size_t index) { return *(_iterator[-index]); }
			pointer		operator->() { return (_iterator.base()); }
			reference	operator*()  { return *(_iterator - 1); }
			reverse_iterator	operator=(reverse_iterator const &in)  { _iterator = in._iterator; return *this; }
			reverse_iterator	operator+=(int const &value) { _iterator -= value; return *this; }
			reverse_iterator	operator-=(int const &value) { _iterator += value; return *this; }
			int					operator+(reverse_iterator const &rhs) const { return _iterator - rhs._iterator; }
			int					operator-(reverse_iterator const &rhs) const { return _iterator + rhs._iterator; }
			reverse_iterator	operator+(int const &value)				const { return reverse_iterator(_iterator - (value)); }
			reverse_iterator	operator-(int const &value)				const { return reverse_iterator(_iterator + (value)); }
		};
		template<typename iterator>
			bool	operator!=(reverse_iterator<iterator> const &lhs, reverse_iterator<iterator> const &rhs) { return (rhs.base() != lhs.base()); }
		template<typename iterator>
			bool	operator==(reverse_iterator<iterator> const &lhs, reverse_iterator<iterator> const &rhs) { return (rhs.base() == lhs.base()); }
		template<typename iterator>
			bool	operator< (reverse_iterator<iterator> const &lhs, reverse_iterator<iterator> const &rhs) { return (rhs.base() > lhs.base()); }
		template<typename iterator>
			bool	operator> (reverse_iterator<iterator> const &lhs, reverse_iterator<iterator> const &rhs) { return (rhs.base() < lhs.base()); }
		template<typename iterator>
			bool	operator>=(reverse_iterator<iterator> const &lhs, reverse_iterator<iterator> const &rhs) { return (rhs.base() <= lhs.base()); }
		template<typename iterator>
			bool	operator<=(reverse_iterator<iterator> const &lhs, reverse_iterator<iterator> const &rhs) { return (rhs.base() >= lhs.base()); }
} //end namepsace ft

#endif