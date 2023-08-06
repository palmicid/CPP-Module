#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	// const Animal* meta = new Animal();		// abstract class cannot create compile error
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();		//will output the cat sound!
	dog->makeSound();		// dog sound
	// meta->makeSound();	// unknown animal sound

	std::cout << std::endl;
	// delete meta;
	delete cat;
	delete dog;
	
	

	std::cout << "\n=========================================" << std::endl;
	
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	// TEST BRAIN
	std::cout << "\n=========================================" << std::endl;
	Dog basic;
	for (int i = 0; i < 5; i++)
		basic.setIdea(i, "blah");
	std::cout << "basic before change :" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << i << " = " << basic.getIdeas(i) << std::endl;
	{
		Dog tmp = basic;
		for (int i = 0; i < 5; i++)
			tmp.setIdea(i, "boo");
		// TEST PRINT BOTH basic and tmp
		std::cout << "basic:" << std::endl;
		for (int i = 0; i < 5; i++)
			std::cout << i << " = " << basic.getIdeas(i) << std::endl;
		std::cout << "tmp:" << std::endl;
		for (int i = 0; i < 5; i++)
			std::cout << i << " = " << tmp.getIdeas(i) << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\n=========================================" << std::endl;


	return 0;
}
