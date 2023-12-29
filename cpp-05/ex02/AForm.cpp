#include "AForm.hpp"

AForm::AForm() : _name("Unknown AForm"), _issigned(false), _gradeSignedLimit(50), _gradeExecLimit(50) 
{
}

AForm::AForm(std::string const &n, int const &s, int const &lim) : _name(n), _issigned(false), _gradeSignedLimit(s), _gradeExecLimit(lim)
{
	if (s < 1 || lim < 1)
		throw GradeTooHighException();
	if (s > 150 || lim > 150)
		throw GradeTooLowException();

}

AForm::AForm(AForm const &other) : _name(other.getName()), _gradeSignedLimit(other.getGradeSignedLimit()), _gradeExecLimit(other.getGradeExecLimit())
{
	_issigned = other.getIssigned();
}

AForm::~AForm()
{}

AForm	&AForm::operator=(AForm const &other)
{
	if (this == &other)
		return *this;
	_issigned = other.getIssigned();
	return (*this);
}

std::string	AForm::getName() const { return _name; }
bool	AForm::getIssigned() const { return _issigned; }
int		AForm::getGradeSignedLimit() const { return _gradeSignedLimit; }
int		AForm::getGradeExecLimit() const { return _gradeExecLimit; }

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *AForm::AlreadySignException::what() const throw()
{
	return ("Form already signed");
}

const char *AForm::NotSignException::what() const throw()
{
	return ("Form not sign");
}

std::ostream	&operator<<(std::ostream &out, AForm const &current)
{
	out << "AForm: " << current.getName() << ", Signed grade: " << current.getGradeSignedLimit() << ", Exec grade: " << current.getGradeExecLimit() << ", Is Signed: " << current.getIssigned();
	return out;
}

void	AForm::beSigned(Bureaucrat &crat)
{
	if (_issigned)
		throw AForm::AlreadySignException();
	else if (crat.getGrade() > _gradeSignedLimit) {
		throw AForm::GradeTooLowException();
	}
	_issigned = true;
}

void	AForm::execute(Bureaucrat const & crat) const
{
	if (!_issigned)
		throw NotSignException();
	if (crat.getGrade() > _gradeExecLimit)
		throw GradeTooLowException();
}
