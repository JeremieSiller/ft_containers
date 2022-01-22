#ifndef SET_HPP
# define SET_HPP

# pragma once

#include <utility>
#include <memory>
#include "../utils/pair.hpp"
#include "../utils/utils.hpp"
#include "../utils/red_black_tree.hpp"

namespace ft{

	template <	class T,								// set::key_type/value_type
				class Compare = std::less<T>,			// set::key_compare/value_compare
				class Alloc = std::allocator<T>			// set::allocator_type
				> class set {
				/** -------- typedefs ------- **/
				public:
					typedef					T												key_type;
					typedef					T												value_type;
					typedef					Compare											key_compare;
					typedef					Compare											value_compare;
					typedef					Alloc											allocator_type;
					typedef typename		allocator_type::reference						reference;
					typedef typename		allocator_type::const_reference					const_reference;
					typedef typename		allocator_type::pointer							pointer;
					typedef typename		allocator_type::const_pointer					const_pointer;
					typedef					size_t											size_type;
				private:
					typedef					Tree<value_type, value_compare, allocator_type>	Tree;
				public:
					typedef typename	Tree::const_iterator											iterator;
					typedef typename	Tree::const_reverse_iterator									reverse_iterator;
					typedef typename	Tree::const_iterator											const_iterator;
					typedef typename	Tree::const_reverse_iterator									const_reverse_iterator;
					typedef typename	ft::iterator_traits<iterator>::difference_type					difference_type;

				/** -------- member attributes ------- **/
				protected:
					Tree	_internal_tree;
				/** -------- constructor(s) ------- **/
				public:
				explicit set (const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()) : _internal_tree(value_compare(comp), alloc) { }
			
				template <class InputIterator>
					set (InputIterator first, InputIterator last,
						const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _internal_tree(value_compare(comp), alloc) {
							for(; first  != last; first++) {
								_internal_tree.insert(*first);
							}
						}
				set (const set& x) : _internal_tree(x._internal_tree) { }

				/** --------- Iterators --------- **/
				iterator				begin()				{ return _internal_tree.begin(); }
				const_iterator			begin()		const	{ return _internal_tree.begin(); };
				iterator				end()				{ return _internal_tree.end(); }
				const_iterator			end()		const	{ return _internal_tree.end(); }
				reverse_iterator		rbegin() 			{ return _internal_tree.rbegin(); }
				const_reverse_iterator	rbegin()	const	{ return _internal_tree.rbegin(); }
				reverse_iterator		rend()				{ return _internal_tree.rend(); }
				const_reverse_iterator	rend()		const	{ return _internal_tree.rend(); }

				/** --------- Capacity --------- **/
				bool		empty()		const	{ return _internal_tree.empty(); }
				size_type	size()		const	{ return _internal_tree.size(); }
				size_type	max_size()	const	{ return _internal_tree.max_size(); }

				/** --------- Modifiers --------- **/
				ft::pair<iterator,bool>	insert (const value_type& val) 						{ return(_internal_tree.insert(val)); }
				iterator				insert (iterator position, const value_type& val)	{ return _internal_tree.insert(_internal_tree.begin(), val); (void)position; }
				template <class InputIterator>
					void				insert (InputIterator first, InputIterator last)	{ _internal_tree.insert(first, last); }

				void					erase (iterator position)							{ _internal_tree.erase(*position); }
				size_type				erase (const value_type& val)						{ return (_internal_tree.erase(val)); }
				void					erase (iterator first, iterator last)				{ 
					while (first != last) {
						_internal_tree.erase(*first++);
					}
				}

				void					swap (set& x)										{ _internal_tree.swap(x._internal_tree); }
				void					clear()												{ _internal_tree.clear(); }
				/** --------- Observers --------- **/
				value_compare	value_comp()	const	{ return _internal_tree.value_comp(); };
				key_compare		key_comp()		const	{ return _internal_tree.value_comp(); };
				/** --------- Operations --------- **/
				iterator					find (const value_type& val)		const	{ return _internal_tree.find(val); }
				size_type					count (const value_type& val)		const	{ return _internal_tree.count(val); }
				iterator					lower_bound (const value_type& val)	const	{ return iterator(_internal_tree.lower_bound(val).base()); }
				iterator					upper_bound (const value_type& val)	const	{ return iterator(_internal_tree.upper_bound(val).base()); }
				ft::pair<iterator,iterator>	equal_range (const value_type& val) const	{ return _internal_tree.equal_range(val); }

				/** --------- Allocator --------- **/
				allocator_type get_allocator() const { return _internal_tree.get_allocator(); }

				/** --------- assignment --------- **/
				set	&operator=(const set &other) {
					_internal_tree = other._internal_tree;
					return *this;
				}

				/** --------- Destructor --------- **/
				~set() { }
			};
			template<class T, class Compare, class Alloc>
				void swap (set<T, Compare, Alloc>& x, set<T, Compare, Alloc>& y) {
					x.swap(y);
				}

			template<class T, class Compare, class Alloc >
				bool operator==( const ft::set<T, Compare, Alloc>& lhs, const ft::set<T, Compare, Alloc>& rhs ) {
					if (lhs.size() != rhs.size())
						return false;
					return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
				}

			template<class T, class Compare, class Alloc >
				bool operator!=( const ft::set<T, Compare, Alloc>& lhs, const ft::set<T, Compare, Alloc>& rhs ) {
					return !(lhs == rhs);
				}
			template<class T, class Compare, class Alloc >
				bool operator<( const ft::set<T, Compare, Alloc>& lhs, const ft::set<T, Compare, Alloc>& rhs ) {
					return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
				}

			template<class T, class Compare, class Alloc >
				bool operator<=( const ft::set<T, Compare, Alloc>& lhs, const ft::set<T, Compare, Alloc>& rhs ) {
					return !(rhs < lhs);
				}

			template<class T, class Compare, class Alloc >
				bool operator>( const ft::set<T, Compare, Alloc>& lhs, const ft::set<T, Compare, Alloc>& rhs ) {
					return rhs < lhs;
				}

			template<class T, class Compare, class Alloc >
				bool operator>=( const ft::set<T, Compare, Alloc>& lhs, const ft::set<T, Compare, Alloc>& rhs ) {
					return !(rhs > lhs);
				}
}


#endif