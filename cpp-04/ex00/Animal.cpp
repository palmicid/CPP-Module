#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal has been created" << std::endl;
}

Animal::Animal( const Animal &obj )
{
	std::cout << "Animal has been cloned" << std::endl;
	*this = obj;
}

Animal::~Animal()
{
	std::cout << "Animal has been destroyed" << std::endl;
}

Animal	&Animal::operator=( const Animal &obj )
{
	std::cout << "Animal has been assigned" << std::endl;
	type = obj.getType();
	return (*this);
}

std::string	Animal::getType() const
{
	return (type);
}

void	Animal::makeSound() const
{
	std::cout << "unidentified animal sound" << std::endl;
}
