#ifndef __AFORM_HPP__
# define __AFORM_HPP__

# include <iostream>
# include <ostream>
# include <string>

class Bureaucrat;

class AForm
{
	protected:

	const std::string	_name;
	const int			_toSign;
	const int			_toExecute;
	bool				_is_signed;
	
	public:
	
	/*===Canonical AForm===*/
	AForm(void);
	virtual~AForm(void);
	AForm(const AForm& to_copy);
	AForm&operator=(const AForm& src);
	
	AForm(std::string name, int to_sign, int to_execute, bool is_signed);
	
	/*===Getters & Setters===*/
	std::string		getName(void)const;
	int				getToSign(void)const;
	int				getToExecute(void)const;
	std::string		getIsSigned(void)const;
	
	/*===Member Function===*/
	virtual void	performAction()const = 0;
	void			beSigned(Bureaucrat &bureaucrat);
	void			execute(Bureaucrat const & executor)const;

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

	class IsNotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &flux, const AForm &Aform);

#endif /*__AAFORM_HPP__*/