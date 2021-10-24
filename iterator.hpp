#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# pragma once

namespace ft {
	template<typename vector>
		class	vec_iterator {
			typedef typename	vector::value_type		value_type;
			typedef typename	vector::reference		reference;
			typedef typename	vector::pointer			pointer;
		public:
			vec_iterator(pointer ptr) : _ptr(ptr) { };
			vec_iterator& operator++() {
				_ptr++;
				return *this;
			}
			vec_iterator operator++(int) {
				vec_iterator	ret = *this;
				++(*this);
				return ret;
			}
			vec_iterator& operator--() {
				_ptr--;
				return *this;
			}
			vec_iterator operator--(int) {
				vec_iterator	ret = *this;
				--(*this);
				return ret;
			}
			reference operator[] (size_t index) {
				return	*(_ptr + index);
			}
			pointer	operator->() {
				return _ptr;
			}
			reference	operator*() {
				return *_ptr;
			}
			bool	operator==(const vec_iterator& other) const {
				return (_ptr == other._ptr);
			}
			bool	operator!=(const vec_iterator& other) const {
				return (_ptr != other._ptr);
			}
		private:
			pointer	_ptr;
		};
	
	/*
	** @brief: const iterator
	** nearly the same as it. Not able to change stuff in vector tho.
	*/
	template<class vector>
		class	const_vec_iterator {
		public:
			typedef typename	vector::value_type		value_type;
			typedef typename	vector::const_reference		reference;
			typedef typename	vector::pointer			pointer;
		public:
			const_vec_iterator(pointer ptr) : _ptr(ptr) { };
			const_vec_iterator(vec_iterator<vector> it) : _ptr(&(it[0])) { };
			const_vec_iterator& operator++() {
				_ptr++;
				return *this;
			}
			const_vec_iterator operator++(int) {
				const_vec_iterator	ret = *this;
				++(*this);
				return ret;
			}
			const_vec_iterator& operator--() {
				_ptr--;
				return *this;
			}
			const_vec_iterator operator--(int) {
				const_vec_iterator	ret = *this;
				--(*this);
				return ret;
			}
			reference operator[] (size_t index) const {
				return	*(_ptr + index);
			}
			pointer	operator->() const {
				return _ptr;
			}
			reference	operator*() const {
				return *_ptr;
			}
			bool	operator==(const const_vec_iterator& other) const {
				return (_ptr == other._ptr);
			}
			bool	operator!=(const const_vec_iterator& other) const {
				return (_ptr != other._ptr);
			}
		private:
			pointer	_ptr;
		};
	/*
	** @brief: reversed iterator
	** increment iterators are reversed
	*/
	template<typename vector>
		class	rev_vec_iterator {
			typedef typename	vector::value_type		value_type;
			typedef typename	vector::reference		reference;
			typedef typename	vector::pointer			pointer;
		public:
								rev_vec_iterator(pointer ptr) : _ptr(ptr)			{ 												}
			rev_vec_iterator&	operator++()										{ _ptr--; return *this;							}
			rev_vec_iterator	operator++(int)										{ rev_vec_iterator ret = ++(*this); return ret;	}
			rev_vec_iterator&	operator--()										{ _ptr++; return *this;							}
			rev_vec_iterator	operator--(int)										{ rev_vec_iterator ret = --(*this); return ret;	}
			reference			operator[]	(size_t index)							{ return *(_ptr + index);						}
			pointer				operator->()										{ return _ptr;									}
			reference			operator*()											{ return *_ptr; 								}
			bool				operator==	(const rev_vec_iterator& other) const	{ return (_ptr == other._ptr);					}
			bool				operator!=	(const rev_vec_iterator& other) const	{ return (_ptr != other._ptr);					}
		private:
			pointer	_ptr;
		};
	
	/*
	** @brief: const reversed iterator
	** the same as reversed iterator. values in vector cant be changed.
	*/
	template<class vector>
		class	const_rev_vec_iterator {
		public:
			typedef typename	vector::value_type		value_type;
			typedef typename	vector::const_reference		reference;
			typedef typename	vector::pointer			pointer;
		public:
			const_rev_vec_iterator(pointer ptr) : _ptr(ptr) { };
			const_rev_vec_iterator(rev_vec_iterator<vector> it) : _ptr(&(it[0])) { };
			const_rev_vec_iterator& operator++() {
				_ptr--;
				return *this;
			}
			const_rev_vec_iterator operator++(int) {
				const_rev_vec_iterator	ret = ++(*this);
				return ret;
			}
			const_rev_vec_iterator& operator--() {
				_ptr++;
				return *this;
			}
			const_rev_vec_iterator operator--(int) {
				const_rev_vec_iterator	ret = --(*this);
				return ret;
			}
			reference operator[] (size_t index) const {
				return	*(_ptr + index);
			}
			pointer	operator->() const {
				return _ptr;
			}
			reference	operator*() const {
				return *_ptr;
			}
			bool	operator==(const const_rev_vec_iterator& other) const {
				return (_ptr == other._ptr);
			}
			bool	operator!=(const const_rev_vec_iterator& other) const {
				return (_ptr != other._ptr);
			}
		private:
			pointer	_ptr;
		};
} //end namepsace ft

#endif