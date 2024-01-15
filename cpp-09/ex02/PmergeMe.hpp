#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <sstream>
#include <vector>
#include <deque>

// TODO try a container first then change to template

template < class T, class Container = std::vector<int> >
class PmergeMe
{
	private:
		Container					_storage;
	
		PmergeMe();

		bool		init_container(int, char **);
		bool		cxDataValid(char *);
		void		startMergeSort();
		Container	myMergeSort(Container);
		void		small2Big(Container &, Container &, Container&);
	public:
		PmergeMe(int, char **);
		PmergeMe(PmergeMe const &);
		~PmergeMe();

		PmergeMe &operator=(PmergeMe const &);


};
//	START ALOT OF TEMPLATE

template <class T, class Container>
PmergeMe<T, Container>::PmergeMe() {}

template <class T, class Container>
PmergeMe<T, Container>::PmergeMe(int ac, char **av) {
	if (init_container(ac,av)) {
		std::cout << "Error: init container" << std::endl;
		return ;
	}
	startMergeSort();
}

template <class T, class Container>
PmergeMe<T, Container>::PmergeMe(PmergeMe const &other) {
	*this = other;
}

template <class T, class Container>
PmergeMe<T, Container>::~PmergeMe() {}

template <class T, class Container>
PmergeMe<T, Container>&	PmergeMe<T, Container>::operator=(PmergeMe const &other) {
	if (this == &other)
		return *this;
	return *this;
}

// only digit allow and if 
template <class T, class Container>
bool	PmergeMe<T, Container>::cxDataValid(char *raw) {
	for (int i = 0; raw[i]; i++) {
		if (!isdigit(raw[i]))
			return 1;
	}
	std::string str(raw);
	if (str.length() == 0 || str.length() > 10)
		return 1;
	
	// cx in int range
	double	tmp = std::atof(str.c_str());
	if (tmp < 0 || tmp > INT_MAX)
		return 1;

	// add to vector
	_storage.push_back(static_cast<int>(tmp));
	
	return 0;
}

template <class T, class Container>
bool	PmergeMe<T, Container>::init_container(int ac, char **av) {
	// loop send to cx 1 by 1
	for (int i = 1; i < ac; i++) {
		if (cxDataValid(av[i]))
			return 1;
	}

	return 0; 
}

// start of the sort send main storage to recursive function and get result back
template <class T, class Container>
void	PmergeMe<T, Container>::startMergeSort() {
	// init time
	typename Container::iterator	st = _storage.begin();
	typename Container::iterator	ed = _storage.end();

	while (st != ed) {
		std::cout << *st << " ";
		st++;
	}
	std::cout << std::endl;




	// sort
	_storage = myMergeSort(_storage);

	st = _storage.begin();
	ed = _storage.end();

	while (st != ed) {
		std::cout << *st << " ";
		st++;
	}
	std::cout << std::endl;

	// cal time

}

template <class T, class Container>
Container	PmergeMe<T, Container>::myMergeSort(Container c) {
	if (c.size() == 1)
		return c;
	else if (c.size() == 2) {
		typename Container::iterator	it = c.begin();
		if (*it > *(it + 1)) {
			std::swap(it, it + 1);
			return c;
		}
	}
	else {
		int i = c.size();
		typename Container::iterator	it = c.begin();
		Container	con_fwd, con_aft;						// MOST DANGER
		if (i % 2 == 0) {
			con_fwd.insert(con_fwd.end(), c.begin(), it + (i / 2) - 1); 
			con_aft.insert(con_aft.end(), it + (i / 2), c.end());
		} 
		else {
			con_fwd.insert(con_fwd.end(), c.begin(), it + (i / 2)); 
			con_aft.insert(con_aft.end(), it + (i / 2) + 1, c.end());
		}
		con_fwd = myMergeSort(con_fwd);
		con_aft = myMergeSort(con_aft);

		// clear c and add 
		small2Big(c, con_fwd, con_aft);
		return c;
	
	}
}

template <class T, class Container>
void	PmergeMe<T, Container>::small2Big(Container &c, Container &fwd, Container &aft) {
	c.clear();

	typename Container::iterator	con1 = fwd.begin();
	typename Container::iterator	ed1 = fwd.end();
	typename Container::iterator	con2 = aft.begin();
	typename Container::iterator	ed2 = aft.end();

	while (con1 != ed1 || con2 != ed2) {

		if (con1 != ed1 && con2 == ed2) {
			c.push_back(*con1);
			con1++;
		}
		else if (con1 == ed1 && con2 != ed2) {
			c.push_back(*con2);
			con2++;
		}
		else if (*con1 < *con2) {
			c.push_back(*con1);
			con1++;
		}
		else if (*con1 > *con2) {
			c.push_back(*con2);
			con2++;
		}
		else {
			c.push_back(*con1);
			con1++;
		}
	}

	// return c;
}


// template <class T, class Container>
// PmergeMe<T, Container>

#endif