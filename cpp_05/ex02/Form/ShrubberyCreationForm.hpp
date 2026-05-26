#ifndef __SHRUBBERY_CREATION_FORM_HPP__
# define __SHRUBBERY_CREATION_FORM_HPP__

# include "./AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:

	std::string		_target;
	virtual void	performAction() const;

	protected:
	
	
	public:
	
	/*===Canonical Form===*/
	ShrubberyCreationForm(void);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm(const ShrubberyCreationForm& to_copy);
	ShrubberyCreationForm&operator=(const ShrubberyCreationForm& src);
	
	ShrubberyCreationForm(std::string target);
	/*===Getters & Setters===*/
	
	
	/*===Member Function===*/

	class OpenFileExeption : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif