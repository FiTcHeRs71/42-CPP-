#include "./ClapTrap/ClapTrap.hpp"
#include "./FragTrap/FragTrap.hpp"

#define SECTION(title) std::cout << "\n\033[1;36m===== " << title << " =====\033[0m\n" << std::endl

int	main(void)
{
	SECTION("TEST FRAGTRAP CANONICAL FORM");
	{
		FragTrap	top("ORNN");
		FragTrap	jung(top);
		FragTrap	mid = jung;

		top.attack("random player");
		mid.attack("a stupid bronze");
	}
	SECTION("TEST FRAGTRAP FULL CONSTRUCTOR");
	{
		FragTrap	adc("Jinx");
		FragTrap	supp;

		adc.attack("Teemo");
		supp.attack("Thresh");
	}
	SECTION("TEST FRAGTRAP HIGH FIVE");
	{
		FragTrap	coach("Kkoma");

		coach.highFiveGuys();
	}
	return (0);
}