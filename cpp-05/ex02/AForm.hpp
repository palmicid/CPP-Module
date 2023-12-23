#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>  
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_issigned;
		int	const			_gradeSignedLimit;
		int	const			_gradeExecLimit;
	public:
		AForm();
		AForm(std::string const &, int const &, int const &);
		AForm(AForm const &);
		virtual ~AForm();
		AForm	&operator=(const AForm &);

		// get part
		std::string	getName() const;
		bool		getIssigned() const;
		int			getGradeSignedLimit() const;
		int			getGradeExecLimit() const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		// other function require by subject
		void	beSigned(Bureaucrat &);
	
};

std::ostream	&operator<<(std::ostream &, AForm const &);

#endif
