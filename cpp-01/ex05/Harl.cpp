#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "[ Harl ] : Hello" << std::endl;
}

Harl::~Harl()
{
	std::cout << "[ Harl ] : Bye Bye" << std::endl;
}

void	Harl::debug( void )
{
	std::cout << "[ Harl ] : (debug) love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[ Harl ] : (info) cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[ Harl ] : (warning) think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void	Harl::error( void )
{
	std::cout << "[ Harl ] : (error) This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain (std::string level)
{
	std::string	arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl:: *ptrToFn[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (level.compare(arr[i]) == 0)
			(this->*ptrToFn[i])();
	}
}