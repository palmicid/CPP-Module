#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("NoTarget")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other), _target(other._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	_target = other._target;
	return (*this);
}

std::string	PresidentialPardonForm::getTarget() const { return (_target); }

void	PresidentialPardonForm::execute(Bureaucrat const &crat) const
{
	AForm::execute(crat);
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}