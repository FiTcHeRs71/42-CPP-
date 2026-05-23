#include "Bureaucrat.hpp"

	/*===Canonical Form===*/
	Bureaucrat::Bureaucrat(void)
	{
		std::cout << "Bureaucrat default constructor called" << std::endl;
	}

	Bureaucrat::~Bureaucrat(void)
	{
		std::cout << "Bureaucrat default destructor called" << std::endl;
	}

	Bureaucrat::Bureaucrat(const Bureaucrat& to_copy)
	{
		std::cout << "Bureaucrat copy constructor called" << std::endl;
	}

	Bureaucrat & Bureaucrat::operator=(const Bureaucrat& src)
	{
		std::cout << "Bureaucrat assignement operator(=) called" << std::endl;
		if (this != & src)
		{

		}
		return (*this);
	}

	/*===Getters & Setters===*/
	std::string	Bureaucrat::getName(void)const
	{
		return (this->_name);
	}

	int		Bureaucrat::getGrade(void)const
	{
		return (this->_grade);
	}

	/*===Member Function===*/
	void	Bureaucrat::increaseGrade(void)
	{
		if (this->_grade - 1 >= 1)
		{
			this->_grade -= 1;
			std::cout << "Congrats to " << this->_name << " get promoted, his rank is now " << this->_grade << std::endl;
		}
		else
	}

	void	Bureaucrat::demotedGrade(void)
	{
		if (this->_grade + 1 <= 150)
		{

		}
		else
	}

/*===Overload Operator===*/
std::ostream	&operator<<(std::ostream &flux, const Bureaucrat & bureaucrat)
{

}