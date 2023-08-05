#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal & );
		~Animal();
		Animal &operator=( const Animal &);

		std::string getType() const;
		void	makeSound() const;
	protected:
		std::string type;
};


#endif
