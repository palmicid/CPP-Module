#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	std::string	raw = "";

	if (ac < 2) {
		std::cout << "Error: No input. input number with no quote" << std::endl;
		return 0;
	}
	
	PmergeMe< int, std::vector<int> >		testVec(ac, av);
	PmergeMe<int, std::deque<int> >			testDQ(ac, av);


	



	return 0;
}