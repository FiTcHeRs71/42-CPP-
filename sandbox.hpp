
#ifndef SANDBOX_HPP
# define SANDBOX_HPP

#include <iostream>


class student
{
private:
	std::string _name;
	int			_note;

public:
	// Constructeur / Destructeur
	student(void);
	~student(void);

	// Getters → pour LIRE un attribut privé
	std::string getName(void);
	int			getNote(void);

	// Setters → pour MODIFIER un attribut privé
	void	setName(std::string name);
	void	setNote(int note);
};





#endif