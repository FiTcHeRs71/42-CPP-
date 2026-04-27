
#include <iostream>
#include <iomanip>
#include <ostream>

int	main(void)
{
	std::string brain_str = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain_str;
	std::string &stringREF = brain_str;

	std::cout << std::left;
	std::cout << "variable declared is brain_str and comtains : " << brain_str << std::endl << std::endl;

	std::cout << std::setw(40) << "Memory adress of the string :" << &brain_str << std::endl;
	std::cout << std::setw(40) << "Memory adress of the string pointer :" << stringPTR << std::endl;
	std::cout << std::setw(40) << "Memory adress of the string reference :" << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(40) << "Value of string varible :" << brain_str << std::endl;
	std::cout << std::setw(40) << "Value pointer to by string pointer :" << *stringPTR << std::endl;
	std::cout << std::setw(40) << "Value pointer to by string reference :" << stringREF << std::endl;
}