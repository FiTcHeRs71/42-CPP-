
#include "Zombie.hpp"

int	main(void)
{
	Zombie	*orgrimmar;
	Zombie	*dalaran;

	orgrimmar = zombieHorde(5, "Orgrimmar");
	dalaran = zombieHorde(10, "Dalaran");

	orgrimmar[0].announce();
	dalaran[9].announce();
	delete [] orgrimmar;
	delete [] dalaran;
}