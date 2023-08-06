#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog has been born" << std::endl;
	type = "Dog";
	_brain = new Brain();
}

Dog::Dog( const Dog &obj ) : Animal()
{
	std::cout << "Dog has been cloned" << std::endl;
	*this = obj;
}

Dog::~Dog()
{
	std::cout << "Dog has been destroyed" << std::endl;
	delete _brain;
}

// for test shallow copy
// _brain = obj._brain;	// to line 29
Dog	&Dog::operator=( const Dog &obj )
{
	std::cout << "Dog has been assigned" << std::endl;
	type = obj.getType();
	_brain = new Brain();
	for (int i = 0; i < 100; i++)
		_brain->setIdea(i, obj.getIdeas(i));
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Bok Bok" << std::endl;
}

std::string	Dog::getIdeas( int i ) const
{
	return (_brain->getIdea(i));
}

void	Dog::setIdea( int i, std::string idea )
{
	_brain->setIdea(i, idea);
}
