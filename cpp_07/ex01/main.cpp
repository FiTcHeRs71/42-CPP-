#include "iter.hpp"
#include <cctype>
#include <cstddef>
#include <iostream>

#define SECTION(title) std::cout << "\n\033[1;36m===== " << title << " =====\033[0m\n" << std::endl

void	ft_toUpper(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}
}

void	to_negativ(int &param_1)
{
	param_1 *= -1;
}

int main(void)
{
	SECTION("TEST ITER ON STRING");
	{
		std::string array[] = {"Hello", "World", "!"};

		::iter(array, static_cast<size_t>(3), ft_toUpper);
		for (int i = 0; i < 3; i++)
		{
			std::cout << array[i] << std::endl;
		}
	}
	SECTION("TEST ITER ON INT");
	{
		int array[] = {1,2,3};

		::iter(array, 3, to_negativ);
		for (int i = 0; i < 3; i++)
		{
			std::cout << array[i] << std::endl;
		}
	}
	return (0);
}