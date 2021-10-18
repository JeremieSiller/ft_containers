#ifndef STACK_HPP
# define STACK_HPP

#pragma once

#include <memory>
#include <vector>

namespace ft
{
	template <
		class T,
		class _Container = std::vector<T> // change to ft!
	> class stack
	{
	/* ----- typdefs ----- */
	public: 
		typedef	_Container									container_type;
		typedef typename container_type::value_type			value_type;
		typedef typename container_type::reference			reference;
		typedef typename container_type::const_reference	const_reference;
		typedef typename container_type::size_type			size_type;
	protected:
		container_type	c;
	/* ----- public memmber function ----- */
	public:
		/* ----- Constructors ----- */
		stack() : c() {}; //real stack throws exception if c is non constructable
		stack(const stack &_s) : c(_s.c) { };
		//stack(container_type const &_c) : c(_c) { };
		explicit stack(const container_type& _c) : c(_c) { }; //explicit ?
		// also has allocator construction (not there yet!);
		/* ----- Deconstructor ----- */
		~stack() {};

		/* ----- get functions ----- */
		bool 			empty() const {return(c.empty());};
		size_type		size()  const {return(c.size());};
		reference		top()         {return(c.back());};
		const_reference	top()   const {return(c.back());};

		/* ----- change functions ----- */
		void			push(const value_type& _v) {c.push_back(_v);};
		void			pop(){c.pop_back();};

		/* ----- Operators ----- */
		stack& operator=(const stack& _s) {c = _s.c; return *this;};
	};
	/* ---- non member operators ----- */
	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return(lhs.c == rhs.c);};

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return(lhs.c != rhs.c);};

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return(lhs.c > rhs.c);};

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return(lhs.c >= rhs.c);};

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return(lhs.c < rhs.c);};

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return(lhs.c <= rhs.c);};
}



//STACK_HPP
#endif