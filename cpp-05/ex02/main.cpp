#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	pepper("PepperMint", 50);
	Bureaucrat	top("top", 1);
	
	try {
	// 
	// Form	paper;
		Form	paper("Test mission", 10, 50);

		std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		pepper.signForm(paper);
		top.signForm(paper);
		// test already sign
		top.signForm(paper);
	}
	catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}
}