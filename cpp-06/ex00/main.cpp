#include <iostream>
// #include <cstdlib>
#include "ScalarConverter.hpp"


int	main(int ac, char **av)
{
	if (ac != 2	) {
		std::cout << "***input the number like this ***" << std::endl;
		std::cout << "  ./converter [number]  " << std::endl;
		exit(1);
	}
	ScalarConverter::convert(av[1]);



	return 0;
}