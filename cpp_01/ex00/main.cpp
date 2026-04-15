
#include "Zombie.hpp"

int main(void)
{
	Zombie	*allocated_zombie;
	randomChump("heap_Zombie");
	allocated_zombie = newZombie("allocated_Zombie");
	allocated_zombie->announce();
	delete (allocated_zombie);
	return (0);
}