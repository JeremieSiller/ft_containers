#ifndef TREE_HPP
# define TREE_HPP

#pragma once

#include <memory>
#include <functional>
#include "node.hpp"
#include "iterator.hpp"
#include "binary_search_tree_iterator.hpp"

/** --- testing --- **/
#include <iostream>

template<
		class T,
		class Compare = std::less<T>,
		class Allocator = std::allocator<T>
	>
	class Tree {
	public:
		typedef	T																	value_type;
		typedef	Compare																value_compare;
		typedef	Allocator															allocator_type;
		typedef typename Allocator::template rebind<tree_node<value_type> >::other	node_allocator_type;
		typedef	tree_node<value_type>												Node;
		typedef	binary_tree_iterator<Node *, Tree, T>								iterator;
		typedef	binary_tree_iterator<const Node *, Tree, const T>					const_iterator;
		typedef ft::reverse_iterator<iterator>										reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>								const_reverse_iterator;
		typedef	size_t																size_type;
	public:
		Node				_parent;
		Node				*_root;
		allocator_type		_a;
		node_allocator_type	_na;
		Compare				_cmp;
		size_type			_size;
	/* ---- testing ---- */
	/* ---- comparison ---- */
	private:
		bool	_equals(value_type const &first, value_type const &second) const {
			return (!_cmp(first, second) && !_cmp(second, first));
		}
	/* ---- helper functions ---- */
	private:
		/*
		** allocates node and constructs
		** valuen with parameter val
		*/
		Node	*createNode(value_type const &val) {
			Node *ret = _na.allocate(1);
			_a.construct(&(ret->val), val);
			ret->parent = nullptr;
			ret->left = nullptr;
			ret->right = nullptr;
			ret->colour = red;
			return ret;
		}

		/*
		** destroyes value of node and
		** deallocates node
		*/
		void	removeNode(Node *root) {
			_a.destroy(&(root->val));
			_na.deallocate(root, 1);
		}

		/*
		** searches for value and returns it's node
		** if it doesn't find it, it returns the node before it
		*/
		Node	*_search(Node *root, const value_type &val) const {
			if (!root)
				return nullptr;
			if (_equals(root->val, val))
				return root;
			if (_cmp(val, root->val) && root->left == nullptr) {
				return root;
			}
			if (!_cmp(val, root->val) && root->right == nullptr) {
				return root;
			}
			if (!_cmp(val, root->val)) {
				return _search(root->right, val);
			}
			return _search(root->left, val);
		}

		/*
		** searches for the most left node which in case of 
		** std::less is the smallest value
		*/
		Node	*mostLeft(Node *root) const {
			while (root && root->left && root != &_parent) {
				root = root->left;
			}
			return(root);
		}

		/*
		** searches for the most right node which in case of 
		** std::less is the biggest value
		*/
		Node	*mostRight(Node *root) const {
			while (root && root->right) {
				root = root->right;
			}
			return(root);
		}
		/*
		** returns the successor of a root.
		** the successor is the next node which is at the right of the node
		** if you look at the orde.
		*/
		Node	*successor(Node *root) const {
			Node	*tmp = root;
			while (tmp->left)
				tmp = tmp->left;
			return tmp;
		}
		/*
		** right-rotation
		** rotates a node to the right, if the node is the root 
		** new root will be node->left
		*/
		void	right_rotation(Node *root) {
			if (!root->left)
				return ;
			Node	*tmp = root->left;
			if (root == _root) {
				_root = tmp;
				_root->parent = &_parent;
				_parent.left = _root;
			}
			if (root->parent && root->parent != &_parent) {
				if (root->parent->left == root) {
					root->parent->left = tmp;
				} else {
					root->parent->right = tmp;
				}
			}
			tmp->parent = root->parent;
			root->parent = tmp;
			root->left = tmp->right;
			if (root->left) {
				root->left->parent = root;
			}
			tmp->right = root;
		}

		/*
		** left-rotation
		** rotates a node to the left, if the node is the root 
		** new root will be node->right
		*/
		void	left_rotation(Node *root) {
			if (!root || !root->right)
				return ;
			Node *tmp = root->right;
			if (root == _root) {
				_root = tmp;
				_root->parent = &_parent;
				_parent.left = _root;
			}
			if (root->parent && root->parent != &_parent) {
				if (root->parent->left == root) {
					root->parent->left = tmp;
				} else {
					root->parent->right = tmp;
				}
			}
			tmp->parent = root->parent;
			root->parent = tmp;
			root->right = tmp->left;
			if (root->right) {
				root->right->parent = root;
			}
			tmp->left = root;
		}

		/**
		 * @brief insertion fix, fixes tree if a violation of
		 * the red-black-tree rules has accured;
		 */
		void	fix_insert(Node *root) {
			Node	*tmp;
			while (root->parent && root->parent != &_parent && root->parent->colour == red) {
				if (root->parent == root->parent->parent->left) {
					tmp = root->parent->parent->right;
					if (tmp && tmp->colour == red) {
						root->parent->colour = black;
						tmp->colour = black;
						root->parent->parent->colour = red;
						root = root->parent->parent;
					} else if (root == root->parent->right) {
						root = root->parent;
						left_rotation(root);
					}
					else {
						root->parent->colour = black;
						root->parent->parent->colour = red;
						right_rotation(root->parent->parent);
					}
				}
				else {
					tmp = root->parent->parent->left;
					if (tmp && tmp->colour == red) {
						root->parent->colour = black;
						tmp->colour = black;
						root->parent->parent->colour = red;
						root = root->parent->parent;
					} else if (root == root->parent->left) {
						root = root->parent;
						right_rotation(root);
					}
					else {
						root->parent->colour = black;
						root->parent->parent->colour = red;
						left_rotation(root->parent->parent);
					}
				}
			}
			_root->colour = black;
		}

		void	_clear(Node	*root) {
			if (!root)
				return ;
			_clear(root->left);
			_clear(root->right);
			removeNode(root);
		}

		Node	*sibling(Node *n) const {
			if (n == nullptr || n->parent == nullptr)
				return nullptr;
			if (n == n->parent->left)
				return n->parent->right;
			return n->parent->left;
		}

		bool	isDoubleBlack(Node *p) {
			if (p->colour == black) {
				if (p->left && p->left->colour == black) {
					return true;
				} else if (p->right && p->right->colour == black) {
					return true;
				} else if (!p->left && !p->left) {
					return true;
				}
			}
			return false;
		}

		Node	*replacement(Node *v) const {
			if (!v)
				return nullptr;
			if (v->left != nullptr && v->right != nullptr)
				return successor(v->right);
			if (v->left == nullptr && v->right == nullptr)
				return nullptr;
			if (v->right == nullptr)
				return v->left;
			return v->right;
		}

		bool	colour(Node *n) const {
			if (!n || n->colour == black)
				return black;
			return red;
		}

		void	fixDoubleBlack(Node *x) {
			if (x == _root)
				return ;
			Node	*sibling;
			Node	*parent;
			sibling = this->sibling(x);
			parent = x->parent;
			if (sibling == nullptr) {
				fixDoubleBlack(parent);
			} else {
				if (colour(sibling) == red) {
					parent->colour = red;
					sibling->colour= black;
					if (sibling == sibling->parent->left) {
						right_rotation(parent);
					} else {
						left_rotation(parent);
					}
					fixDoubleBlack(x);
				} else {
					if (colour(sibling->left) == red || colour(sibling->right) == red) { // red childs ≥1
						if (sibling->left != nullptr && sibling->left->colour == red) {
							if (sibling->parent->left == sibling) {
								sibling->left->colour = sibling->colour;
								sibling->colour = parent->colour;
								right_rotation(parent);
							} else {
								sibling->left->colour = parent->colour;
								right_rotation(sibling);
								left_rotation(parent);
							}
						} else {
							if (sibling->parent && sibling->parent->left == sibling) {
								sibling->right->colour = parent->colour;
								left_rotation(sibling);
								right_rotation(parent);
							} else {
								sibling->right->colour = sibling->colour;
								sibling->colour = parent->colour;
								left_rotation(parent);
							}
						}
						parent->colour = black;
					} else { // 2 black chlidren
						sibling->colour = red;
						if (parent->colour == black)
							fixDoubleBlack(parent);
						else
							parent->colour	= black;
					}
				}
			}
		}

	public:
		explicit Tree(const value_compare& comp, const allocator_type &alloc) :
		_parent(), _root(nullptr), _a(alloc), _na(alloc), _cmp(comp), _size(0) { 
			_parent.left = &_parent;
			_parent.right = nullptr;
		}

		Tree(const Tree &x) : _parent(), _root(), _a(x._a), _na(x._na), _cmp(x._cmp), _size(0) { //probably more efficient way by just creating new tree
			const_iterator	b = x.begin();
			const_iterator	e = x.end();
			while (b != e) {
				this->insert(*b);
				b++;
			}
		}

		ft::pair<iterator, bool>	insert(value_type const &val) {
			Node	*tmp;
			Node	*r;
			if (_root == nullptr) {
				_root = createNode(val);
				_root->colour = black;
				_root->parent = &_parent;
				_parent.left = _root;
				fix_insert(_root);
				_size++;
				return (ft::make_pair(iterator(_root), true));
			}
			tmp = _search(_root, val);
			if (_equals(val, tmp->val)) {
				return (ft::make_pair(iterator(tmp), false));
			}
			else if (_cmp(val, tmp->val)) {
				tmp->left = createNode(val);
				r = tmp->left;
				tmp->left->parent = tmp;
				fix_insert(tmp->left);
				_size++;
				return (ft::make_pair(iterator(r), true));
			}
			else {
				tmp->right = createNode(val);
				r = tmp->right;
				tmp->right->parent = tmp;
				fix_insert(tmp->right);
				_size++;
				return (ft::make_pair(iterator(r), true));
			}
		}

		iterator	insert(iterator position, const value_type &val) {
			return insert(val).first;
			(void)position;
		}

		template<class InputIterator>
			void	insert(InputIterator first, InputIterator last) {
				while (first != last)
				{
					insert(*first);
					first++;
				}
			}

		size_type	erase(value_type const &val) {
			Node	*tmp = _search(_root, val);
			if (!tmp || !_equals(val, tmp->val))
				return 0;
			erase(tmp);
			return 1;
		}

		void	erase(Node *v) {
			if (!v)
				return ;
			Node	*u = replacement(v);
			bool	dBlack = ((colour(u) == black && colour(v) == black));
			Node	*parent = v->parent;
			if (u == nullptr) {
				if (v == _root) {
					_root = nullptr;
					_parent.left = &_parent;
				} else {
					if (dBlack == true) {
						fixDoubleBlack(v);
					} else {
						if (sibling(v) != nullptr) {
							sibling(v)->colour = red;
						}
					}
					if (v == v->parent->left) {
						parent->left = nullptr;
					} else {
						parent->right = nullptr;
					}
				}
				_size--;
				removeNode(v);
				return ;
			}
			if (v->left == nullptr || v->right == nullptr) {
				if (v == _root) {
					_root = u;
					_root->parent = &_parent;
					u->left = nullptr;
					u->right = nullptr;
					u->colour = black;
					removeNode(v);
				} else {
					if (v == v->parent->left) {
						parent->left = u;
					} else {
						parent->right = u;
					}
					u->parent = parent;
					removeNode(v);
					if (dBlack == true) {
						fixDoubleBlack(u);
					} else {
						u->colour = black;
					}
				}
				_size--;
				return ;
			}
			if (v == _root) {
				_root = u;
			}
			if (v->parent && v->parent->left == v) {
				v->parent->left = u;
			} else if (v->parent && v->parent->right == v) {
				v->parent->right = u;
			}
			if (v->right) {
				v->right->parent = u;
			}
			if (v->left) {
				v->left->parent = u;
			}
			if (u->parent && u == u->parent->left) {
				u->parent->left = v;
			}
			if (u->parent && u == u->parent->right) {
				u->parent->right = v;
			}
			ft::swap(u->parent, v->parent);
			ft::swap(u->left, v->left);
			ft::swap(u->right, v->right);
			ft::swap(u->colour, v->colour);
			erase(v);
		}

		void	erase(iterator first, iterator last) {
			while (first != last) {
				erase(first++.base());
			}
		}

		void	clear() {
			_clear(_root);
			_parent.left = &_parent;
			_root = nullptr;
			_size = 0;
		}

		
		iterator				begin()				{ return iterator(mostLeft(_parent.left));}
		const_iterator			begin()		const	{ return const_iterator(mostLeft(_parent.left));}
		iterator				end()				{ return iterator(&_parent);		}
		const_iterator			end()		const	{ return const_iterator(&_parent);		}
		reverse_iterator		rbegin()			{ return reverse_iterator(end());	}
		const_reverse_iterator	rbegin() 	const	{ return const_reverse_iterator(end()); }
		reverse_iterator		rend()				{ return reverse_iterator(begin());	}
		const_reverse_iterator	rend()		const	{ return reverse_iterator(begin());	}

		bool		empty()	const { return (begin() == end()); }
		size_type	size()	const { return _size; }
		size_type	max_size() const { return _na.max_size(); }
		
		iterator		find (const value_type& k)		{
			Node	*n = _search(_root, k);
			if (!n || !_equals(n->val, k))
				return end();
			return iterator(n);
		};

		const_iterator	find (const value_type& k) const	{
			Node	*n = _search(_root, k);
			if (!n || !_equals(n->val, k))
				return end();
			return const_iterator(n);
		};

		void	swap(Tree &other) {
			ft::swap(_parent.left, other._parent.left);
			ft::swap(_root, other._root);
			ft::swap(_a, other._a);
			ft::swap(_na, other._na);
			ft::swap(_cmp, other._cmp);
			ft::swap(_size, other._size);
			_root->parent = &_parent;
			other._root->parent = &other._parent;
		}

		value_compare	value_comp() const { return _cmp; }

		size_type	count(const value_type &k) const {
			return (find(k) != end());
		}
		iterator lower_bound (const value_type &k) {
			reverse_iterator rbg = rbegin();
			reverse_iterator ren = rend();
			while (rbg != ren && !_equals(*rbg, k) && !_cmp(k, *rbg)) {
				rbg++;
			}
			if (rbg == rend())
				return end();
			return rbg.base();
		}
		const_iterator lower_bound (const value_type &k) const {
			const_reverse_iterator rbg = rbegin();
			const_reverse_iterator ren = rend();
			while (rbg != ren && !_equals(*rbg, k) && !_cmp(k, *rbg)) {
				rbg++;
			}
			if (rbg == rend())
				return end();
			return rbg.base();
		}
		iterator upper_bound (const value_type &k) {
		}
		const_iterator upper_bound (const value_type &k) const {

		}

		~Tree() { clear(); }
	};

#endif