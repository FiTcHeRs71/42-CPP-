#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

struct Data
{
	std::string	pseudo;
	int			accountLVL;
	std::string	password;
};

class Serializer
{
	public:

	/*===Canonical Form===*/
	Serializer(void);
	~Serializer(void);
	Serializer(const Serializer& to_copy);
	Serializer&operator=(const Serializer& src);

	/*===Member Function===*/
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

};

#endif /*SERIALIZER_HPP*/