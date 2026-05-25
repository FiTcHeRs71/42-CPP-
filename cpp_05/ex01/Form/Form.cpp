#include "Form.hpp"

/*===Canonical Form===*/
Form::Form(void)
	:_name("default")
	,_toSign(1)
	,_toExecute(1)
	,_is_signed(false)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form default destructor called" << std::endl;
}

Form::Form(const Form& to_copy)
	:_name(to_copy._name)
	,_toSign(to_copy._toSign)
	,_toExecute(to_copy._toExecute)
	,_is_signed(to_copy._is_signed)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form & Form::operator=(const Form& src)
{
	if (this != &src)
	{
		this->_is_signed = src._is_signed;
	}
	return (*this);
}

Form::Form(std::string name, int to_sign, int to_execute, bool is_signed)
	:_name(name)
	,_toSign(to_sign)
	,_toExecute(to_execute)
	,_is_signed(is_signed)
{
	std::cout << "Form full constructor called" << std::endl;
}

/*===Getters & Setters===*/
std::string	Form::getNAme(void)const
{
	return (this->_name);
}

int	Form::getToSign(void)const
{
	return (this->_toSign);
}

int	Form::getToExecute(void)const
{
	return (this->_toExecute);
}

bool	Form::getIsSigned(void)const
{
	return (this->_is_signed);
}

/*===Member Function===*/
void		beSigned(Bureaucrat &bureaucrat)
{

}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*Form::GradeTooLowException::what()  const throw()
{
	return ("Grade is too low");
}

/*===Overload Operator===*/
std::ostream	&operator<<(std::ostream &flux, Form const &form)
{
	flux << "Name : " << form.getNAme() << ", Sign Grade : " << form.getToSign() << ", Execute Grade : " << form.getToExecute() << ", is signed : " << form.getIsSigned() << std::endl;
	return (flux);
}