#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern::~Intern()
{}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return ("Form Not Found");
}

AForm*	Intern::makeForm(std::string const &formName, std::string const &target)
{
	std::string arr[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm" };
	for (int i = 0; i < 3; i++) {
		if (formName.compare(arr[i]) == 0) {
			std::cout << "Intern creates " << arr[i] << std::endl;
			switch (i)
			{
				case 0:
					return (new ShrubberyCreationForm(target));	
				case 1:
					return (new RobotomyRequestForm(target));
				case 2:
					return (new PresidentialPardonForm(target));
				default:
					break;
			}
		}
	}
	throw FormNotFoundException();
}
