#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template <typename T_array, typename T_function>
void	iter(T_array *array, const size_t length, T_function function)
{
	for (size_t idx = 0; idx < length; idx++)
		function(array[idx]);
}



#endif