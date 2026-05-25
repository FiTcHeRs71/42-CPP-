#ifndef __FORM_HPP__
# define __FORM_HPP__

# include <iostream>

class Form
{
	private:

	const std::string	_name;
	bool				_is_signed;
	

	protected:
	

	public:

	/*===Canonical Form===*/
	Form(void);
	~Form(void);
	Form(const Form& to_copy);
	Form&operator=(const Form& src);

	/*===Getters & Setters===*/
	

	/*===Member Function===*/
	
};

#endif /*__FORM_HPP__*/