#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <stack>
#include <iterator>
#include <iostream>
#include <string.h>
#include <vector>
#include "iterator.hpp"
#include <bits/cpp_type_traits.h>
// #include <type_traits>


namespace ft {
	template<
	    class T,
	    class Allocator = std::allocator<T>
	> class vector 
	{
	/* ---- Member types ----- */
	public:
		typedef 			T											value_type;
		typedef 			Allocator									allocator_type;
		typedef typename	allocator_type::reference					reference;
		typedef typename	allocator_type::const_reference				const_reference;
		typedef typename	allocator_type::pointer						pointer;
		typedef typename	allocator_type::const_pointer				const_pointer;
		typedef 			ft::vec_iterator<vector<T> >				iterator;
		typedef 			ft::const_vec_iterator<vector<T> >			const_iterator;
		typedef				ft::rev_vec_iterator<vector<T> >			reverse_iterator;
		typedef				ft::const_rev_vec_iterator<vector<T> >		const_reverse_iterator;
		typedef typename	allocator_type::size_type					size_type;
	/* ----- attributes ----- */
	private:
		size_type		_size;
		size_type		_capacity;
		pointer			_data;
		allocator_type	a;
	/* ----- Constructors ---- */
	public:
		explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _data(NULL), a(alloc) { };

		explicit vector (size_type n, const value_type& val = value_type(),
						 const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), a(alloc) {
							_data = a.allocate(n);
							for (size_type i = 0; i < _size; i++)
							{
								a.construct(_data + i, val);
							}
						 };			

		template <typename InputIterator >
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type()) : _size(last - first), _capacity(last - first), _data(NULL), a(alloc){
						typedef typename std::__is_integer<InputIterator>::__type _Integral;
						_M_initialize_dispatch(first, last, _Integral());
						// _data = a.allocate(_capacity);
						// for (size_t i = 0; first != last; i++, first++)
						// {
						// 	a.construct(_data + i, *(first));
						// }
					};

		vector (const vector& x) : _size(x._size), _capacity(x._capacity), a(x.a) { 
			_data = a.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
			{
				a.construct(_data + i, value_type());
			}
		}
	/* ----- Deconstructor ----- */
		~vector() {
			if (_capacity > 0) {
				clear();
				a.deallocate(_data, _capacity);
			}
		}
	/* ----- Public member functions ---- */
	public:
		/* --- iterators --- */
		const_iterator			begin()		const	{ return const_iterator(_data);							};
		const_iterator			end()		const	{ return const_iterator(_data + _size);					};
		iterator				begin() 			{ return iterator(_data); 								};
		iterator				end()				{ return iterator(_data + _size);						};
		reverse_iterator		rbegin()			{ return reverse_iterator(_data + (_size - 1));			};
		const_reverse_iterator	rbegin()	const	{ return const_reverse_iterator(_data + (_size - 1));	};
		reverse_iterator		rend()				{ return reverse_iterator(_data - 1);					};
		const_reverse_iterator	rend()		const	{ return const_reverse_iterator(_data - 1);				};

		/* --- capacity --- */
		size_type	size ()													const {return (_size);}
		size_type	max_size ()												const {return (a.max_size());}
		size_type	capacity ()												const {return (_capacity);};
		void		reserve (size_type n) {
			pointer	tmp;
			if (n > max_size())
				throw std::length_error("vector::reserve");
			if (n > _capacity)
			{
				tmp = a.allocate(n);
				for (size_type i = 0; i < _size; i++)
				{
					a.construct(tmp + i, _data[i]);
					a.destroy(_data + i);
				}
				a.deallocate(_data, _capacity);
				_data = tmp;
				_capacity = n;
			}
		}
		void		resize (size_type n, value_type val = value_type()) {
			if (n > _size)
			{
				if (n > _capacity)
					reserve(n);
				for ( ; _size < n; _size++)
				{
					a.construct(_data + _size , val);
				}
			}
			else
			{
				for ( ; _size > n; _size--)
				{
					a.destroy(_data + _size);
				}
			}
		};

		/* --- Element acces --- */
		reference			operator[] (size_type n)			{ return _data[n]; }
		const_reference		operator[] (size_type n)	const	{ return _data[n]; }
		reference			at (size_type n)					{ return _data[n]; }
		const_reference		at (size_type n)			const	{ return _data[n]; }
		reference			front ( )							{ return _data[0]; }
		const_reference		front ( )					const	{ return _data[0]; }

		/* --- modifiers -- */
		// template <class InputIterator>
		// 	void		assign (InputIterator first, InputIterator last);
		// void			assign (size_type n, value_type const & val) {
		// 	if (n < _capacity)
		// 	{
		// 		_data[n]
		// 	}
		// 	else
		// 		memset(_data, val, sizeof(value_type) * n);
		// }
		void			push_back (const value_type& val) {
			if (_size + 1 > _capacity)
			{
				_capacity *= 2;
				T	*tmp;
				tmp = a.allocate(_capacity);
				memcpy(tmp, _data, _size);
				a.deallocate(_data, _capacity / 2);
				_data = tmp;
			}
			_data[_size++] = val;
		};
		void			pop_back ();
		// iterator		insert (iterator position, const value_type& val);
	    // void			insert (iterator position, size_type n, const value_type& val);
		// template <class InputIterator>
	    // 	void		insert (iterator position, InputIterator first, InputIterator last);
		// iterator		erase (iterator position);
		// iterator		erase (iterator first, iterator last);
		void			swap (vector& x);
		void			clear() {
			for (size_type i = 0; i < _size; i++)
				a.destroy(&(_data[i]));
			_size = 0;
		};
		allocator_type	get_allocator() const { return a; };
	};
	/* ----- relational operators ----- */
	template <class T, class Alloc>
		bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
			bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
		bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
			bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
			bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	/* ---- functions ----- */
	template <class T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
}
#endif