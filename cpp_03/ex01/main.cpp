#include "./ClapTrap/ClapTrap.hpp"
#include "./ScavTrap/ScavTrap.hpp"

#define SECTION(title) std::cout << "\n\033[1;36m===== " << title << " =====\033[0m\n" << std::endl

int	main(void)
{
	SECTION("TEST SCAV TRAP");
	{
		ScavTrap	top;
		ScavTrap	mid("Akali");

		mid.attack("Default");
		top.takeDamage(20);
		top.beRepaired(10);
		top.guardGate();
		mid.attack("Default");
		top.takeDamage(20);
	}
	return (0);
}