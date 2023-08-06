#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog has been born" << std::endl;
	type = "Dog";
}

Dog::Dog( const Dog &obj ) : Animal()
{
	std::cout << "Dog has been cloned" << std::endl;
	*this = obj;
}

Dog::~Dog()
{
	std::cout << "Dog has been destroyed" << std::endl;
}

Dog	&Dog::operator=( const Dog &obj )
{
	std::cout << "Dog has been assigned" << std::endl;
	type = obj.getType();
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Bok Bok" << std::endl;
}
