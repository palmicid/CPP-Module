#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int	main()
{
	Data	data;
	data.num = 42;
	data.c = 'Z';
	data.boolean = true;
	data.someData = "I'm a string!";

	uintptr_t	seria = Serializer::serialize( &data );
	Data		*deser = Serializer::deserialize( seria );

	std::cout << "Data" << std::endl;
	std::cout << "num: " << data.num << std::endl;
	std::cout << "c: " << data.c << std::endl;
	std::cout << "bool: " << data.boolean << std::endl;
	std::cout << "string: " << data.someData << std::endl;

	std::cout << "----------------------------------------" << std::endl;

	std::cout << "Deserialized Data" << std::endl;
	std::cout << "num: " << deser->num << std::endl;
	std::cout << "c : " << deser->c << std::endl;
	std::cout << "bool: " << deser->boolean << std::endl;
	std::cout << "string: " << deser->someData << std::endl;

	std::cout << "----------------------------------------" << std::endl;

	std::cout << "uint seria: " << seria << std::endl;
	seria = Serializer::serialize( deser );
	std::cout << "againnn: " << seria << std::endl;

	return 0;
}
