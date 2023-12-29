#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern& copy);
		~Intern();
		Intern& operator=(const Intern& );

		AForm*	makeForm(std::string const & ,std::string const &);

		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};



#endif
