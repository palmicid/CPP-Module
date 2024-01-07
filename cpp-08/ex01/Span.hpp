#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>

class Span
{
	private:
		unsigned int		_size;
		std::vector<int>	_storage;
	public:
		Span();
		Span(unsigned int);
		Span(Span const &);
		~Span();

		Span&	operator=(Span const &);
		void	addNumber(int);
		void	addNumber(std::vector<int>::iterator const &, std::vector<int>::iterator const &);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		// helper function
		bool	cx_exist(std::vector<int>::iterator const &, std::vector<int>::iterator const &, int);

		class SameNumberException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class StorageFullException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class NoSpanFoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		void printVector();
};


#endif