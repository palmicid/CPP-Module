#include "AForm.hpp"

AForm::AForm() : _name("Unknown Form"), _issigned(false), _gradeSignedLimit(50), _gradeExecLimit(50) 
{
}

AForm::AForm(std::string const &n, int const &s, int const &lim) : _name(n), _issigned(false), _gradeSignedLimit(s), _gradeExecLimit(lim)
{
	try {
		// but the grade are const TTATT
		if (s < 1) {
			throw AForm::GradeTooHighException();
		}
		else if (s > 150) {
			throw AForm::GradeTooLowException();
		}
	}
	catch (const std::exception& e) {
		std::cout << "Signed limit " << e.what() << '\n';
	}

	try {
		if (lim < 1) {
			throw AForm::GradeTooHighException();
		}
		else if (lim > 150) {
			throw AForm::GradeTooLowException();
		}
	}
	catch (const std::exception& e) {
		std::cout << "Exec limit " << e.what() << '\n';
	}
	
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

std::ostream	&operator<<(std::ostream &out, AForm const &current)
{
	out << "AForm: " << current.getName() << ", Signed grade: " << current.getGradeSignedLimit() << ", Exec grade: " << current.getGradeExecLimit() << ", Is Signed: " << current.getIssigned();
	return out;
}

void	AForm::beSigned(Bureaucrat &crat)
{
	if (_issigned)
		std::cout << "AForm: " << _name << " already signed." << std::endl;
	try {
		if (crat.getGrade() > _gradeSignedLimit) {
			throw AForm::GradeTooLowException();
		}
		_issigned = true;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
