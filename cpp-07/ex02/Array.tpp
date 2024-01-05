#ifndef ARRAY_TPP
#define ARRAY_TPP

// constructor with no parameters: creates an empty array
template<typename T>
Array<T>::Array() {
	_arr = new T[0];
}

// constructor with an unsigned int parameter:
//creates an array of n elements, initialized by default
template<typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	_arr = new T[n];
}

// do deep copy
// construction by copy
template<typename T>
Array<T>::Array(Array const &other) {
	*this = other;
}

// assignment operator deep copy
template<typename T>
Array<T>	&Array<T>::operator=(Array<T> const &other) {
	if (this != &other) {
		_size = other.size();
		delete [] _arr;
		_arr = new T[_size];
		for (unsigned int i = 0; i < _size; i++) {
			_arr[i] = other._arr[i];
		}
	}
	return *this;
}

template<typename T>
Array<T>::~Array() {
	delete [] _arr;
}

template<typename T>
T	&Array<T>::operator[](unsigned int i) {
	if (i >= _size) {
		throw OutOfRangeException();
	}
	return _arr[i];
}

template<typename T>
unsigned int	Array<T>::size() const {
	return _size;
}

template<typename T>
const char	*Array<T>::OutOfRangeException::what() const throw() {
	return "Out of range";
}


#endif
