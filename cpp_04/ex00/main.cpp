
#include "./Animal/Animal.hpp"
#include "./Cat/Cat.hpp"
#include "./Dog/Dog.hpp"
#include "./WrongAnimal/Wrong.hpp"

#define SECTION(title) std::cout << "\n\033[1;36m===== " << title << " =====\033[0m\n" << std::endl

int	main(void)
{
	SECTION("POLYMORPH NORMAL");
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	SECTION("WRONG ANIMAL");
	{
		const WrongAnimal meta = WrongAnimal();
		const WrongAnimal cat = WrongCat();

		meta.makeSound();
	}
	return (0);
}