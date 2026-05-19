#include "./Animal/Animal.hpp"
#include "./Cat/Cat.hpp"
#include "./Dog/Dog.hpp"
#include "./Brain/Brain.hpp"

#define SECTION(title) std::cout << "\n\033[1;36m===== " << title << " =====\033[0m\n" << std::endl


int	main(void)
{
	SECTION("TEST TYPE + MAKE SOUND");
	{
		const Animal* cat = new Cat();
		const Animal* dog = new Dog();

		std::cout << "My type is " << cat->getType() << " and my cries is ";
		cat->makeSound();
		std::cout << std::endl;

		std::cout << "My type is " << dog->getType() << " and my cries is ";
		dog->makeSound();
		std::cout << std::endl;

		delete cat;
		delete dog;
	}
	SECTION("TEST ARRAY OF ANIMAL OBJECT");
	{
		const Animal* animal[10];

		for(int i = 0; i < 10; i++)
		{
			if (i < 5)
				animal[i] = new Cat();
			else
				animal[i] = new Dog();
		}

		std::cout << "My type is " << animal[2]->getType() << " and my cries is ";
		animal[2]->makeSound();

				std::cout << "My type is " << animal[9]->getType() << " and my cries is ";
		animal[9]->makeSound();

		for (int i = 0; i < 10; i++)
		{
			delete animal[i];
		}
	}
	SECTION("TEST BRAIN ACCES");
	{
		const Cat cat;

		std:: cout << cat.getMyBrainIdeas(4) << std::endl;
		std:: cout << cat.getMyBrainIdeas(98) << std::endl;
	}
	return (0);
}
