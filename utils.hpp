#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft {
	/*
	** check wether a type is integeral ...
	**/
	template <bool is_integral, typename type>
		struct  is_integral_res 
		{
			static const bool value = is_integral;
		};
	template <>
		struct is_integeral_type : public is_integral_res<false, bool> {};
	template <>
		struct is_integeral_type<bool> : public is_integral_res<true, bool> {};
	template <>
		struct is_integeral_type<char> : public is_integral_res<true, char> {};
	template <>
		struct is_integeral_type<signed char> : public is_integral_res<true, signed char> {};
	template <>
		struct is_integeral_type<unsigned char> : public is_integral_res<true, unsigned char> {};
	template <>
		struct is_integeral_type<short int> : public is_integral_res<true, short int> {};
	template <>
		struct is_integeral_type<int> : public is_integral_res<true, int> {};
	template <>
		struct is_integeral_type<long int> : public is_integral_res<true, long int> {};
	template <>
		struct is_integeral_type<long long int> : public is_integral_res<true, long long int> {};
	template <>
		struct is_integeral_type<unsigned char> : public is_integral_res<true, unsigned char> {};
	template <>
		struct is_integeral_type<unsigned short int> : public is_integral_res<true, unsigned short int> {};
	template <>
		struct is_integeral_type<unsigned int> : public is_integral_res<true, unsigned int> {};
	template <>
		struct is_integeral_type<unsigned long int> : public is_integral_res<true, unsigned long int> {};
	template <>
		struct is_integeral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int> {};
	template <typename T>
		struct is_integral : public is_integral_type<type> { };
}
# endif 