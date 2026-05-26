#include "./ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

	/*===Canonical Form===*/
ShrubberyCreationForm::ShrubberyCreationForm(void)
	:AForm("ShrubberyCreationForm", 145, 137, false)
	,_target("Default Target")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm default destructor called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& to_copy)
	:AForm(to_copy)
	,_target(to_copy._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	:AForm("ShrubberyCreationForm", 145, 137, false)
	,_target(target)
{
	std::cout << "ShrubberyCreationForm full constructor called" << std::endl;
}
/*===Member Function===*/
void	ShrubberyCreationForm::performAction() const
{
	std::ofstream outfile((_target + std::string("_shrubbery")).c_str());

	if (outfile)
		{
		outfile <<
		"         v" << std::endl <<
		"        >X<" << std::endl <<
		"         A" << std::endl <<
		"        d$b" << std::endl <<
		"      .d\\$$b." << std::endl <<
		"    .d$i$$\\$$b." << std::endl <<
		"       d$$@b" << std::endl <<
		"      d\\$$$ib" << std::endl <<
		"    .d$$$\\$$$b" << std::endl <<
		"  .d$$@$$$$\\$$ib." << std::endl <<
		"      d$$i$$b" << std::endl <<
		"     d\\$$$$@$b" << std::endl <<
		"  .d$@$$\\$$$$$@b." << std::endl <<
		".d$$$$i$$$\\$$$$$$b." << std::endl <<
		"        ###" << std::endl <<
		"        ###" << std::endl <<
		"        ###" << std::endl <<
	std::endl;
	}
	else
	{
		std::cout <<" couldn't execute " << this->getName() << " because ";
		throw OpenFileExeption();
	}
}

const char	*ShrubberyCreationForm::OpenFileExeption::what() const throw()
{
	return ("Could not open and write the file!");
}

