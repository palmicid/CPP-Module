#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	Bureaucrat	pepper("PepperMint", 50);
	Bureaucrat	top("top", 1);
	
	try {
	// 
	// Form	paper;
		AForm	*paper = new ShrubberyCreationForm("ShrubberyTree");
		AForm	*robot = new RobotomyRequestForm("SALT");
		AForm	*president = new PresidentialPardonForm("Taobin");


		std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		pepper.signForm(*paper);
		pepper.signForm(*robot);
		pepper.signForm(*president);
		top.signForm(*paper);
		top.signForm(*robot);
		top.signForm(*president);
		std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		pepper.executeForm(*paper);
		pepper.executeForm(*robot);
		pepper.executeForm(*president);
		top.executeForm(*paper);
		top.executeForm(*robot);
		top.executeForm(*president);
		std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

		delete paper;
		delete robot;
		delete president;
	}
	catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}
}
