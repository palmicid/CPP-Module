#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <exception>
#include <limits>
#include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &);
		ScalarConverter&	operator=(ScalarConverter const &);

	public:
		~ScalarConverter();

		static void		convert(std::string const &);

		class NonDisplayException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class OutofRangeException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif