#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <iostream>


class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw() {
			return ("Not found");
		}

};

template <typename T>	void	easyfind(T& container, int n);

#include "Easyfind.tpp"

#endif