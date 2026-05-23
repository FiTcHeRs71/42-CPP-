#include "Bureaucrat.hpp"

/*===Canonical Form===*/
Bureaucrat::Bureaucrat(void)
	:_name("default")
	,_grade(75)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat default destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& to_copy)
	:_name(to_copy._name)
	,_grade(to_copy._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat& src)
{
	std::cout << "Bureaucrat assignement operator(=) called" << std::endl;
	if (this != & src)
	{
		this->_grade = src._grade;
	}
	return (*this);
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	:_name(name)
{
	std::cout << "Bureaucrat full constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
}

/*===Getters & Setters===*/
std::string	Bureaucrat::getName(void)const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void)const
{
	return (this->_grade);
}

/*===Member Function===*/
void	Bureaucrat::increaseGrade(void)
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	else
	{
		this->_grade -= 1;
		std::cout << "Congrats to " << this->_name << " get promoted, his rank is now " << this->_grade << std::endl;
	}
}

void	Bureaucrat::demotedGrade(void)
{
	if (this->_grade  == 150)
	{
		throw GradeTooLowException();
	}
	else
	{
		this->_grade += 1;
		std::cout << "due to insufficient work " << this->_name << " has been demoted, his rank is now " << this->_grade << std::endl;
	}
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

/*===Overload Operator===*/
std::ostream	&operator<<(std::ostream &flux, const Bureaucrat & bureaucrat)
{
	flux << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (flux);
}
