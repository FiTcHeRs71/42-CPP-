
#include "Zombie.hpp"

void	randomChump( std::string name )
{
	Zombie	heap_zombie = Zombie(name);

	heap_zombie.announce();
}