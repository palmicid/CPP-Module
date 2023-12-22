#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	petch("petch", 25);
	Bureaucrat	top("top", 1);
	Bureaucrat	buby("buby", 150);

	Form		secret("secret mission", 1, 1);
	Form		normal;
	Form		brokenHigh("broken high", 0, 100);
	Form		brokenLow("broken low", 151, 100);

	std::cout << secret << std::endl;
	std::cout << brokenHigh << std::endl;
	std::cout << brokenLow << std::endl;
	
	std::cout << "============ START TEST ================" << std::endl;
	std::cout << "===== TEST grade lower =====" << std::endl;
	buby.signForm(normal);
	std::cout << normal << std::endl;
	std::cout << std::endl;

	std::cout << "===== TEST grade higher: can sign the form =====" << std::endl;
	petch.signForm(normal);
	std::cout << normal << std::endl;
	std::cout << std::endl;
	top.signForm(secret);
	std::cout << secret << std::endl;

	return 0;
}