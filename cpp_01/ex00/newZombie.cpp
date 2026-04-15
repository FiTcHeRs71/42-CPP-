
#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie *new_zombies = new Zombie();

	new_zombies->setZombieName(name);
	return (new_zombies);
}