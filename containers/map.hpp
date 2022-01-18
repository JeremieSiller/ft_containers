#ifndef MAP_HPP
# define MAP_HPP

#include <memory>
#include <string>
#include <iostream>
#include <cmath>
#include "../utils/utils.hpp"
#include "../utils/pair.hpp"
#include "../utils/node_iterator.hpp"
#include "../utils/iterator.hpp"
#include <utility>
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
		public:
			struct Node
			{
				value_type	value;
				Node		*parent;
				Node		*left;
				Node		*right;
				bool		is_end;
				bool		colour;
			public:
				Node(bool _end) : value(), parent(nullptr), left(nullptr), right(nullptr), is_end(_end) { }
				Node(const_reference val=value_type()) :
					value(val) , parent(nullptr), left(nullptr), right(nullptr), is_end(false) { }
				Node(Node const &in) : value(in.value), parent(in.parent), left(in.left), right(in.right), is_end(in.is_end) { }
				~Node() {	}
			};
			typedef		binary_tree_iterator<Node *, map, value_type>					iterator;
			typedef		binary_tree_iterator<const Node *, map, const value_type> 			const_iterator;
			typedef		ft::reverse_iterator<iterator>							reverse_iterator;
			typedef		ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		private:
			typedef typename Allocator::template rebind<Node>::other	node_allocator;
			Node					*_parent;
			Node					*_last;
			allocator_type			_a;
			node_allocator			_na;
			value_compare			_cmp;
			key_compare				_keycmp;
		private:
			/*
			** checks if first and second are equal
			** if !_cmp(a, b) && !_cmpp(b, a) -> a == b
			*/
			bool	_equals(value_type const &first, value_type const &second) const {
				return (!_cmp(first, second) && !_cmp(second, first));
			}

			bool	_equals(key_type const &first, key_type const &second) const {
				return (!_keycmp(first, second) && !_keycmp(second, first));
			}

			Node	*createNode(const_reference val)
			{
				Node	*ret = _na.allocate(1);
				_na.construct(ret, val);
				return ret;
			}

			Node	*createEnd()
			{
				Node *ret = _na.allocate(1);
				_na.construct(ret, true);
				return ret;
			}

			void	deleteNode(Node *n)
			{
				_na.destroy(n);
				_na.deallocate(n, 1);
			}

			Node	*highestSubNode(Node *n) {
				if (!n)
					return nullptr;
				while (n->right != nullptr && n->right->is_end == false) {
					n = n->right;
				}
				return (n);
			}

			Node	*lowestSubNode(Node *n) {
				if (!n)
					return nullptr;
				while (n->left != nullptr && n->left->is_end == false) {
					n = n->left;
				}
				return (n);
			}

			size_type	_size(Node	*head) const {
				if (head == nullptr || head->is_end == true) {
					return 0;
				} else {
					return 1 + _size(head->left) + _size(head->right);
				}
			}

		public:
			explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) : _parent(nullptr), _last(nullptr), _a(alloc), _na(), _cmp(comp), _keycmp(comp) { }
			
			~map() {
				clear();
			}
			ft::pair<iterator, bool>	insert(const value_type &val) {
				if (_parent == nullptr)
				{
					_parent = createNode(val);
					if (!_last)
						_last = createEnd();
					_parent->right = _last;
					_last->parent = _parent;
					return ft::pair<iterator, bool>(iterator(_parent), true);
				}
				else {
					Node	*head = _parent;
					while (
						((head->left != nullptr && !_cmp(head->value, val) && head->left->is_end == false)
						||
						(head->right != nullptr && _cmp(head->value, val) && head->right->is_end == false))
						&&
						(!_equals(head->value, val))
					) {
						if (!_cmp(head->value, val))
						{
							head = head->left;
						}
						else
						{
							head = head->right;
						}
					}
					if (_equals(head->value, val))
					{
						head->value.second = val.second;
						return ft::pair<iterator, bool>(iterator(head), false);
					}
					Node	*n = createNode(val);
					Node	*r = head->right;
					Node	*l = head->left;
					n->parent = head;
					if (!_cmp(head->value, val))
					{
						head->left = n;
						n->left = l;
						if (l)
							l->parent = n;
					}
					else
					{
						head->right = n;
						n->right = r;
						if (r)
							r->parent = n;
					}
					return ft::pair<iterator, bool>(iterator(n), true);
				}
			}

			iterator	insert (iterator position, const value_type &val) {
				if (_cmp(*position, val) && !_cmp(*(++position), val) && !_equals(*(position), val)) {
					return(insert(val).first);
				}
				return(insert(val).first);
			}

			template <class InputIterator>
				void		insert (InputIterator first, InputIterator last,
					typename std::enable_if<!std::is_integral<InputIterator>::value, bool>::type = true) {
						while (first != last) {
							insert(*first);
							first++;
						}
					}

			iterator	begin() { return iterator(lowestSubNode(_parent)); }
			const_iterator	begin() const { return const_iterator(lowestSubNode(_parent)); }
			const_iterator	end()	const { return const_iterator(_last);}
			iterator	end()	{ return iterator(_last);}
			reverse_iterator rbegin() { return reverse_iterator(_last); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(_last); }
			reverse_iterator rend() { return reverse_iterator(lowestSubNode(_parent)); }
			const_reverse_iterator rend() const { return const_reverse_iterator(lowestSubNode(_parent)); }
			bool		empty()	const { return(_parent == nullptr); }
			// size_type	size()	const { return(ft::distance(begin(), end()));}
			size_type	max_size() const { return _na.max_size(); }

			iterator find (const key_type& k) {
				Node	*head = _parent;
				while (
					((head->left != nullptr && !_keycmp(head->value.first, k) && head->left->is_end == false)
					||
					(head->right != nullptr && _keycmp(head->value.first, k) && head->right->is_end == false))
					&&
					(!_equals(head->value.first, k))
				) {
					if (!_keycmp(head->value.first, k))
					{
						head = head->left;
					}
					else
					{
						head = head->right;
					}
				}
				if (!_equals(head->value.first, k)) {
					return end();
				}
				return iterator(head);
			}

			const_iterator find (const key_type& k) const {
				Node	*head = _parent;
				while (
					((head->left != nullptr && !_keycmp(head->value.first, k) && head->left->is_end == false)
					||
					(head->right != nullptr && _keycmp(head->value.first, k) && head->right->is_end == false))
					&&
					(!_equals(head->value.first, k))
				) {
					if (!_keycmp(head->value.first, k))
					{
						head = head->left;
					}
					else
					{
						head = head->right;
					}
				}
				if (!_equals(head->value.first, k)) {
					return end();
				}
				return const_iterator(head);
			}

			mapped_type&	operator[](const key_type& k) {
				if (find(k) == end()) {
					return insert(value_type(k, mapped_type(7))).first->second;
				}
				else {
					return (*find(k)).second;
				}
			}

			void erase (iterator position) {
				Node	*n = position.base();
				if (n != _parent)
				{
					if (n->parent->left == n)
					{
						if (n->right)
						{
							Node *sub = lowestSubNode(n->right);
							n->parent->left = n->right;
							n->right->parent = n->parent;
							sub->left = n->left;
							if (sub->left)
								sub->left->parent = sub;
						}
						else if (n->left)
						{
							n->left->parent = n->parent;
							n->parent->left = n->left;
						}
						else {
							n->parent->left = nullptr;
						}
					}
					else {
						if (n->left)
						{
							Node *sub = highestSubNode(n->left);
							n->parent->right = n->left;
							n->left->parent = n->parent;
							sub->right = n->right;
							if (sub->right)
								sub->right->parent = sub;
							if (n == _last->parent) {
								_last->parent = highestSubNode(_parent);
							}
						}
						else if (n->right)
						{
							n->right->parent = n->parent;
							n->parent->right = n->right;
						}
						else {
							n->parent->right = nullptr;
						}
					}
				}
				else {
					if (n->left && n->left->is_end == false) {
						Node	*sub;
						_parent = n->left;
						_parent->parent = nullptr;
						sub = highestSubNode(_parent);
						sub->right = n->right;
						if (sub->right) {
							sub->right->parent = sub;
						}
						_parent->right->parent =_parent;
					}
					else if (n->right && n->right->is_end == false) {
						Node	*sub;
						_parent = n->right;
						_parent->parent = nullptr;
						sub = lowestSubNode(_parent);
						if (sub->left) {
							sub->left->parent = sub;
						}
						sub->left = n->left;
						_parent->left->parent = _parent;
					}
					else {
						_parent = nullptr;
					}
				}
				deleteNode(n);
			}

			size_type erase (const key_type& k) {
				iterator it = find(k);
				if (it == end())
					return (0);
				this->erase(it);
				return (1);
			}

			void erase (iterator first, iterator last) {
				for (; first != last; ) { //could be way more efficient I guess 
					this->erase(first++);
				}
			}

			size_type	size() const {
				return _size(_parent);
			}

			template<typename S>
				void _swap(S &l, S& r) {
					S	tmp = l;
					l = r;
					r = tmp;
				}
			void		swap(map &x) {
				_swap(_parent, x._parent);
				_swap(_last, x._last);
				_swap(_a, x._a);
				_swap(_na, x._na);
				_swap(_cmp, x._cmp);
				_swap(_keycmp, x._keycmp);
			}
		private:
			void	_clear(Node *root) {
				if (!root)
					return ;
				_clear(root->left);
				_clear(root->right);
				deleteNode(root);
			}
		public:
			void		clear() {
				_clear(_parent);
			}
	};
}

#endif