#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	unknown;
	Bureaucrat	pepper("PepperMint", 50);
	Bureaucrat	topOne("top", -1);
	Bureaucrat	lastOne("last", 151);

	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

	std::cout << "Name: " << unknown.getName() << "Grade: " << unknown.getGrade() << std::endl;
	std::cout << "Name: " << pepper.getName() << "Grade: " << pepper.getGrade() << std::endl;
	std::cout << "Name: " << topOne.getName() << "Grade: " << topOne.getGrade() << std::endl;
	std::cout << "Name: " << lastOne.getName() << "Grade: " << lastOne.getGrade() << std::endl;
	
	std::cout << "================== TEST increase ===================" << std::endl;
	std::cout << pepper;
	pepper.incrementGrade();
	std::cout << pepper;
	std::cout << "--------------------------" << std::endl;
	std::cout << topOne;
	topOne.incrementGrade();
	std::cout << topOne ;
	std::cout << "================== TEST decrease ====================" << std::endl;
	std::cout << pepper ;
	pepper.decrementGrade();
	std::cout << pepper ;
	std::cout << "--------------------------" << std::endl;
	std::cout << lastOne ;
	lastOne.decrementGrade();
	std::cout << lastOne ;

}