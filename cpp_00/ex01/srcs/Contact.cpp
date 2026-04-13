
#include "../includes/PhoneBook.hpp"

void	Contact::print(void)const
{
	std::cout << std::endl;
	std::cout << "< First name > : \t" << this->_firstName << std::endl;
	std::cout << "< Last name > : \t" << this->_lastName << std::endl;
	std::cout << "< Nick name > : \t" << this->_nickName << std::endl;
	std::cout << "< Phone number > : \t" << this->_phone << std::endl;
	std::cout << "< Darkest secret > : \t" << this->_secret << std::endl;
	std::cout << std::endl;
}

void	print_graphic_tab(std::string corner_l, std::string col, std::string corner_r)
{
	std::cout << corner_l;
	for (int col_index = 0; col_index < 4; col_index++)
	{
		if (col_index)
			std::cout << col;
		for (int i = 0; i < 10; i++)
			std::cout <<"─";
	}
	std::cout << corner_r;
}

static const std::string truncat_str(std::string const str, size_t len)
{
	std::string res(str);

	if (res.size() <= len)
		return (res);
	res.at(len - 1) = '.';
	res.erase(res.begin() + len, res.end());
	return (res);
}

static void	print_col(std::string str, int size)
{
	std::cout << std::setfill(' ') << std::setw(size);
	std::cout << truncat_str(str, size);
	std::cout << "|";
}

void	Contact::printRow(int index) const
{
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << index;
	std::cout << "|";
	print_col(this->_firstName, 10);
	print_col(this->_lastName, 10);
	print_col(this->_nickName, 10);
	std::cout << std::endl;
}