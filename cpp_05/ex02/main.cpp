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
	srand(42);

	SECTION("SHRUBBERY - EXECUTE SANS SIGNATURE (doit echouer)");
	{
		Bureaucrat				bob("Bob", 145);
		ShrubberyCreationForm	form;

		std::cout << bob << std::endl;
		std::cout << form << std::endl;
		try
		{
			bob.executeForm(form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	SECTION("SHRUBBERY - SIGNATURE REFUSEE (grade insuffisant)");
	{
		Bureaucrat				bob("Bob", 146);
		ShrubberyCreationForm	form;

		std::cout << bob << std::endl;
		try
		{
			bob.signForm(form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << form << std::endl;
	}

	SECTION("SHRUBBERY - SIGN + EXECUTE (succes)");
	{
		Bureaucrat				bob("Bob", 137);
		ShrubberyCreationForm	form;

		std::cout << bob << std::endl;
		try
		{
			bob.signForm(form);
			bob.executeForm(form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << form << std::endl;
	}

	SECTION("ROBOTOMY - EXECUTE SANS SIGNATURE (doit echouer)");
	{
		Bureaucrat				alice("Alice", 45);
		RobotomyRequestForm		form;

		std::cout << alice << std::endl;
		try
		{
			alice.executeForm(form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	SECTION("ROBOTOMY - EXECUTE GRADE INSUFFISANT (doit echouer)");
	{
		Bureaucrat				alice("Alice", 46);
		RobotomyRequestForm		form;

		std::cout << alice << std::endl;
		try
		{
			alice.signForm(form);
			alice.executeForm(form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	SECTION("ROBOTOMY - SIGN + EXECUTE X5 (50/50 succes)");
	{
		Bureaucrat			alice("Alice", 1);
		RobotomyRequestForm	form;

		alice.signForm(form);
		for (int i = 0; i < 5; i++)
		{
			try
			{
				alice.executeForm(form);
			}
			catch (std::exception &e)
			{
				std::cout << "Echec: " << e.what() << std::endl;
			}
		}
	}

	SECTION("PRESIDENTIAL PARDON - EXECUTE SANS SIGNATURE (doit echouer)");
	{
		Bureaucrat				president("President", 5);
		PresidentialPardonForm	form;

		std::cout << president << std::endl;
		try
		{
			president.executeForm(form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	SECTION("PRESIDENTIAL PARDON - GRADE INSUFFISANT POUR SIGNER");
	{
		Bureaucrat				president("President", 26);
		PresidentialPardonForm	form;

		std::cout << president << std::endl;
		try
		{
			president.signForm(form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	SECTION("PRESIDENTIAL PARDON - SIGN + EXECUTE (succes)");
	{
		Bureaucrat				president("President", 5);
		PresidentialPardonForm	form;

		std::cout << president << std::endl;
		try
		{
			president.signForm(form);
			president.executeForm(form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	SECTION("COPY + OPERATEUR= SUR LES FORMS");
	{
		ShrubberyCreationForm	s1;
		ShrubberyCreationForm	s2(s1);
		ShrubberyCreationForm	s3;
		s3 = s1;
		std::cout << s1 << std::endl;
		std::cout << s2 << std::endl;
		std::cout << s3 << std::endl;
	}

	return (0);
}
