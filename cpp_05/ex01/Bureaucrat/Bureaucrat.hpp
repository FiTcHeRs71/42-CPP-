#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

# include <iostream>
# include <ostream>
# include <exception>

class Form;

class Bureaucrat
{
	private:

	const std::string	_name;
	int					_grade;

	protected:
	

	public:

	/*===Canonical Form===*/
	Bureaucrat(void);
	~Bureaucrat(void);
	Bureaucrat(const Bureaucrat& to_copy);
	Bureaucrat&operator=(const Bureaucrat& src);

	Bureaucrat(std::string name, int grade);

	/*===Getters & Setters===*/
	std::string	getName(void)const;
	int			getGrade(void)const;

	/*===Member Function===*/
	void		increaseGrade(void);
	void		demotedGrade(void);
	void		signForm(Form &form);

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

/*===Overload Operator===*/
std::ostream	&operator<<(std::ostream &flux, const Bureaucrat &bureaucrat);

#endif /*__BUREAUCRAT_HPP_*/