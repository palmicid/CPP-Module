#include <iostream>
#include <string>
#include "MySed.hpp"

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		MySed box(av[1], av[2], av[3]);
		box.myReplace();
	}
	else
	{
		std::cout << "Plz run cmd like this" << std::endl;
		std::cout << "./Sed4losers <filename> <OriStr> <Str2Replace>" << std::endl;
	}
	return (0);
}