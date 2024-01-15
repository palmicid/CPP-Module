#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	std::string	raw = "";

	if (ac < 2) {
		std::cout << "Error: No input. input number with no quote" << std::endl;
		return 0;
	}
	
	PmergeMe< int, std::vector<int> >		byVec(ac, av);
	PmergeMe<int, std::deque<int> >			byDQ(ac, av);

	std::cout << "Before:    ";
	byVec.printStorage();

	byVec.startMergeSort();
	byDQ.startMergeSort();

	std::cout << "After:     ";
	byVec.printStorage();

	byVec.printMessage("vector");
	byDQ.printMessage("deque");
	

	return 0;
}