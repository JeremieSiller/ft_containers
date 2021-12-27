#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <stack>
#include <iterator>
#include <iostream>
#include <string.h>
#include <vector>
#include <bits/cpp_type_traits.h>
#include <bits/stl_iterator_base_funcs.h>
#include <stdexcept>
// #include <type_traits>


namespace ft {
	template<
	    class T,
	    class Allocator = std::allocator<T>
	> class vector
	{
	/* ---- Member types ----- */
	public:
		typedef 			T														value_type;
		typedef 			Allocator												allocator_type;
		typedef typename	allocator_type::reference								reference;
		typedef typename	allocator_type::const_reference							const_reference;
		typedef typename	allocator_type::pointer									pointer;
		typedef typename	allocator_type::const_pointer							const_pointer;
		typedef 			__gnu_cxx::__normal_iterator<pointer, vector>			iterator;
		typedef 			__gnu_cxx::__normal_iterator<const_pointer, vector>		const_iterator;
		typedef 			std::reverse_iterator<const_iterator>					const_reverse_iterator;
		typedef 			std::reverse_iterator<iterator>							reverse_iterator;
		typedef typename	allocator_type::size_type								size_type;
	/* ----- attributes ----- */
	private:
		size_type		_size;
		size_type		_capacity;
		pointer			_start;
		pointer			_end;
		allocator_type	_a;
	/* ----- Public member functions ---- */
	public:
		/* --- Constructors --- */
		explicit vector (const allocator_type& alloc = allocator_type()) : 
			_size(), _capacity(), _start(), _end(), _a(alloc) { }

		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
			_size(n), _capacity(n), _start(), _end(), _a(alloc) {
				_end = _a.allocate(n);
				_start = _end;
				for (size_t i = 0; i < n; i++)
				{
					_a.construct(_end, val);
					_end++;
				}
			}
		// template <typename InputIterator >
		// 	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

		vector (const vector& x) :
			_size(x._size), _capacity(x._capacity), _start(), _end(), _a(x._a) {
				_end = _a.allocate(_capacity);
				_start = _end;
				for (size_t i = 0; i < x._size; i++)
				{
					_a.construct(_end, x[i]);
					_end++;
				}
			}

		/* --- Deconstructor --- */
		~vector() {
			clear();
			_a.deallocate(_start, _capacity);
		}

		/* --- iterators --- */
		iterator				begin() 			{ return iterator(_start);					};
		iterator				end()				{ return iterator(_end);					};
		const_iterator			begin()		const	{ return const_iterator(_start);			};
		const_iterator			end()		const	{ return const_iterator(_end);				};
		reverse_iterator		rbegin()			{ return reverse_iterator(_start);			};
		reverse_iterator		rend()				{ return reverse_iterator(_end);			};
		const_reverse_iterator	rbegin()	const	{ return const_reverse_iterator(_start);	};
		const_reverse_iterator	rend()		const	{ return const_reverse_iterator(_end);		};

		/* --- size and capacity --- */
		size_type	size ()													const	{ return _size; }
		size_type	max_size ()												const	{ return _a.max_size(); }
		size_type	capacity ()												const	{ return _capacity; }
		
		/* --- changing size and capacity --- */
		void		reserve (size_type n) {
			if (n > _capacity)
			{
				size_t	tmp_size = _size;
				pointer	end;
				pointer	tmp;
				end = _a.allocate(n);
				tmp = end;
				for (size_t i = 0; i < _size; i++)
				{
					_a.construct(end, _start[i]);
					end++;
				}
				clear();
				_size = tmp_size;
				_a.deallocate(_start, _capacity);
				_start = tmp;
				_end = end;
				_capacity = n;
			}
		}
		void		resize (size_type n, value_type val = value_type()) {
			if (n > max_size())
				throw std::length_error("vector");
			if (n < _size)
			{
				for (size_t i = n; i < _size; i++)
				{
					_a.destroy(_start + i);
				}
				_end = _start + n;
				_size = n;
			}
			else if (n > _size)
			{
				if (n > _capacity)
				{
					reserve(_capacity * 2);
					if (n > _capacity)
						reserve(n);
				}
				for (size_t i = _size; i < n; i++)
				{
					_a.construct(_end, val);
					_end++;
				}
				_size = n;
			}
		}

		/* --- Element acces --- */
		reference			operator[] (size_type n)								{ return *(_start + n); }
		const_reference		operator[] (size_type n)						const	{ return *(_start + n); }

		reference			at (size_type n) {
			if (n >= _size || n < 0)
				throw std::out_of_range("vector");
			return *(_start + n); 
		}
		const_reference			at (size_type n) const {
			if (n >= _size || n < 0)
				throw std::out_of_range("vector");
			return *(_start + n); 
		}
		reference			front ()												{ return *_start; }
		const_reference		front ()										const	{ return *_start; };

		allocator_type	get_allocator() const												;
		/* --- modifiers -- */
		template <class InputIterator>
			void		assign (InputIterator first, InputIterator last)					;
		void			assign (size_type n, value_type const & val)						;
		void			push_back (const value_type& val)									;
		void			pop_back ()															;
		iterator		insert (iterator position, const value_type& val)					;
		void			insert (iterator position, size_type n, const value_type& val)		;
		template <class InputIterator>
			void		insert (iterator position, InputIterator first, InputIterator last)	;
		iterator		erase (iterator position)											;
		iterator		erase (iterator first, iterator last)								;
		void			swap (vector& x)													;

		void			clear()	{
			for (size_t i = 0; i < _size; i++)
			{
				_a.destroy(_start + i);
			}
			_end = _start;
			_size = 0;
		};
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