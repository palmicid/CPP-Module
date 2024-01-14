#include "RPN.hpp"


int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "put input in double quote" << std::endl;
		return 0;
	}
	// std::cout << av[1] << std::endl;
	std::string	str = av[1];
	RPN first(str);



	return 0;
}