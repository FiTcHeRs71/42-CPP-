#include "AForm.hpp"
# include "../Bureaucrat/Bureaucrat.hpp"

/*===Canonical AForm===*/
AForm::AForm(void)
	:_name("default")
	,_toSign(1)
	,_toExecute(1)
	,_is_signed(false)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "AForm default destructor called" << std::endl;
}

AForm::AForm(const AForm& to_copy)
	:_name(to_copy._name)
	,_toSign(to_copy._toSign)
	,_toExecute(to_copy._toExecute)
	,_is_signed(to_copy._is_signed)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm & AForm::operator=(const AForm& src)
{
	if (this != &src)
	{
		this->_is_signed = src._is_signed;
	}
	return (*this);
}

AForm::AForm(std::string name, int to_sign, int to_execute, bool is_signed)
	:_name(name)
	,_toSign(to_sign)
	,_toExecute(to_execute)
	,_is_signed(is_signed)
{
	if (to_sign > 150 || to_execute > 150)
		throw GradeTooLowException();
	else if (to_sign < 1 || to_execute < 1)
		throw GradeTooHighException();
	std::cout << "AForm full constructor called" << std::endl;
}

/*===Getters & Setters===*/
std::string	AForm::getName(void)const
{
	return (this->_name);
}

int	AForm::getToSign(void)const
{
	return (this->_toSign);
}

int	AForm::getToExecute(void)const
{
	return (this->_toExecute);
}

bool	AForm::getIsSigned(void)const
{
	return (this->_is_signed);
}

/*===Member Function===*/
void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getToSign())
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << this->_name << " because ";
		throw GradeTooLowException();
	}
	else if (this->_is_signed == false)
	{
		this->_is_signed = true;
		std::cout << bureaucrat << " have signed : " << this ->_name << std::endl;
	}
	else
	{
		std::cout << "AForm is already signed" << std::endl;
	}
}

void	AForm::execute(Bureaucrat const & executor)
{
	if (this->_is_signed == false)
	{
		std::cout << executor.getName() << " couldn't execute " << this->_name << " because ";
		throw IsNotSignedException();
	}
	else if (executor.getGrade() > this->getToExecute())
	{
		std::cout << executor.getName() << " couldn't execute " << this->_name << " because ";
		throw GradeTooLowException();
	}
	else
		performAction();
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char	*AForm::IsNotSignedException::what() const throw()
{
	return ("Form can not be executed, because it is not signed!");
}

/*===Overload Operator===*/
std::ostream	&operator<<(std::ostream &flux, AForm const &Aform)
{
	flux << "Name : " << Aform.getName() << ", Sign Grade : " << Aform.getToSign() << ", Execute Grade : " << Aform.getToExecute() << ", is signed : " << Aform.getIsSigned();
	return (flux);
}