#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackdamage(30);
	std::cout << "FragTrap = " << getName() << " has been create" << std::endl;
}

FragTrap::FragTrap( std::string name )
{
	setName(name);
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackdamage(30);
	std::cout << "FragTrap = " << getName() << " has been create" << std::endl;
}

FragTrap::FragTrap( const FragTrap &obj ) : ClapTrap(obj)
{
	*this = obj;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << getName() << " has been destroy" << std::endl;
}

FragTrap&	FragTrap::operator=( const FragTrap &obj )
{
	if (this == &obj)
		return (*this);
	setName(obj.getName());
	setHitPoints(obj.getHitPoints());
	setEnergyPoints(obj.getEnergyPoints());
	setAttackdamage(obj.getAttackDamage());
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << getName() << " give me a High Five !!! [^^]P" << std::endl;
}

// ========================= FOR TEST ==================================
void	FragTrap::displayStat()
{
	std::cout << "FR4G-TP Information" << std::endl;
	std::cout <<"NAME = " << getName() << std::endl;
	std::cout <<"ATK  = " << getAttackDamage() << std::endl;
	std::cout <<"EP   = " << getEnergyPoints() << std::endl;
	std::cout <<"HP   = " << getHitPoints() << std::endl;
}
