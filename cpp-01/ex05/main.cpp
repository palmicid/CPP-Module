#include <iostream>
#include "Harl.hpp"

int	main(void)
{
	std::string	input;
	Harl	harl;
	
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	return 0;
}