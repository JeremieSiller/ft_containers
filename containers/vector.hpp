#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <stdexcept>
#include <utility>
#include "../utils/iterator.hpp"
#include "../utils/utils.hpp"
#include "../utils/sfinae.hpp"


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
		typedef				ft::random_access_iterator<value_type, vector>			iterator;
		typedef				ft::random_access_iterator<const value_type, vector>	const_iterator;
		typedef 			ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		typedef 			ft::reverse_iterator<iterator>							reverse_iterator;
		typedef typename	allocator_type::size_type								size_type;
	/* ----- attributes ----- */
	private:
		size_type		_capacity;
		pointer			_start;
		pointer			_end;
		allocator_type	_a;
	/* ---- Private member funtcions (helper) ---- */
	private:
		void	_destroy(pointer p_start, pointer p_end) {
			while (p_start != p_end)
			{
				_a.destroy(p_start);
				p_start++;
			}
		}
	/* ----- Public member functions ---- */
	public:
		/* --- Constructors --- */
		explicit vector (const allocator_type& alloc = allocator_type()) : 
			_capacity(), _start(), _end(), _a(alloc) { }

		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
			_capacity(n), _start(), _end(), _a(alloc) {
				_end = _a.allocate(n);
				_start = _end;
				for (size_t i = 0; i < n; i++)
				{
					_a.construct(_end, val);
					_end++;
				}
			}
		template <typename InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true) :
			_capacity(), _start(), _end(), _a(alloc) {
				reserve(ft::distance(first, last));
				_end = _start + ft::distance(first, last);
				ft::copy(first, last, iterator(_start));
		}

		vector (const vector& x) :
			_capacity(x._capacity), _start(), _end(), _a(x._a) {
				_end = _a.allocate(_capacity);
				_start = _end;
				for (size_t i = 0; i < x.size(); i++)
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
		reverse_iterator		rbegin()			{ return reverse_iterator(end());			};
		reverse_iterator		rend()				{ return reverse_iterator(begin());			};
		const_reverse_iterator	rbegin()	const	{ return const_reverse_iterator(end());		};
		const_reverse_iterator	rend()		const	{ return const_reverse_iterator(begin());	};

		/* --- size and capacity --- */
		size_type	size ()													const	{ return _end - _start; }
		size_type	max_size ()												const	{ return _a.max_size(); }
		size_type	capacity ()												const	{ return _capacity; }
		
		/* --- changing size and capacity --- */
		void		reserve (size_type n) {
			if (n > max_size())
				throw std::length_error("vector");
			if (n > _capacity)
			{
				pointer	new_start, new_end;

				new_start = _a.allocate(n);
				new_end = new_start + size();
				ft::copy(iterator(_start), iterator(_end), new_start);
				clear();
				_a.deallocate(_start, size());
				_start = new_start;
				_end = new_end;
				_capacity = n;
			}
		}
		void		resize (size_type n, value_type val = value_type()) {
			if (n > max_size())
				throw std::length_error("vector");
			if (n < size())
			{
				_destroy(_start + n, _end);
				_end = _start + n;
			}
			else if (n > size())
			{
				if (n > _capacity)
				{
					if (n <= _capacity * 2)
						reserve(_capacity * 2);
					else
						reserve(n);
				}
				for (size_t i = size(); i < n; i++)
				{
					_a.construct(_end, val);
					_end++;
				}
			}
		}

		/* --- Element acces --- */
		reference			operator[] (size_type n)								{ return *(_start + n); }
		const_reference		operator[] (size_type n)						const	{ return *(_start + n); }

		reference			at (size_type n) {
			if (n >= size() || n < 0)
				throw std::out_of_range("vector");
			return *(_start + n); 
		}
		const_reference			at (size_type n) const {
			if (n >= size() || n < 0)
				throw std::out_of_range("vector");
			return *(_start + n); 
		}
		reference			front ()												{ return *_start; }
		const_reference		front ()										const	{ return *_start; }
		reference			back ()													{ return *(_end - 1); }
		const_reference		back ()											const	{ return *(_end - 1); }

		bool				empty()											const	{ return !size(); }

		allocator_type	get_allocator() const										{ return _a;} ;
		/* --- modifiers -- */
		template <class InputIterator>
			void		assign (InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true) {
				if (static_cast<size_type>(ft::distance(first, last)) > max_size())
					throw std::length_error("vector");
				size_t	i;
				for (i = 0; i < size() && first != last; i++, first++)
				{
					_a.destroy(_start + i);
					_a.construct(_start + i, *first);
				}
				if (i < size())
				{
					_end = _start + i;
					for (; i < size(); i++)
					{
						_a.destroy(_start + i);
					}
				}
				if (first != last)
				{
					reserve(ft::distance(first, last) + i);
					while (first != last)
					{
						_a.construct(_end, *first);
						_end++;
						first++;
					}
				}
			}

		void			assign (size_type n, value_type const & val) {
			if (n > max_size())
				throw (std::length_error("vector"));
			size_t	i;
			for (i = 0; i < n && i < size(); i++)
			{
				_a.destroy(_start + i);
				_a.construct(_start + i, val);
			}
			resize(n, val);
		}
		void			push_back (const value_type& val) {
			resize(size() + 1, val);
		}
		void			pop_back () {
			_end--;
			_a.destroy(_end);
		}

		iterator		insert (iterator position, const value_type& val) {
			size_t	d = ft::distance(begin(), position);
			insert(position, 1, val);
			return(iterator(_start + d));
		}

		void			insert (iterator position, size_type n, const value_type& val) {
			if (n > max_size() || size() + n > max_size())
				throw std::length_error("vector");
			size_type	dist = ft::distance(begin(), position);
			size_type	old_end = size();
			resize(size() + n);
			ft::backward_copy(begin() + dist, begin() + old_end, begin() + dist + n);
			ft::fill(begin() + dist, begin() + dist + n, val);
		};
		template <class InputIterator>
			void		insert (iterator position, InputIterator first, InputIterator last,
				typename std::enable_if<!std::is_integral<InputIterator>::value, bool>::type = true) {
				size_type n = ft::distance(first, last);
				if (n > max_size() || size() + n > max_size())
					throw std::length_error("vector");
				size_type dist = ft::distance(begin(), position);
				size_type old_end = size();
				resize(size() + n);
				ft::backward_copy(begin() + dist, begin() + old_end, begin() + dist + n);
				for (size_t i = 0; i < n; i++)
				{
					*(_start + dist + i) = *first;
					first++;
				}
			}
		iterator		erase (iterator position) {
			return(erase(position, position + 1));
		}
		iterator		erase (iterator first, iterator last) {
			iterator i = ft::copy(last, end(), first);
			pointer p = _start + (i - begin());
			for (; p != _end; p++) {
				_a.destroy(p);
			}
			_end -= ft::distance(first, last);
			return first;
		}
		void			swap (vector& x) {
			pointer		tmp_pointer = _end;
			size_type	tmp_size = _capacity;
			_end = x._end;
			x._end = tmp_pointer;
			tmp_pointer = _start;
			_start = x._start;
			x._start = tmp_pointer;
			_capacity = x._capacity;
			x._capacity = tmp_size;
		}

		void			clear()	{
			_destroy(_start, _end);
			_end = _start;
		};
		vector& operator= (const vector& x) {
			reserve(x.size());
			ft::copy(x.begin(), x.end(), begin());
			_end = _start + x.size();
			return *this;
		}
	};
	/* ----- relational operators ----- */
	template <class T, class Alloc>
		bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			if (lhs.size() != rhs.size())
				return false;
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}
	template <class T, class Alloc>
			bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
				return (!(lhs == rhs));
			}
	template <class T, class Alloc>
		bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}
	template <class T, class Alloc>
			bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
				return !(rhs < lhs);
			}
	template <class T, class Alloc>
			bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
				return (rhs < lhs);
			}
	template <class T, class Alloc>
		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
				return !(rhs > lhs);
		}
	/* ---- functions ----- */
	template <class T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
			x.swap(y);
		}
}
#endif