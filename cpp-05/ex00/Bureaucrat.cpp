#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("NoName"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const &name, int num) : _name(name), _grade(num)
{
	if (num < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (num > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this == &other)
		return (*this);
	_grade = other.getGrade();
	return (*this);
}

std::string Bureaucrat::getName() const { return (_name); }
int			Bureaucrat::getGrade() const { return (_grade); }

void	Bureaucrat::incrementGrade()
{
	if ((_grade - 1) < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if ((_grade + 1) > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &current)
{
	out << current.getName() << ", bureaucrat grade " << current.getGrade();
	return out;
}

