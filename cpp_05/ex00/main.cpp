#include "./Bureaucrat/Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <ostream>

#define SECTION(title) std::cout << "\n\033[1;36m===== " << title << " =====\033[0m\n" << std::endl

int	main(void)
{
	SECTION("TEST DOWNGRADE GRADE LESS THEN 1");
	{
		Bureaucrat	dummy("dummy", 1);

		std::cout << dummy << std::endl;
		try
		{
			dummy.increaseGrade();
		}
		catch (std::exception &dummy)
		{
			std::cout << "Exception caught:" << dummy.what() << std::endl;
		}
		std::cout << dummy << std::endl;
	}
	SECTION("TEST INCREASE GRADE MORE THEN 150");
	{
		Bureaucrat	dummy("dummy", 150);
		std::cout << dummy << std::endl;
		try
		{
			dummy.demotedGrade();
		}
		catch (std::exception &dummy)
		{
			std::cout << "Exception caught:" << dummy.what() << std::endl;
		}
		std::cout << dummy << std::endl;
	}
	return (0);
}