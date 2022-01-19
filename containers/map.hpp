#ifndef MAP_HPP
# define MAP_HPP

#include <memory>
#include <string>
#include <iostream>
#include <cmath>
#include "../utils/pair.hpp"
#include <utility>
#include "../utils/red_black_tree.hpp"
#ifndef nullptr
# define nullptr NULL
#endif

namespace ft {

	template<
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<ft::pair<const Key, T> >
	> class map  {
		public:
			typedef					Key										key_type;
			typedef					T										mapped_type;
			typedef					ft::pair<const key_type, mapped_type>	value_type;
			typedef					Compare									key_compare;
			typedef					Allocator								allocator_type;
			typedef typename		allocator_type::reference				reference;
			typedef typename		allocator_type::const_reference			const_reference;
			typedef typename		allocator_type::pointer					pointer;
			typedef typename		allocator_type::const_pointer			const_pointer;
			typedef					ptrdiff_t								difference_type;
			typedef					size_t									size_type;

			class value_compare {
				friend class map;

				protected:
					key_compare	_comp;

					value_compare(Compare c) : _comp(c) { } //constructed with map's comparsion object
				public:
					typedef bool		result_type;
					typedef value_type	first_arguement_type;
					typedef value_type	second_arguement_type;
					bool operator() (value_type const &x, value_type const &y) const {
						return _comp(x.first, y.first);
					}
			};
		private:
			typedef				Tree<value_type, value_compare, allocator_type>					Tree;
		public:
			// typedef		binary_tree_iterator<const Node *, map, const value_type> 			const_iterator;
			// typedef		ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef typename	Tree::iterator													iterator;
			typedef typename	Tree::reverse_iterator											reverse_iterator;
			typedef typename	Tree::const_iterator											const_iterator;
			typedef typename	Tree::const_reverse_iterator									const_reverse_iterator;
		protected:
			Tree	_internal_tree;
		/** ---------- constructor(s) --------- **/
		public:
			explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) : _internal_tree(value_compare(comp), alloc) { }
			
			template <class InputIterator>
				map (InputIterator first, InputIterator last,
						const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _internal_tree(value_compare(comp), alloc) {
							for(; first  != last; first++) {
								_internal_tree.insert(*first);
							}
						}
			map (const map& x) : _internal_tree(x._internal_tree) {	}
			
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
			// bool	empty() const { return _internal_tree.empty(); }
			// size_type size() const { return _internal_tree.size(); }
			// size_type max_size() const { return internal_tree.max_size(); }

			/** --------- Element access --------- **/
			// mapped_type& operator[] (const key_type& k);

			/** --------- Modifiers --------- **/
			ft::pair<iterator,bool> insert (const value_type& val) {
				return(_internal_tree.insert(val));
			}
			iterator insert (iterator position, const value_type& val);
			template <class InputIterator>
				void insert (InputIterator first, InputIterator last);
			void erase (iterator position);
			size_type erase (const key_type& k);
			void erase (iterator first, iterator last);
			//void swap (map& x);
			void	clear() { _internal_tree.clear(); }

			/** --------- Observers --------- **/
			// key_compare	key_comp() const;
			// value_compare value_comp() const;


			/** --------- Operations --------- **/
			// iterator find (const key_type& k);
			// const_iterator find (const key_type& k) const;
			// size_type count (const key_type& k) const;
			// iterator lower_bound (const key_type& k);
			// const_iterator lower_bound (const key_type& k) const;
			// iterator upper_bound (const key_type& k);
			// const_iterator upper_bound (const key_type& k) const;

			/** --------- Allocator --------- **/
			// allocator_type get_allocator() const;

			/** --------- Destructor --------- **/
			~map() { }
	};
}

#endif