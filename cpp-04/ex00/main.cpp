#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();		//will output the cat sound!
	j->makeSound();		// dog sound
	meta->makeSound();	// unknown animal sound

	std::cout << std::endl;
	delete meta;
	delete i;
	delete j;

	std::cout << "\n=========================================" << std::endl;

	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();
	wrong_cat->makeSound();
	wrong_meta->makeSound();
	
	std::cout << std::endl;
	delete wrong_meta;
	delete wrong_cat;

	return 0;
}