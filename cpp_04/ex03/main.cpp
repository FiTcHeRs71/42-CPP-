/*#include "./AMateria/AMateria.hpp"
#include "./Ice_Cure/Ice_Cure.hpp"
#include "./ICharacter/ICharacter.hpp"

#define SECTION(title) std::cout << "\n\033[1;36m===== " << title << " =====\033[0m\n" << std::endl

int	main(void)
{
	SECTION("TEST INTRA (sujet)");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	SECTION("COPIE PROFONDE - copy constructor");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());

		Character original("original");
		original.equip(src->createMateria("ice"));

		Character clone(original);

		ICharacter* dummy = new Character("dummy");

		std::cout << "-- original utilise son slot 0 --" << std::endl;
		original.use(0, *dummy);
		std::cout << "-- clone utilise son slot 0 --" << std::endl;
		clone.use(0, *dummy);

		delete dummy;
		delete src;
	}

	SECTION("COPIE PROFONDE - operator=");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Cure());

		Character a("a");
		a.equip(src->createMateria("cure"));

		Character b("b");
		b.equip(src->createMateria("cure"));
		std::cout << "-- avant affectation --" << std::endl;
		b = a;

		ICharacter* dummy = new Character("dummy");
		std::cout << "-- b utilise son slot 0 apres b = a --" << std::endl;
		b.use(0, *dummy);

		delete dummy;
		delete src;
	}

	SECTION("INVENTAIRE PLEIN (5e equip ignore)");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());

		ICharacter* me = new Character("me");
		me->equip(src->createMateria("ice"));
		me->equip(src->createMateria("ice"));
		me->equip(src->createMateria("ice"));
		me->equip(src->createMateria("ice"));

		AMateria* overflow = src->createMateria("ice");
		me->equip(overflow);
		std::cout << "-- equip sur inventaire plein : rien ne se passe --" << std::endl;

		delete me;
		delete src;
	}

	SECTION("INDEX INVALIDE (use / unequip)");
	{
		ICharacter* me = new Character("me");
		ICharacter* target = new Character("target");

		std::cout << "-- use(0) sur slot vide : rien --" << std::endl;
		me->use(0, *target);
		std::cout << "-- use(-1) et use(99) : rien, pas de crash --" << std::endl;
		me->use(-1, *target);
		me->use(99, *target);
		std::cout << "-- unequip(-1) et unequip(99) : rien, pas de crash --" << std::endl;
		me->unequip(-1);
		me->unequip(99);

		delete me;
		delete target;
	}

	SECTION("UNEQUIP (ne delete pas : a liberer soi-meme)");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());

		ICharacter* me = new Character("me");
		AMateria* mat = src->createMateria("ice");
		me->equip(mat); // slot 0

		me->unequip(0);
		std::cout << "-- Materia retiree : on la libere a la main --" << std::endl;
		delete mat;

		delete me;
		delete src;
	}

	SECTION("CREATEMATERIA TYPE INCONNU (renvoie NULL)");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());

		AMateria* unknown = src->createMateria("fire");
		if (unknown == NULL)
			std::cout << "createMateria(\"fire\") a bien renvoye NULL" << std::endl;
		else
		{
			std::cout << "ERREUR : devrait etre NULL" << std::endl;
			delete unknown;
		}

		delete src;
	}

	return (0);
} */

#include "./AMateria/AMateria.hpp"
#include "./Ice_Cure/Ice_Cure.hpp"
#include "./ICharacter/ICharacter.hpp"

#define SECTION(title) std::cout << "\n\033[1;36m===== " << title << " =====\033[0m\n" << std::endl

#include <iostream>

void subject_provided_test()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

void copy_constructor_test()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	Character me("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me.equip(tmp);
	tmp = src->createMateria("cure");
	me.equip(tmp);
	Character copy(me);
	me.unequip(0);
	me.use(0, copy);
	copy.use(0, me);
	delete src;
}

void assignment_operator_test()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	Character me("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me.equip(tmp);
	tmp = src->createMateria("cure");
	me.equip(tmp);
	Character copy;
	copy = me;
	me.unequip(0);
	me.use(0, copy);
	copy.use(0, me);
	delete src;
}

void invalid_arguments_test()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(0);
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("nonexistant");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->unequip(-1);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(-1, *bob);
	me->use(2, *bob);
	delete bob;
	delete me;
	delete src;
}

int main()
{
	//subject_provided_test();
	//copy_constructor_test();
	assignment_operator_test();
	//invalid_arguments_test();
	return 0;
}