#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat has been born" << std::endl;
	type = "Cat";
	_brain = new Brain();
}

Cat::Cat( const Cat &obj ) : Animal()
{
	std::cout << "Cat has been cloned" << std::endl;
	*this = obj;
}

Cat::~Cat()
{
	std::cout << "Cat has been destroyed" << std::endl;
	delete _brain;
}

Cat	&Cat::operator=( const Cat &obj )
{
	std::cout << "Cat has been assigned" << std::endl;
	type = obj.getType();
	_brain = new Brain();
	for (int i = 0; i < 100; i++)
		_brain->setIdea(i, obj._brain->getIdea(i));
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}

std::string	Cat::getIdeas( int i ) const
{
	return (_brain->getIdea(i));
}

void	Cat::setIdea( int i, std::string idea )
{
	_brain->setIdea(i, idea);
}
