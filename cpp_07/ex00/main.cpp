#include "Whatever.hpp"
#include <iostream>

#define SECTION(title) std::cout << "\n\033[1;36m===== " << title << " =====\033[0m\n" << std::endl

int main(void)
{
	SECTION("TESTING SWAP");
	{
		int a = 5;
		int b = 10;
		std::string str = "Hello";
		std::string str2 = "42";

		std::cout << "value of a : " << a << std::endl;
		std::cout << "value of b : " << b << std::endl;
		std::cout << "value of str : " << str << std::endl;
		std::cout << "value of str2 : " << str2 << std::endl;


		std::cout << "SWAP value of a & b / str & str2" << std::endl;
		::swap(a, b);
		::swap(str, str2);

		std::cout << "value of a : " << a << std::endl;
		std::cout << "value of b : " << b << std::endl;
		std::cout << "value of str : " << str << std::endl;
		std::cout << "value of str2 : " << str2 << std::endl;
	}
	SECTION("TESTING MIN & MAX");
	{
		int a = 100;
		int b = -50;

		std::cout << "value of a : " << a << std::endl;
		std::cout << "value of b : " << b << std::endl;

		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	}
	return (0);
}