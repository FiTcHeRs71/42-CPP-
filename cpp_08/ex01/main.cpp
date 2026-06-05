#include "./Span/Span.hpp"
#include <climits>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <ostream>

#define SECTION(title) std::cout << "\n\033[1;36m===== " << title << " =====\033[0m\n" << std::endl

int	main(void)
{
	srand(time(NULL));
	SECTION("TEST MAIN INTRA");
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	SECTION("TEST ARRAY WITH ALL SAME ELEMENTS");
	{
		Span sp = Span(5);

		sp.addNumber(1);
		sp.addNumber(1);
		sp.addNumber(1);
		sp.addNumber(1);
		sp.addNumber(1);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	SECTION("TEST TRY CATCH");
	{
		Span sp = Span(5);

		try
		{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(22);
		}
		catch (std::exception &e)
		{
			std::cout << "/!\\Exception caught -> " << e.what() << std::endl;
		}
	}
	SECTION("TEST 10 000");
	{
		Span sp = Span(10000);

		try
		{
			std::vector<int> v;
			for (int i = 0; i < 10000; ++i)
				v.push_back(rand());
			sp.addRange(v.begin(), v.end());
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "/!\\Exception caught -> " << e.what() << std::endl;
		}
	}
	return (0);
}