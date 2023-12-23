#include "Bureaucrat.hpp"

int	main()
{
	try {
	Bureaucrat	unknown;
	Bureaucrat	pepper("PepperMint", 50);
	// change pepermint grade to test increment and decrement
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << unknown << std::endl;
	std::cout << pepper << std::endl;

	pepper.incrementGrade();
	std::cout << pepper << std::endl;
	pepper.decrementGrade();
	std::cout << pepper << std::endl;

	}
	catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}



}