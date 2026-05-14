#include "./ClapTrap/ClapTrap.hpp"
#include "./FragTrap/FragTrap.hpp"
#include "./DiamondTrap/DiamondTrap.hpp"
#include "./ScavTrap/ScavTrap.hpp"

#define SECTION(title) std::cout << "\n\033[1;36m===== " << title << " =====\033[0m\n" << std::endl

int	main(void)
{
	SECTION("TEST DIAMOND TRAP");
	{
		DiamondTrap	adc("Jinx");
		DiamondTrap	supp(adc);

		adc.whoAmI();
		supp.whoAmI();
	}
	SECTION("TEST DIAMOND TRAP");
	{
		DiamondTrap	mid("Akali");
		DiamondTrap	jung("Xin");
		DiamondTrap	bot;

		bot = jung;

		mid.attack("Xin");
		jung.takeDamage(20);
		bot.guardGate();
		bot.whoAmI();
		bot.highFiveGuys();
	}
	return (0);
}