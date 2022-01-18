#ifndef NODE_HPP
# define NODE_HPP

#pragma once

enum rb_tree_color { red = false, black = true };

template<class T>
	struct tree_node {
		typedef	T		value_type;
		tree_node		*parent;
		tree_node		*left;
		tree_node		*right;
		value_type		val;
		rb_tree_color	colour;
	};

#endif