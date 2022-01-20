#ifndef STACK_HPP
# define STACK_HPP

#pragma once

#include "vector.hpp"

namespace ft
{
	template <
		class T,
		class _Container = ft::vector<T>
	> class stack
	{
	/* ----- typdefs ----- */
	public: 
		typedef	_Container									container_type;
		typedef typename container_type::value_type			value_type;
		typedef typename container_type::size_type			size_type;
	/* ----- attributes ----- */
	protected:
		container_type	_c;
	/* ----- public memmber function ----- */
	public:
		/* ----- Constructors ----- */
		explicit stack(const container_type& c = container_type()) : _c(c) { };

		/* ----- Deconstructor ----- */
		~stack() { _c.clear(); };

		/* ----- get functions ----- */
		bool 				empty() const {return(_c.empty());};
		size_type			size()  const {return(_c.size());};
		value_type&			top()         {return(_c.back());};
		const value_type&	top()   const {return(_c.back());};

		/* ----- change functions ----- */
		void			push(const value_type& _v) {_c.push_back(_v);};
		void			pop(){_c.pop_back();};
		/* ----- friend declarations ----- */
		template <class TN, class ContainerN>
			friend bool operator== (const stack<TN,ContainerN>& lhs, const stack<TN,ContainerN>& rhs);
		template <class TN, class ContainerN>
			friend bool operator!= (const stack<TN,ContainerN>& lhs, const stack<TN,ContainerN>& rhs);
		template <class TN, class ContainerN>
			friend bool operator<  (const stack<TN,ContainerN>& lhs, const stack<TN,ContainerN>& rhs);
		template <class TN, class ContainerN>
			friend bool operator<= (const stack<TN,ContainerN>& lhs, const stack<TN,ContainerN>& rhs);
		template <class TN, class ContainerN>
			friend bool operator>  (const stack<TN,ContainerN>& lhs, const stack<TN,ContainerN>& rhs);
		template <class TN, class ContainerN>
			friend bool operator>= (const stack<TN,ContainerN>& lhs, const stack<TN,ContainerN>& rhs);
	};
	/* ---- non member operators ----- */
	template <class T, class Container>
		bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return(lhs._c == rhs._c);};

	template <class T, class Container>
		bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return(lhs._c != rhs._c);};

	template <class T, class Container>
		bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return(lhs._c < rhs._c);};

	template <class T, class Container>
		bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return(lhs._c <= rhs._c);};

	template <class T, class Container>
		bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return(lhs._c > rhs._c);};

	template <class T, class Container>
		bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return(lhs._c >= rhs._c);};
}



//STACK_HPP
#endif