/*
#include "sandbox.hpp"

student::student(void) {}

student::~student(void) {}

std::string student::getName(void)
{
	return this->_name;
}

void student::setName(std::string name)
{
	this->_name = name;
}

int	student::getNote(void)
{
	return this->_note;
}

void	student::setNote(int note)
{
	this->_note = note;
}
int main(void)
{
	student fred;
	fred.setName("Fichers");
	fred.setNote(18);
	std::cout << fred.getName() << " a eu la note de " << fred.getNote() << std::endl;
}*/

/*
#include <iostream>     // std::cout
#include <algorithm>    // std::max

int main () 
{
	std::cout << "max(1,2)==" << std::max(1,2) << '\n';
	std::cout << "max(2,1)==" << std::max(2,1) << '\n';
	std::cout << "max('a','z')==" << std::max('a','z') << '\n';
	std::cout << ("max(3.14,2.73)==" << std::max(3.14,2.73) << '\n';
	return 0;
}*/

#include "sandbox.hpp"
bigint::bigint(void)
{
}
bigint::~bigint(void){}

bigint::bigint(const bigint &src)
{
	this->_array = src._array;
}
bigint & bigint::operator=(const bigint &src)
{
	this->_array = src._array;
}