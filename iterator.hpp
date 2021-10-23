#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft {
	template<typename pointer>
		class	vec_iterator {
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
				++(*this);
				return ret;
			}
			&(*pointer) operator[] () {
				return	*(_ptr + index);
			}
			pointer	opeartor->() {
				return _ptr;
			}
			&(*pointer	)opeartor*() {
				return *_ptr;
			}
			bool	operator!=(const vec_iterator& other) const {
				return (_ptr != other._ptr);
			}
		private:
			pointer	_ptr;
		};
	template<typename T>
		class	reverse_iterator {

		};
	// template<class Iterator>
// struct iterator_traits
// {
//     typedef typename Iterator::difference_type difference_type;
//     typedef typename Iterator::value_type value_type;
//     typedef typename Iterator::pointer pointer;
//     typedef typename Iterator::reference reference;
//     typedef typename Iterator::iterator_category iterator_category;
// }; 
}

#endif