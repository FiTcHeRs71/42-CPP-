#ifndef __PRESIDENTIAL_PARDON_FORM__
# define __PRESIDENTIAL_PARDON_FORM__

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
	private:

	std::string	_target;
	virtual void	performAction() const;

	protected:
	

	public:

	/*===Canonical Form===*/
	PresidentialPardonForm(void);
	~PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm& to_copy);
	PresidentialPardonForm&operator=(const PresidentialPardonForm& src);

	PresidentialPardonForm(std::string target);

	/*===Getters & Setters===*/
	std::string		getTarget(void)const;

	/*===Member Function===*/
};

#endif /*__PRESIDENTIAL_PARDON_FORM__*/