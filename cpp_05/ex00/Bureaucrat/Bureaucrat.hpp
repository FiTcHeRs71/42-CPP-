#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

#include <iostream>
#include <ostream>

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

	/*===Getters & Setters===*/
	std::string	getName(void)const;
	int			getGrade(void)const;

	/*===Overload Operator===*/
	

	/*===Member Function===*/
	void		increaseGrade(void);
	void		demotedGrade(void);
};

std::ostream	&operator<<(std::ostream &flux, const Bureaucrat & bureaucrat);

#endif /*__BUREAUCRAT_HPP_*/