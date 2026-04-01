
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
}
