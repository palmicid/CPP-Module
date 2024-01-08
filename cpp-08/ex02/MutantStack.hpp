#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>


// template<class T, class Container = std::stack<T>>
template<class T>
class MutantStack : public std::stack<T>
{
	private:
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(MutantStack const &other) {
			*this = other;
		}
		~MutantStack() {}

		MutantStack&	operator=(MutantStack const &other) {
			if (this != &other) {
				std::stack<T>::operator=(other);
			}
			return *this;
		}

		typedef typename std::stack<T>::container_type::iterator	iterator;

		iterator		begin() { return std::stack<T>::c.begin(); }
		iterator		end() { return std::stack<T>::c.end(); }
		
};


#endif