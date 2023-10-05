#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

void    Harl::debug(void)
{
    std::cout << "what the hell is gooooing on" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "You wanna know what's up? I'm whats up" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "This is getting really really bad dude" << std::endl;
}

void    Harl::error(void)
{
    std::cout << "what the fuck did you just do?" << std::endl;
}

void    Harl::complain(std::string level)
{
    void		(Harl::*ptr_complain[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"debug", "info", "warning", "error"};
    int i;

    i = 0;

    while (levels[i] != level && i < 4)
        i++;
    (this->*ptr_complain[i])();
	
	}

