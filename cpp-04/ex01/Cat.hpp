#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat( const Cat & );
		~Cat();
		Cat	&operator=( const Cat & );

		void		makeSound() const;
		std::string	getIdeas( int ) const;
		void		setIdea( int, std::string );
	private:
		Brain*	_brain;
};

#endif
