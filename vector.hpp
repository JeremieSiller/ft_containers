#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <vector>
#include <iterator>

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
		size_type	_size;
	/* ----- Constructors ---- */
	public:
		explicit vector (const allocator_type& alloc = allocator_type());

		explicit vector (size_type n, const value_type& val = value_type(),
						 const allocator_type& alloc = allocator_type());

		template <class InputIterator>
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type());

		vector (const vector& x);
	/* ----- Public member functions ---- */
	public:
		/* --- capacity --- */
		size_type	size ()													const;
		size_type	max_size ()												const;
		void		resize (size_type n, value_type val = value_type());
		size_type	capacity ()												const;
		void		reserve (size_type n);
		/* --- Element acces --- */
		reference			operator[] (size_type n);
		const_reference		operator[] (size_type n) const;
		reference			at (size_type n);
		const_reference		at (size_type n) const;
		reference			front (size_type n);
		const_reference		front (size_type n) const;
		/* --- modifiers -- */
		template <class InputIterator>
			void		assign (InputIterator first, InputIterator last);
		void			assign (size_type n, const value_type& val);
		void			push_back (const value_type& val);
		void			pop_back ();
		iterator		insert (iterator position, const value_type& val);
	    void			insert (iterator position, size_type n, const value_type& val);
		template <class InputIterator>
	    	void		insert (iterator position, InputIterator first, InputIterator last);
		iterator		erase (iterator position);
		iterator		erase (iterator first, iterator last);
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