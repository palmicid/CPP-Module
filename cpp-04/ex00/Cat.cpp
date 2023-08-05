#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat has been born" << std::endl;
	type = "Cat";
}

Cat::Cat( const Cat &obj ) : Animal(obj)
{
	std::cout << "Cat has been cloned" << std::endl;
	*this = obj;
}

Cat::~Cat()
{
	std::cout << "Cat has been destroyed" << std::endl;
}

Cat	&Cat::operator=( const Cat &obj )
{
	std::cout << "Cat has been assigned" << std::endl;
	type = obj.getType();
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}
