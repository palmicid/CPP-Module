#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	Bureaucrat	pepper("PepperMint", 50);
	Bureaucrat	top("Im-No-1", 1);
	Intern		tart;

	// I'm lazy so I create this
	std::string	name[4] = { "ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm","NotFound" };
	
	try {
	// 
	// Form	paper;
		// AForm	*paper = new ShrubberyCreationForm("ShrubberyTree");
		// AForm	*robot = new RobotomyRequestForm("SALT");
		// AForm	*president = new PresidentialPardonForm("Taobin");
		AForm	*paper = tart.makeForm(name[1], "BobTheTarget");
		if (paper) {
			pepper.executeForm(*paper);
			pepper.signForm(*paper);
			top.executeForm(*paper);
			std::cout << "================ START ====================" << std::endl;
			top.signForm(*paper);
			std::cout << "---------------- EXEC ---------------------" << std::endl;
			top.executeForm(*paper);
			std::cout << "-------------------------------------------" << std::endl;
			std::cout << "================= TEST PRINT =====================" << std::endl;
			std::cout << *paper << std::endl;
			// for (int i = 0; i < 100; i++) {
			// 	std::cout << "---------------------" << std::endl;
			// 	top.executeForm(*paper);
			// }
			delete paper;
		}

		std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

	}
	catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}
}
