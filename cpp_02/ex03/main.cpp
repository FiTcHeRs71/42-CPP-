
#include "includes/Point.hpp"

int	main(void)
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	std::cout << bsp(a, b, c, Point(2, 2))    << " (attendu 1)" << std::endl;
	std::cout << bsp(a, b, c, Point(20, 20))  << " (attendu 0)" << std::endl;
	std::cout << bsp(a, b, c, Point(0, 0))    << " (attendu 0, sommet)" << std::endl;
	std::cout << bsp(a, b, c, Point(5, 0))    << " (attendu 0, bord)" << std::endl;
	std::cout << bsp(a, b, c, Point(5, 5))    << " (attendu 0, hypoténuse)" << std::endl;
}