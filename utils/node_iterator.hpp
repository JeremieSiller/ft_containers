#ifndef NODE_ITERATOR_HPP
# define NODE_ITERATOR_HPP
#include <iostream>

#pragma once

template<typename T, typename container, typename value>
class	binary_tree_iterator {
public:
	typedef	T		Node;

	typedef			value					value_type;
	typedef			typename container::size_type	difference_type;
	typedef			typename container::pointer		pointer;
	typedef			value_type&		reference;
	typedef			value_type		iterator_category;
private:
	Node	_current;
public:
	binary_tree_iterator() : _current(nullptr) { }
	binary_tree_iterator(Node const &in) : _current(in) { }
	binary_tree_iterator(binary_tree_iterator<typename container::Node *, container, typename container::value_type> const &in) : _current(in.base()) { }
	// binary_tree_iterator(const binary_tree_iterator<const T, const V> &in) : _current(in._current) { }
	const Node	&base() const { return _current; }
	binary_tree_iterator &operator++() {
		if (_current->right != nullptr) {
			_current = _current->right;
			while (_current->left) {
				_current = _current->left;
			}
		}
		else {
			Node	c = _current;
			_current = _current->parent;
			while (_current->right == c)
			{
				c = _current;
				_current = _current->parent;
			}
		}
		return *this;
	}

	binary_tree_iterator operator++(int) {
		binary_tree_iterator save = _current;
		if (_current->right != nullptr) {
			_current = _current->right;
			while (_current->left) {
				_current = _current->left;
			}
		}
		else {
			Node	c = _current;
			_current = _current->parent;
			while (_current->right == c)
			{
				c = _current;
				_current = _current->parent;
			}
		}
		return save;
	}

	binary_tree_iterator operator--(int) {
		binary_tree_iterator save = _current;
		if (_current->left != nullptr) {
			_current = _current->left;
			while (_current->right) {
				_current = _current->right;
			}
			
		}
		else {
			Node	c = _current;
			_current = _current->parent;
			while (_current->left == c) {
				c = _current;
				_current = _current->parent;
			}
		}
		return save;
	}

	binary_tree_iterator &operator--() {
		if (_current->left != nullptr) {
			_current = _current->left;
			while (_current->right) {
				_current = _current->right;
			}
			
		}
		else {
			Node	c = _current;
			_current = _current->parent;
			while (_current->left == c) {
				c = _current;
				_current = _current->parent;
			}
		}
		return *this;
	}

	binary_tree_iterator	operator-(int const &i) const {
		binary_tree_iterator ret = *this;
		for (int j = 0; j < i; j++)
		{
			ret--;
		}
		return (ret);
	}

	// }
	bool operator==(binary_tree_iterator const &other) const {
		return _current == other._current;
	}
	bool operator!=(binary_tree_iterator const &other) const {
		return !(*this == other);
	}
	value_type	&operator*() {
		return _current->value;
	}
};

#endif