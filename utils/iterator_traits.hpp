#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#pragma once

namespace ft {
	template <class Iterator>
		struct iterator_traits
		{
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
		};
		
	struct random_access_iterator_tag { };
	
	
} // namespace ft


#endif