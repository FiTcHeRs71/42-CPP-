#include "./Bureaucrat/Bureaucrat.hpp"
#include "./Form/Form.hpp"
#include <exception>
#include <iostream>

#define SECTION(title) std::cout << "\n\033[1;36m===== " << title << " =====\033[0m\n" << std::endl

int	main(void)
{
	SECTION("CREATION FORMULAIRE VALIDE + OPERATOR<<");
	{
		Form	f("Budget2024", 50, 30, false);
		std::cout << f << std::endl;
	}

	SECTION("CREATION FORMULAIRE GRADE TROP BAS (> 150)");
	{
		try
		{
			Form	bad("BadForm", 151, 30, false);
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
		try
		{
			Form	bad("BadForm", 50, 200, false);
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	SECTION("CREATION FORMULAIRE GRADE TROP HAUT (< 1)");
	{
		try
		{
			Form	bad("BadForm", 0, 30, false);
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
		try
		{
			Form	bad("BadForm", 50, -1, false);
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	SECTION("SIGNATURE REFUSEE (grade trop faible)");
	{
		Bureaucrat	bob("Bob", 80);
		Form		f("TopSecret", 50, 30, false);

		std::cout << bob << std::endl;
		std::cout << f << std::endl;
		try
		{
			bob.signForm(f);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << f << std::endl;
	}

	SECTION("SIGNATURE REUSSIE (grade suffisant)");
	{
		Bureaucrat	alice("Alice", 30);
		Form		f("TopSecret", 50, 30, false);

		std::cout << alice << std::endl;
		std::cout << f << std::endl;
		try
		{
			alice.signForm(f);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << f << std::endl;
	}

	SECTION("SIGNATURE D'UN FORMULAIRE DEJA SIGNE");
	{
		Bureaucrat	alice("Alice", 1);
		Form		f("AlreadySigned", 50, 30, false);

		alice.signForm(f);
		std::cout << f << std::endl;
		alice.signForm(f);
		std::cout << f << std::endl;
	}

	SECTION("PROMOTION PUIS SIGNATURE");
	{
		Bureaucrat	bob("Bob", 75);
		Form		f("Promo", 74, 60, false);

		std::cout << bob << std::endl;
		std::cout << f << std::endl;
		try
		{
			bob.signForm(f);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		bob.increaseGrade();
		std::cout << bob << std::endl;
		try
		{
			bob.signForm(f);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << f << std::endl;
	}

	SECTION("COPY CONSTRUCTOR ET OPERATOR= FORM");
	{
		Form	f1("Original", 50, 30, false);
		Form	f2(f1);
		Form	f3("Other", 10, 5, false);

		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		f3 = f1;
		std::cout << f3 << std::endl;
	}

	return (0);
}
