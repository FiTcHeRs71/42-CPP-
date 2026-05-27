#include "./Serializer/Serializer.hpp"

int main(void)
{
	Data data = {.pseudo = "admin", .accountLVL = 5, .password = "admin",};
	std::cout << "pseudo:\t\t" << data.pseudo << "\npassword:\t" << data.password << std::endl;

	Data *ptr = &data;
	std::cout << "ptr:\t" << ptr << std::endl;

	uintptr_t raw = Serializer::serialize(ptr);
	std::cout << "raw:\t" << raw << std::endl;

	Data *ptr2 = Serializer::deserialize(raw);
	std::cout << "ptr2:\t" << ptr2 << std::endl;
	std::cout << "pseudo:\t\t" << ptr2->pseudo << "\npassword:\t" << ptr2->password << std::endl;
	return (0);
}