
#include "includes/HumanA.hpp"
#include "includes/HumanB.hpp"
#include "includes/Weapon.hpp"


int	main(void)
{
	Weapon	sword = Weapon("sword");
	HumanA	anduin = HumanA("Anduin", sword);
	anduin.attack();
	sword.setType("long sword");
	anduin.attack();

	std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;

	Weapon	bow = Weapon("bow");
	HumanB	sylvanas = HumanB("Sylvanas");
	sylvanas.setWeapon(bow);
	sylvanas.attack();
	bow.setType("legendary bow");
	sylvanas.attack();

	return (0);
}

/*int main()
{

	{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	}

	{
	Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
	return 0;
	}

}*/