#include "Form.hpp"

Form::Form() : _name("Unknown Form"), _issigned(false), _gradeSignedLimit(50), _gradeExecLimit(50) 
{
}

Form::Form(std::string const &n, int const &s, int const &lim) : _name(n), _issigned(false), _gradeSignedLimit(s), _gradeExecLimit(lim)
{
	if (s < 1 || lim < 1)
		throw GradeTooHighException();
	if (s > 150 || lim > 150)
		throw GradeTooLowException();

}

Form::Form(Form const &other) : _name(other.getName()), _gradeSignedLimit(other.getGradeSignedLimit()), _gradeExecLimit(other.getGradeExecLimit())
{
	_issigned = other.getIssigned();
}

Form::~Form()
{}

Form	&Form::operator=(Form const &other)
{
	if (this == &other)
		return *this;
	_issigned = other.getIssigned();
	return (*this);
}

std::string	Form::getName() const { return _name; }
bool	Form::getIssigned() const { return _issigned; }
int		Form::getGradeSignedLimit() const { return _gradeSignedLimit; }
int		Form::getGradeExecLimit() const { return _gradeExecLimit; }

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *Form::AlreadySignException::what() const throw()
{
	return ("form already signed");
}

std::ostream	&operator<<(std::ostream &out, Form const &current)
{
	out << "Form: " << current.getName() << ", Signed grade: " << current.getGradeSignedLimit() << ", Exec grade: " << current.getGradeExecLimit() << ", Is Signed: " << current.getIssigned();
	return out;
}

void	Form::beSigned(Bureaucrat &crat)
{
	if (_issigned)
		throw Form::AlreadySignException();
	else if (crat.getGrade() > _gradeSignedLimit) {
		throw Form::GradeTooLowException();
	}
	_issigned = true;
}
