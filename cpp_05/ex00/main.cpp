#include "./Bureaucrat/Bureaucrat.hpp"
#include <exception>
#include <iostream>

#define SECTION(title) std::cout << "\n\033[1;36m===== " << title << " =====\033[0m\n" << std::endl

int	main(void)
{
	SECTION("CREATION VALIDE + OPERATOR<<");
	{
		Bureaucrat	alice("Alice", 42);
		Bureaucrat	bob("Bob", 1);
		Bureaucrat	charlie("Charlie", 150);

		std::cout << alice << std::endl;
		std::cout << bob << std::endl;
		std::cout << charlie << std::endl;
	}

	SECTION("CONSTRUCTEUR PAR DEFAUT");
	{
		Bureaucrat	def;
		std::cout << def << std::endl;
	}

	SECTION("COPY CONSTRUCTOR");
	{
		Bureaucrat	original("Original", 50);
		Bureaucrat	copy(original);
		std::cout << original << std::endl;
		std::cout << copy << std::endl;
	}

	SECTION("OPERATEUR =");
	{
		Bureaucrat	a("A", 10);
		Bureaucrat	b("B", 100);
		std::cout << "Avant : " << a << " | " << b << std::endl;
		b = a;
		std::cout << "Apres : " << b << std::endl;
	}

	SECTION("CREATION GRADE TROP HAUT (< 1)");
	{
		try
		{
			Bureaucrat	bad("Bad", 0);
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
		try
		{
			Bureaucrat	bad("Bad", -5);
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	SECTION("CREATION GRADE TROP BAS (> 150)");
	{
		try
		{
			Bureaucrat	bad("Bad", 151);
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
		try
		{
			Bureaucrat	bad("Bad", 999);
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	SECTION("INCREASE GRADE (PROMOTION)");
	{
		Bureaucrat	worker("Worker", 5);
		std::cout << worker << std::endl;
		worker.increaseGrade();
		std::cout << worker << std::endl;
		worker.increaseGrade();
		std::cout << worker << std::endl;
	}

	SECTION("INCREASE GRADE A LA LIMITE (grade 1 -> exception)");
	{
		Bureaucrat	top("Top", 1);
		std::cout << top << std::endl;
		try
		{
			top.increaseGrade();
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << top << std::endl;
	}

	SECTION("DEMOTED GRADE (DEGRADATION)");
	{
		Bureaucrat	worker("Worker", 146);
		std::cout << worker << std::endl;
		worker.demotedGrade();
		std::cout << worker << std::endl;
		worker.demotedGrade();
		std::cout << worker << std::endl;
	}

	SECTION("DEMOTED GRADE A LA LIMITE (grade 150 -> exception)");
	{
		Bureaucrat	bottom("Bottom", 150);
		std::cout << bottom << std::endl;
		try
		{
			bottom.demotedGrade();
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << bottom << std::endl;
	}

	return (0);
}
