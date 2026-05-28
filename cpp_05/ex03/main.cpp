#include "./Bureaucrat/Bureaucrat.hpp"
#include "./Form/AForm.hpp"
#include "./Form/ShrubberyCreationForm.hpp"
#include "./Form/RobotomyRequestForm.hpp"
#include "./Form/PresidentialPardonForm.hpp"
#include "./Intern/Intern.hpp"
#include <exception>
#include <iostream>
#include <cstdlib>

#define SECTION(title) std::cout << "\n\033[1;36m===== " << title << " =====\033[0m\n" << std::endl

int	main(void)
{
	srand(time(NULL));
	SECTION("SHRUBBERY CREATION FORM BY INTERN");
	{
		Bureaucrat				high("High", 1);
		Bureaucrat				low("Low", 150);
		Intern					intern;
		AForm					*form = intern.makeForm("ShrubberyCreationForm", "Shrubbery");


		std::cout << *form << std::endl;
		std::cout << "=== Failed ===" << std::endl;
		try
		{
			low.signForm(*form);    // grade trop bas -> echec
			high.signForm(*form);   // sortet ne fais pas avec lexception
			high.executeForm(*form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "=== Succes ===" << std::endl;
		try
		{
			high.signForm(*form);   // signature OK
			high.executeForm(*form); // execution OK -> ecrit le fichier
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		delete form;
	}

	SECTION("ROBOTOMY REQUEST FORM BY INTERN");
	{
		Bureaucrat			high("High", 1);
		Intern				intern;
		AForm				*form = intern.makeForm("RobotomyRequestForm", "robotization");

		std::cout << *form << std::endl;
		try
		{
			//high.executeForm(*form); // pas signe -> echec
			high.signForm(*form);
			for (int i = 0; i < 5; i++)
			{
				try
				{
					high.executeForm(*form); // 50/50
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
		delete form;
	}

	SECTION("PRESIDENTIAL PARDON FORM BY INTERN");
	{
		Bureaucrat				high("High", 1);
		Bureaucrat				low("Low", 150);
		Intern					intern;
		AForm					*form = intern.makeForm("PresidentialPardonForm", "Presidential");

		std::cout << *form << std::endl;
		try
		{
			high.signForm(*form);   // signature OK
			high.executeForm(*form); // execution OK
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		delete form;
	}

	return (0);
}