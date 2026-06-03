#include "easyfind.hpp"
#include <exception>
#include <iostream>
#include <vector>

int main(void)
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
		std::cout<< "trying to find [122], value return by easyfind : " << *pos << std::endl;
	} 
	catch (std::exception &e)
	{
		std::cout << "Exception catch : " << e.what() << std::endl;
	}
}