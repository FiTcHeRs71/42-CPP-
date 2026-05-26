#include "./Bureaucrat/Bureaucrat.hpp"
#include "./Form/AForm.hpp"
#include "./Form/ShrubberyCreationForm.hpp"
#include "./Form/RobotomyRequestForm.hpp"
#include "./Form/PresidentialPardonForm.hpp"
#include <exception>
#include <iostream>
#include <cstdlib>

#define SECTION(title) std::cout << "\n\033[1;36m===== " << title << " =====\033[0m\n" << std::endl

int	main(void)
{
	srand(time(NULL));
	SECTION("SHRUBBERY CREATION FORM");
	{
		Bureaucrat				high("High", 1);
		Bureaucrat				low("Low", 150);
		ShrubberyCreationForm	form;

		std::cout << form << std::endl;
		try
		{
			low.signForm(form);    // grade trop bas -> echec
			high.signForm(form);   // sortet ne fais pas avec lexception
			high.executeForm(form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			high.signForm(form);   // signature OK
			high.executeForm(form); // execution OK -> ecrit le fichier
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	SECTION("ROBOTOMY REQUEST FORM");
	{
		Bureaucrat			high("High", 1);
		RobotomyRequestForm	form;

		std::cout << form << std::endl;
		try
		{
			//high.executeForm(form); // pas signe -> echec
			high.signForm(form);
			for (int i = 0; i < 5; i++)
			{
				try
				{
					high.executeForm(form); // 50/50
				}
				catch (std::exception &e)
				{
					std::cout << "Echec: " << e.what() << std::endl;
				}
			}
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	SECTION("PRESIDENTIAL PARDON FORM");
	{
		Bureaucrat				high("High", 1);
		Bureaucrat				low("Low", 150);
		PresidentialPardonForm	form;

		std::cout << form << std::endl;
		try
		{
			high.signForm(form);   // signature OK
			high.executeForm(form); // execution OK
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return (0);
}
