
#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie *new_zombies = new Zombie(name);

	return (new_zombies);
}