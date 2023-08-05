#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal has been created" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &obj )
{
	std::cout << "WrongAnimal has been cloned" << std::endl;
	*this = obj;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal has been destroyed" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=( const WrongAnimal &obj )
{
	std::cout << "WrongAnimal has been assigned" << std::endl;
	type = obj.getType();
	return (*this);
}

std::string	WrongAnimal::getType() const
{
	return (type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Unknown animal sound" << std::endl;
}
