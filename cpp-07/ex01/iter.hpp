 #ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, size_t len, void (*f)(T &)) {
	for (size_t i = 0; i < len; i++) {
		f(array[i]);
	}
}

template <typename T, typename A>
void iter(T *array, size_t len, void (*f)(A &)) {
	for (size_t i = 0; i < len; i++) {
		f(array[i]);
	}
}




// ==================== FOR TEST ====================
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

#endif
