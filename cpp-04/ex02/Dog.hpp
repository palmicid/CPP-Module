#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog( const Dog & );
		~Dog();
		Dog	&operator=( const Dog & );

		void		makeSound() const;
		std::string	getIdeas( int ) const;
		void		setIdea( int, std::string );
	private:
		Brain*	_brain;
};






#endif
