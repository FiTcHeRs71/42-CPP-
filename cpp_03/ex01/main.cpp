#include "./ClapTrap/ClapTrap.hpp"
#include "./ScavTrap/ScavTrap.hpp"

#define SECTION(title) std::cout << "\n\033[1;36m===== " << title << " =====\033[0m\n" << std::endl

int	main(void)
{
	/*SECTION("TEST CLAP TRAP");
	{
	ClapTrap	bot("Jinx");
	ClapTrap	supp("Alistar");

	bot.attack("test");
	supp.takeDamage(bot.getAttackDamage());
	bot.setAttackDamage(5);
	bot.attack("test");
	supp.takeDamage(bot.getAttackDamage());
	bot.attack("test");
	supp.takeDamage(bot.getAttackDamage());
	bot.attack("test");
	supp.takeDamage(bot.getAttackDamage());
	supp.beRepaired(5);
	}*/
	SECTION("TEST SCAV TRAP");
	{
		ScavTrap	top;
		ScavTrap	mid("Akali");
		ScavTrap	jung = mid;

		mid.attack("test");
		jung.attack("test");
		top.takeDamage(20);
	}
}