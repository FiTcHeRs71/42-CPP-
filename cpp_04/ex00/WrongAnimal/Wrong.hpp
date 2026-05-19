#ifndef __WRONG_HPP__
# define __WRONG_HPP__

#include <iostream>
#include <string>

class WrongAnimal
{
	private:


	protected:

	std::string _type;

	public:

	/*===Canonical Form===*/
	WrongAnimal(void);
	virtual ~WrongAnimal(void);
	WrongAnimal(const WrongAnimal& to_copy);
	WrongAnimal&operator=(const WrongAnimal& src);
	WrongAnimal(std::string name);

	/*===Getters & Setters===*/
	std::string	getType(void)const;

	/*===Member Function===*/
	void	makeSound(void);
};

class WrongCat : public WrongAnimal
{
	private:


	protected:


	public:

	/*===Canonical Form===*/
	WrongCat(void);
	~WrongCat(void);
	WrongCat(const WrongCat& to_copy);
	WrongCat&operator=(const WrongCat& src);
	WrongCat(std::string name);

	/*===Getters & Setters===*/
	

	/*===Member Function===*/
};

#endif /*__WRONG_HPP__*/