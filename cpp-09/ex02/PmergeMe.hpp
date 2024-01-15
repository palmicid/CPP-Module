#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <sys/time.h>
#include <climits>
#include <vector>
#include <deque>
#include <ctime>
#include <iomanip>

template < class T, class Container = std::vector<int> >
class PmergeMe
{
	private:
		Container	_storage;
		double		_timeuse;
		size_t		_size;

		PmergeMe();

		bool		init_container(int, char **);
		bool		cxDataValid(char *);
		Container	myMergeSort(Container);
		void		small2Big(Container &, Container &, Container&);
		bool		cxSorted();
		void		toInsertion(Container &);
	public:
		PmergeMe(int, char **);
		PmergeMe(PmergeMe const &);
		~PmergeMe();

		PmergeMe 	&operator=(PmergeMe const &);

		double		getTimeuse() const;
		size_t		getSize() const;
		
		void		startMergeSort();
		void		printStorage();
		void		printMessage(std::string const &) const;
};


//	START ALOT OF TEMPLATE

template <class T, class Container>
double	PmergeMe<T, Container>::getTimeuse() const { return _timeuse; }

template <class T, class Container>
size_t	PmergeMe<T, Container>::getSize() const { return _size; }

template <class T, class Container>
void	PmergeMe<T, Container>::printStorage()
{
	typename Container::iterator	st = _storage.begin();
	typename Container::iterator	ed = _storage.end();

	while (st != ed) {
		std::cout << *st << ' ';
		st++;
	}
	std::cout << std::endl;
}

template <class T, class Container>
void	PmergeMe<T, Container>::printMessage(std::string const &cname) const 
{
	std::cout << "Time to process a range of " << _size << " elements with std::" << cname << " : " << std::fixed << std::setprecision(5) << _timeuse << " us" << std::endl;
}


template <class T, class Container>
bool	PmergeMe<T, Container>::cxSorted() {
	typename Container::iterator	st = _storage.begin();
	typename Container::iterator	ed = _storage.end();
	typename Container::iterator	nx = st;

	nx++;
	while (nx != ed) {
		if (*st > *nx)
			return 1;
		st++;
		nx++;
	}
	return 0;
}


template <class T, class Container>
PmergeMe<T, Container>::PmergeMe() {}

template <class T, class Container>
PmergeMe<T, Container>::PmergeMe(int ac, char **av) {
	if (init_container(ac,av)) {
		std::cout << "Error: init container" << std::endl;
		return ;
	}
	_size = _storage.size();
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
	std::clock_t	st = std::clock();
	// sort
	_storage = myMergeSort(_storage);
	_timeuse = static_cast<double>(std::clock() - st) / CLOCKS_PER_SEC;
	// cal time


}

template <class T, class Container>
Container	PmergeMe<T, Container>::myMergeSort(Container c) {

	if (c.size() <= 50) {
		toInsertion(c);
		return c;
	}

	int i = c.size();
	typename Container::iterator	it = c.begin();
	Container	con_fwd, con_aft;						// MOST DANGER
	if (i % 2 == 0) {
		con_fwd.insert(con_fwd.end(), c.begin(), it + (i / 2));
		con_aft.insert(con_aft.end(), it + (i / 2), c.end());
	} 
	else {
		con_fwd.insert(con_fwd.end(), c.begin(), it + (i / 2) + 1); 
		con_aft.insert(con_aft.end(), it + (i / 2 + 1), c.end());
	}

	con_fwd = myMergeSort(con_fwd);
	con_aft = myMergeSort(con_aft);

	// clear c and add 
	small2Big(c, con_fwd, con_aft);

	return c;
}

template <class T, class Container>
void	PmergeMe<T, Container>::small2Big(Container &c, Container &fwd, Container &aft) {
	c.clear();

	typename Container::iterator	con1 = fwd.begin();
	typename Container::iterator	ed1 = fwd.end();
	typename Container::iterator	con2 = aft.begin();
	typename Container::iterator	ed2 = aft.end();

	while (con1 != ed1 || con2 != ed2)
	{
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

}


template <class T, class Container>
void	PmergeMe<T, Container>::toInsertion(Container &c)
{
	typename Container::iterator	st = c.begin();
	typename Container::iterator	ed = c.end();
	typename Container::iterator	nx;
	typename Container::iterator	tmp;				// for store where iter min is
	T								min;

	while (st != (ed - 1)) {
		min = *st;
		tmp = st;
		nx = st + 1;
		while (nx != ed) {
			if (min > *nx) {
				tmp = nx;
				min = *nx;
			}
			nx++;
		}
		if (st != tmp)
			std::iter_swap(st, tmp);
		st++;
	}

}

#endif