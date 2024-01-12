#include "BitcoinExchange.hpp"


// must take an argument
int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << " input example \n ./btc [intput_file]" << std::endl;
		return 0;
	}
	try {
		BitcoinExchange	bittest(av[1]);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	// open file read can open with .csv and .txt 
	// .csv sep by comma
	// .txt sep by  |
	// 

	return 0;
}