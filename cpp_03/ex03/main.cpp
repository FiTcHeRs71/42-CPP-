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

		adc.whoAmI();
	}
	return (0);
}