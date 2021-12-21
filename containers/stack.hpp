#ifndef STACK_HPP
# define STACK_HPP

#pragma once

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
		typedef typename container_type::size_type			size_type;
	/* ----- attributes ----- */
	protected:
		container_type	c;
	/* ----- public memmber function ----- */
	public:
		/* ----- Constructors ----- */
		explicit stack(const container_type& _c = container_type()) { }; //explicit ?

		/* ----- Deconstructor ----- */
		~stack() {};

		/* ----- get functions ----- */
		bool 				empty() const {return(c.empty());};
		size_type			size()  const {return(c.size());};
		value_type&			top()         {return(c.back());};
		const value_type&	top()   const {return(c.back());};

		/* ----- change functions ----- */
		void			push(const value_type& _v) {c.push_back(_v);};
		void			pop(){c.pop_back();};
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