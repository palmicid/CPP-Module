#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain has been created" << std::endl;
}

Brain::Brain( const Brain &obj )
{
	std::cout << "Brain has been cloned" << std::endl;
	*this = obj;
}

Brain::~Brain()
{
	std::cout << "Brain has been destroyed" << std::endl;
}

Brain	&Brain::operator=( const Brain &obj )
{
	std::cout << "Brain has been assigned" << std::endl;
	if (this == &obj)
		return *this;
	for (int i = 0; i < 100; i++)
		ideas[i] = obj.getIdea(i);
	return (*this);
}

std::string	Brain::getIdea( int i ) const
{
	return (ideas[i]);
}

void	Brain::setIdea( int i, std::string idea )
{
	ideas[i] = idea;
}
