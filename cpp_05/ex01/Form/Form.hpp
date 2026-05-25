#ifndef __FORM_HPP__
# define __FORM_HPP__

# include <iostream>
# include <ostream>
# include <string>
# include "../Bureaucrat/Bureaucrat.hpp"

class Form
{
	private:

	const std::string	_name;
	const int			_toSign;
	const int			_toExecute;
	bool				_is_signed;

	protected:
	

	public:

	/*===Canonical Form===*/
	Form(void);
	~Form(void);
	Form(const Form& to_copy);
	Form&operator=(const Form& src);

	Form(std::string name, int to_sign, int to_execute, bool is_signed);

	/*===Getters & Setters===*/
	std::string	getNAme(void)const;
	int			getToSign(void)const;
	int			getToExecute(void)const;
	bool		getIsSigned(void)const;

	/*===Member Function===*/
	void		beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream	operator<<(const std::ostream &flux, const Form &form);

#endif /*__FORM_HPP__*/