#include "Span.hpp"

Span::Span() : _size(0)
{}

Span::Span(unsigned int size) : _size(size)
{
}

Span::Span(Span const &other)
{
	*this = other;
}

Span::~Span() {}

Span&	Span::operator=(Span const &other)
{
	if (this != &other) {
		_storage.clear();
		_size = other._size;
		_storage = other._storage;
	}
	return *this;
}

// return true if found
bool	Span::cx_exist(std::vector<int>::iterator const &st, std::vector<int>::iterator const &ed, int toFind)
{
	return (std::find(st, ed, toFind) != _storage.end());
}

void	Span::addNumber(int toAdd)
{
	// cx if the storage is full
	if (_storage.size() >= _size) {
		throw Span::StorageFullException();
	}	//cx if the number already exist
	if (!cx_exist(_storage.begin(), _storage.end(), toAdd)) {
		_storage.push_back(toAdd);
	}
	else {
		throw Span::SameNumberException();
	}
}

// add many number
void	Span::addNumber(std::vector<int>::iterator const &st, std::vector<int>::iterator const &ed)
{
	if ((std::distance(st, ed) + _storage.size()) > _size) {
		throw Span::StorageFullException();
	}
	std::vector<int>::iterator cur = st;
	while (cur != ed) {
		try {
			if (std::find(_storage.begin(), _storage.end(), *cur) == _storage.end()) {
				_storage.push_back(*cur);
			}
			else {
				throw Span::SameNumberException();
			}
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		cur++;
	}
}

unsigned int	Span::shortestSpan()
{
	if (_storage.size() <= 1) {
		throw Span::NoSpanFoundException();
	}
	std::vector<int>::iterator st = _storage.begin();
	std::vector<int>::iterator ed = _storage.end();
	unsigned int min = UINT_MAX;
	unsigned int tmp;
	
	std::sort(st, ed);
	std::vector<int>::iterator aft = st + 1;
	while (aft != ed) {
		tmp = *aft - *st;
		if (tmp < min) {
			min = tmp;
		}
		st++;
		aft++;
	}
	return min; 
}

unsigned int	Span::longestSpan()
{
	if (_storage.size() <= 1) {
		throw Span::NoSpanFoundException();
	}
	std::vector<int>::iterator st = _storage.begin();
	std::vector<int>::iterator ed = _storage.end();
	unsigned int max = 0;

	std::sort(st, ed);
	max = *(ed - 1) - *st;
	return max;
}


const char*	Span::SameNumberException::what() const throw() { return "Number already exist"; }
const char* Span::StorageFullException::what() const throw() { return "Storage Full Cannot Add"; }
const char* Span::NoSpanFoundException::what() const throw() { return "No Span Found"; }


void	Span::printVector()
{
	std::vector<int>::iterator it = _storage.begin();
	while (it != _storage.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}
