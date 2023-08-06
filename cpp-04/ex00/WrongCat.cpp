#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat has been born" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat &obj ) : WrongAnimal()
{
	std::cout << "WrongCat has been cloned" << std::endl;
	*this = obj;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat has been destroyed" << std::endl;
}

WrongCat	&WrongCat::operator=( const WrongCat &obj )
{
	std::cout << "WrongCat has been assigned" << std::endl;
	type = obj.getType();
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Maow Maow" << std::endl;
}
