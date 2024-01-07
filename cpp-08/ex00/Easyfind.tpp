#ifndef EASYFIND_TPP
#define EASYFIND_TPP


template <typename T> 
void	easyfind(T& container, int n)
{
	typename T::iterator found = find(container.begin(), container.end(), n);
	if (found == container.end())
		throw NotFoundException();
	else
		std::cout << "Found " << n << std::endl;
}

 

#endif
