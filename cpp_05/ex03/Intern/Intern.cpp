#include "Intern.hpp"
#include <string>

/*===Canonical Form===*/
Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern default destructor called" << std::endl;
}
Intern::Intern(const Intern& to_copy)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = to_copy;
}
Intern & Intern::operator=(const Intern& src)
{
	std::cout << "Intern operator assignement(=) called" << std::endl;
	if (this != & src)
	{
		return (*this);
	}
	return (*this);
}

/*===Member Function===*/

static AForm	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(const std::string formName, const std::string target)
{
	AForm*(*all_forms[])(const std::string target_form) = {&makePresident, &makeRobot, &makeShrubbery};
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	
	for (int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (all_forms[i](target));
		}
	}
	std::cout << "Intern can not create a form called " << formName << std::endl;
	return (NULL);
}