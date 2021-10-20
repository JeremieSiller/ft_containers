#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <stack>
#include <iterator>
#include <iostream>
#include <string.h>

namespace ft {
	template<
	    class T,
	    class Allocator = std::allocator<T>
	> class vector 
	{
	/* ---- Member types ----- */
	public:
		typedef 			T								value_type;
		typedef 			Allocator						allocator_type;
		typedef typename	allocator_type::reference		reference;
		typedef typename	allocator_type::const_reference	const_reference;
		typedef typename	allocator_type::pointer			pointer;
		typedef typename	allocator_type::const_pointer	const_pointer;
		// iterators missing
		typedef typename	allocator_type::size_type		size_type;
	/* ----- attributes ----- */
	private:
		size_type		_size;
		size_type		_capacity;
		value_type		*_data;
		allocator_type	a;
	/* ----- Constructors ---- */
	public:
		explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _data(NULL), a() { };

		explicit vector (size_type n, const value_type& val = value_type(),
						 const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n) {
							_data = a.allocate(n);
							memset(_data, 0, sizeof(value_type) * n);
						 };			

		// template <class InputIterator>
		// 	vector (InputIterator first, InputIterator last,
		// 			const allocator_type& alloc = allocator_type());

		vector (const vector& x) : _size(x._size), _capacity(x._capacity), a(x.a) { 
			_data = a.allocate(_capacity);
			memcpy(_data, x._data, _size * sizeof(value_type));
		}
	/* ----- Deconstructor ----- */
	~vector() {a.deallocate(_data, _capacity);}
	/* ----- Public member functions ---- */
	public:
		/* --- iterators --- */
		// iterator				begin()				;
		// const_iterator			begin()		const	;
		// iterator				end()				;
		// const_iterator			end()		const	;
		// reverse_iterator		rbegin()			;
		// const_reverse_iterator	rbegin()	const	;
		// reverse_iterator		rend()				;
		// const_reverse_iterator	rend()		const	;

		/* --- capacity --- */
		size_type	size ()													const {return (_size);}
		size_type	max_size ()												const {return (a.max_size());}
		void		resize (size_type n, value_type val = value_type());
		size_type	capacity ()												const {return (_capacity);};
		void		reserve (size_type n);

		/* --- Element acces --- */
		reference			operator[] (size_type n)			{ return _data[n]; };
		const_reference		operator[] (size_type n)	const	{ return _data[n]; };
		reference			at (size_type n)					{ return _data[n]; };
		const_reference		at (size_type n)			const	{ return _data[n]; };
		reference			front ( )							{ return _data[0]; };
		const_reference		front ( )					const	{ return _data[0]; };

		/* --- modifiers -- */
		template <class InputIterator>
			void		assign (InputIterator first, InputIterator last);
		void			assign (size_type n, const value_type& val);
		void			push_back (const value_type& val);
		void			pop_back ();
		// iterator		insert (iterator position, const value_type& val);
	    // void			insert (iterator position, size_type n, const value_type& val);
		// template <class InputIterator>
	    // 	void		insert (iterator position, InputIterator first, InputIterator last);
		// iterator		erase (iterator position);
		// iterator		erase (iterator first, iterator last);
		void			swap (vector& x);
		void			clear();
		allocator_type	get_allocator() const;
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