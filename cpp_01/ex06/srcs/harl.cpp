
#include "../includes/harl.hpp"


Harl::Harl()
{
	std::cout << "default Harl class constructor called" << std::endl;
}

Harl::~Harl()
{
	std::cout << "default Harl class destructor called" << std::endl;
}

void	Harl::_debug(void)
{
	std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::_info(void)
{
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std ::endl;
}

void	Harl::_warning(void)
{
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::_error(void)
{
	std::cout << "[ERROR]\nThis is unacceptable!\nI want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) 
{
	std::string	complains[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			idx = -1;

	for (int i = 0; i < 4; i++)
	{
		if (level == complains[i])
		{
			idx = i;
		}
	}

	switch (idx)
	{
		case 0 :
			this->_debug();
		case 1 :
			this->_info();
		case 2 : 
			this->_warning();
		case 3 :
			this->_error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]";
	}
}