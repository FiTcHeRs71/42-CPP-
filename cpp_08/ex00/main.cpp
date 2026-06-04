#include "easyfind.hpp"
#include <climits>
#include <exception>
#include <iostream>
#include <ostream>
#include <vector>

#define SECTION(title) std::cout << "\n\033[1;36m===== " << title << " =====\033[0m\n" << std::endl

int main(void)
{
	SECTION("TEST CORRECT VALUE");
	{
		std::vector<int> tab;
		std::vector<int>::iterator pos;

		for (int i = 100; i < 125; i++)
		{
			tab.push_back(i);
			//std::cout << tab.back() << "," <<std::endl;
		}
		try
		{
			pos = easyfind(tab, 122);
			std::cout << "trying to find [122], value return by easyfind : " << *pos << std::endl;
		} 
		catch (std::exception &e)
		{
			std::cout << "/!\\Exception catch -> " << e.what() << std::endl;
		}
	}
	SECTION("TEST UNCORRECT VALUE");
	{
		std::vector<int>			tab;
		
		for (int i = 0; i < 10; i++)
		{
			tab.push_back(i);
		}
		try
		{
			std::cout << "trying to find [5], value return by easyfind : " << *easyfind(tab, 5) << std::endl;
			std::cout << "trying to find [9999999+99999+999999999+999999999+99999999+9999999+9999999], value return by easyfind : " << *easyfind(tab, 9999999+99999+999999999+999999999+99999999+9999999+9999999) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "/!\\Exception catch -> " << e.what() << std::endl;
		}
	}
	SECTION("TEST EMPTY VECTOR");
	{
		std::vector<int>	tab;
	
		try
		{
			std::cout << "trying to find [5], value return by easyfind : " << *easyfind(tab, 5) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "/!\\Exception catch -> " << e.what() << std::endl;
		}
	}
	return (0);
}