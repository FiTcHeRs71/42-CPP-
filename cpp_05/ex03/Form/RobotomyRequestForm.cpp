#include "./RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstdlib>

/*===Canonical Form===*/
RobotomyRequestForm::RobotomyRequestForm(void)
	:AForm("RobotomyRequestForm", 72, 45, false)
	,_target("Default target")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm default destructor called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& to_copy)
	:AForm(to_copy)
	,_target(to_copy._target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	:AForm("RobotomyRequestForm", 72, 45, false)
	,_target(target)
{
	std::cout << "RobotomyRequestForm full constructor called" << std::endl;
}

/*===Getters & Setters===*/
std::string	RobotomyRequestForm::getTarget(void)const
{
	return (this->_target);
}

/*===Member Function===*/
void	RobotomyRequestForm::performAction() const
{
	int random;

	random = rand() % 2;
	if(random == 1)
		std::cout << "Beeep Be Be Beeeee Beeeeeeeep. " << getTarget() << " has been robotomized successfully!" << std::endl;
	else
		throw RobotizationFailed();
}

const char	*RobotomyRequestForm::RobotizationFailed::what() const throw()
{
	return ("RobotizationFailed");
}