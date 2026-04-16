
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*horde;

	horde = new Zombie[N];

	for (int idx = 0; idx < N; idx++)
	{
		horde[idx].setZombieName(name);
	}
	return (horde);
}