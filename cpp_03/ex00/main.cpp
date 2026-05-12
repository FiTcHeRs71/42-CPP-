#include "./ClapTrap/ClapTrap.hpp"

int	main(void)
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
	return (0);
}