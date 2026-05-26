#include "./PresidentialPardonForm.hpp"
#include "AForm.hpp"

/*===Canonical Form===*/
PresidentialPardonForm::PresidentialPardonForm(void)
	:AForm("PresidentialPardonForm", 25, 5, false)
	,_target("default PresidentialPardonForm")
{
	std::cout << "PresidentialPardonForm default contructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm default destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& to_copy)
	:AForm(to_copy)
	,_target(to_copy._target)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	:AForm("PresidentialPardonForm", 25, 5, false)
	,_target(target)
{
	std::cout << "PresidentialPardonForm full constructor called" << std::endl;
}

/*===Member Function===*/
void	PresidentialPardonForm::performAction() const
{
	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}