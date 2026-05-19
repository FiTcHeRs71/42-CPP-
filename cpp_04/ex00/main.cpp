
#include "./Animal/Animal.hpp"
#include "./Cat/Cat.hpp"
#include "./Dog/Dog.hpp"
#include "./WrongAnimal/Wrong.hpp"

#define SECTION(title) std::cout << "\n\033[1;36m===== " << title << " =====\033[0m\n" << std::endl

int	main(void)
{
	SECTION("POLYMORPH NORMAL // INTRA TEST");
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	SECTION("WRONG ANIMAL");
	{
		//const WrongAnimal* meta = new WrongAnimal();
		WrongAnimal* cat = new WrongCat();

		std::cout << cat->getType() << " " << std::endl;
		cat->makeSound();

		delete cat;
	}
	return (0);
}