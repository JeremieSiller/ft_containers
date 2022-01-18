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
		typedef reverse_iterator<iterator>											reverse_iterator;
	private:
	public:
		Node				_parent;
		Node				*_root;
		allocator_type		_a;
		node_allocator_type	_na;
		Compare				_cmp;
	/* ---- testing ---- */
	public:
			void _shit(Node *root, int space)
			{
				if (root == nullptr)
					return;
				space += 10;
				_shit(root->right, space);
				std::cout<<std::endl;
				for (int i = 10; i < space; i++)
					std::cout << " ";
				std::cout << (root)->val << "\n";
				_shit(root->left, space);
			}
			void _shit2(Node *root, int space)
			{
				if (root == nullptr)
					return;
				space += 10;
				_shit2(root->right, space);
				std::cout<<std::endl;
				for (int i = 10; i < space; i++)
					std::cout << " ";
				if (root->colour == black) {
					std::cout << "B" << "\n";
				} else {
					std::cout << "R" << "\n";
				}
				_shit2(root->left, space);
			}
			// print tree as rb and keys
			void print()
			{
				_shit(_root, 0);
				std::cout << "--------------------------------------------------" << std::endl;
				_shit2(_root, 0);
			}
	/* ---- comparison ---- */
	private:
		bool	_equals(value_type const &first, value_type const &second) const {
			return (!_cmp(first, second) && !_cmp(second, first));
		}
	/* ---- allocation and deallocation ---- */
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
			if (!root)
				return nullptr;
			if (root->right != nullptr) {
				return mostLeft(root->right);
			}
			Node	*tmp = root->parent;
			while (tmp != nullptr && root != tmp->left) {
				root = tmp;
				tmp = tmp->parent;
			}
			return tmp;
		}
	/* ----- ROTATIONS - self balancing ----- */
	public:
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

	public:
		explicit Tree(allocator_type const &alloc = allocator_type()) :
		_parent(), _root(nullptr), _a(alloc), _na(alloc), _cmp() { 
			_parent.left = &_parent;
			_parent.right = nullptr;
		}


		void	insert(value_type const &val) {
			Node	*tmp;
			if (_root == nullptr) {
				_root = createNode(val);
				_root->colour = black;
				_root->parent = &_parent;
				_parent.left = _root;
				fix_insert(_root);
				return ;
			}
			tmp = _search(_root, val);
			if (_equals(val, tmp->val)) {
				tmp->val = val;
			}
			else if (_cmp(val, tmp->val)) {
				tmp->left = createNode(val);
				tmp->left->parent = tmp;
				fix_insert(tmp->left);
			}
			else {
				tmp->right = createNode(val);
				tmp->right->parent = tmp;
				fix_insert(tmp->right);
			}
		}

		void	erase(value_type const &val) {
			Node	*tmp = _search(_root, val);
			if (!tmp || !_equals(val, tmp->val))
				return ;
			erase(tmp);
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
			if (v->left == nullptr)
				return v->right;
			if (v->right == nullptr)
				return v->left;
			return successor(v);
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
							if (sibling->left != nullptr && sibling->left->colour == red) {
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

		void	erase(Node *v) {
			if (!v)
				return ;
			Node	*u = replacement(v);
			bool	dBlack = ((colour(u) == black && colour(v) == black));
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
						v->parent->left = nullptr;
					} else {
						v->parent->right = nullptr;
					}
				}
				removeNode(v);
				return ;
			}
			if (v->left == nullptr || v->right == nullptr) {
				if (v == _root) {
					v->val = u->val;
					v->left = nullptr;
					v->right = nullptr;
					removeNode(u);
				} else {
					if (v == v->parent->left) {
						v->parent->left = u;
					} else {
						v->parent->right = u;
					}
					u->parent = v->parent;
					removeNode(v);
					if (dBlack == true) {
						fixDoubleBlack(u);
					} else {
						u->colour = black;
					}
				}
				return ;
			}
			v->val = u->val;
			erase(u);
		}

		void	clear() {
			_clear(_root);
			_parent.left = &_parent;
			_root = nullptr;
		}

		~Tree() { clear(); }
		
		iterator			begin()		{ return iterator(mostLeft(_parent.left));}
		iterator			end()		{ return iterator(&_parent);		}
		reverse_iterator	rbegin()	{ return reverse_iterator(end());	}
		reverse_iterator	rend()		{ return reverse_iterator(begin());	}
	};

#endif