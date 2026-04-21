
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
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::_info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std ::endl;
}

void	Harl::_warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::_error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) 
{
	switch (std::atoi(level.c_str())) 
	{
		case 1 : 
			this->_warning(void);
		case 2 :
			&info(void);
		
	}
}