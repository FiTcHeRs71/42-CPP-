#ifndef __ROBO_TO_MY_REQUEST_FORM__
# define __ROBO_TO_MY_REQUEST_FORM__

#include <exception>
# include <string>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:

	std::string		_target;
	virtual void	performAction() const;

	protected:
	

	public:

	/*===Canonical Form===*/
	RobotomyRequestForm(void);
	~RobotomyRequestForm(void);
	RobotomyRequestForm(const RobotomyRequestForm& to_copy);
	RobotomyRequestForm&operator=(const RobotomyRequestForm& src);

	RobotomyRequestForm(std::string target);
	/*===Getters & Setters===*/
	

	/*===Member Function===*/
	class RobotizationFailed : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif