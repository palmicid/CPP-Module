#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

// Why stdint.h and not cstdint?
// because it trigger warning c++11

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const &);
		Serializer &operator=(Serializer const &);
		~Serializer();
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data* 		deserialize(uintptr_t raw);
};



#endif