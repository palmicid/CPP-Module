#include <iostream>
#include <iomanip>
#include "iter.hpp"

// for print out because I'm lazy
template <typename T> void printArray(T *array, size_t len) {
	for (size_t i = 0; i < len; i++) {
		std::cout << std::setw(4) << array[i];
	}
	std::cout << std::endl;
}

// for testing
template <typename T> void addOne(T &i) {
	i++;
}

int	main()
{
	int		int_array[5] = { 1, 2, 3, 4, 5 };
	char	char_array[5] = { 'a', 'b', 'c', 'd', 'e' };
	float	float_array[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };


	std::cout << "int_array 1st line = before iter, 2nd line after iter" << std::endl;
	::printArray(int_array, 5);
	::iter(int_array, 5, addOne);
	::printArray(int_array, 5);

	std::cout << "char_array 1st line = before iter, 2nd line after iter" << std::endl;
	::printArray(char_array, 5);
	::iter(char_array, 5, addOne);
	::printArray(char_array, 5);

	std::cout << "float_array 1st line = before iter, 2nd line after iter" << std::endl;
	::printArray(float_array, 5);
	::iter(float_array, 5, addOne);
	::printArray(float_array, 5);

	return 0;
}
