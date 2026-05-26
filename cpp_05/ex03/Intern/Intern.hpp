#ifndef __INTERN_HPP__
# define __INTERN_HPP__

# include "../Form/AForm.hpp"
# include "../Form/PresidentialPardonForm.hpp"
# include "../Form/RobotomyRequestForm.hpp"
# include "../Form/ShrubberyCreationForm.hpp"

class Intern
{
	public:

	/*===Canonical Form===*/
	Intern(void);
	~Intern(void);
	Intern(const Intern& to_copy);
	Intern&operator=(const Intern& src);

	/*===Getters & Setters===*/


	/*===Member Function===*/
	AForm	*makeForm(const std::string formName, const std::string target);
};

#endif