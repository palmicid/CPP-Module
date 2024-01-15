#include "PmergeMe.hpp"

// PmergeMe::PmergeMe() {}

// PmergeMe::PmergeMe(int ac, char** av)
// {
// 	if (init_container(ac, av)) {
// 		std::cout << "Error: init container" << std::endl;
// 		return ;
// 	}
// 	std::cout << "DATA OK" << std::endl;
// }

// PmergeMe::PmergeMe(PmergeMe const &other) 
// {
// 	*this = other;
// }

// PmergeMe&	PmergeMe::operator=(PmergeMe const &other)
// {
// 	if (this == &other)
// 		return *this;
// 	return *this;
// }

// PmergeMe::~PmergeMe() {}

// ================================================================================

bool	cxDataValid(char *raw)
{
	for (int i = 0; raw[i]; i++) {
		if (!isdigit(raw[i]))
			return 1;
	}
	std::string	str(raw);
	if (str.length() == 0)
		return 1;
	return 0;
}

bool	PmergeMe::init_container(int ac, char** av)
{
	for (int i = 1; i < ac; i++) {
		if (cxDataValid(av[i]))
			return 1;
	}
	return 0;
}


