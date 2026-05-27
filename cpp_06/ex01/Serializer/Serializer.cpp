# include "Serializer.hpp"

/*===Canonical Form===*/
Serializer::Serializer(void)
{
	std::cout << "Serializer default constructor called" << std::endl;
}
Serializer::~Serializer(void)
{
	std::cout << "Serializer default destructor called" << std::endl;
}
Serializer::Serializer(const Serializer& to_copy)
{
	(void)to_copy;
	std::cout << "Serializer copy constructor called" << std::endl;
}
Serializer & Serializer::operator=(const Serializer& src)
{
	(void)src;
	std::cout << "Serializer assignement operator(=) called" << std::endl;
	return (*this);
}

/*===Member Function===*/
uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}