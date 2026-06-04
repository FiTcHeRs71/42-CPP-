#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <iostream>
# include <algorithm>

class NotFoundException :public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Value not found");
		}
};

template <typename T> 
typename T::iterator easyfind(T &param_1, int param_2)
{
	typename T::iterator i;

	i = std::find(param_1.begin(), param_1.end(), param_2);
	if (i == param_1.end())
		throw NotFoundException();
	return (i);
}

#endif