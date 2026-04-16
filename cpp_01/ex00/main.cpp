
#include "Zombie.hpp"

int main(void)
{
	Zombie	*allocated_zombie;
	allocated_zombie = newZombie("allocated_Zombie");
	randomChump("heap_Zombie");
	allocated_zombie->announce();
	delete (allocated_zombie);
	return (0);
}