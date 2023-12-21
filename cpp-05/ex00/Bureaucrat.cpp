#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("NoName"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const &name, int num) : _name(name)
{
	
	try
	{
		if (num < 1) {
			_grade = 1;
			throw Bureaucrat::GradeTooHighException();
		}
		else if (num > 150) {
			_grade = 150;
			throw Bureaucrat::GradeTooLowException();
		}
		_grade = num;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
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
	try 
	{
		if ((_grade - 1) < 1)
			throw Bureaucrat::GradeTooHighException();
		_grade--;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::decrementGrade()
{
	try
	{
		if ((_grade + 1) > 150)
			throw Bureaucrat::GradeTooLowException();
		_grade++;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
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
	out << current.getName() << ", bureaucrat grade " << current.getGrade() << std::endl;
	return out;
}
