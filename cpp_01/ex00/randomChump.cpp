
#include "Zombie.hpp"

void	randomChump( std::string name )
{
	Zombie	heap_zombie;

	heap_zombie.setZombieName(name);
	heap_zombie.announce();
}