#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackdamage(20);
	std::cout << "ScavTrap " << getName() << " has been create" << std::endl;
}

ScavTrap::ScavTrap( std::string name)
{
	setName(name);
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackdamage(20);
	std::cout << "ScavTrap " << getName() << " has been create" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &obj ) : ClapTrap()
{
	*this = obj;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << getName() << " has been destroy" << std::endl;
}

ScavTrap&	ScavTrap::operator=( const ScavTrap &obj )
{
	if (this == &obj)
		return (*this);
	setName(obj.getName());
	setHitPoints(obj.getHitPoints());
	setEnergyPoints(obj.getEnergyPoints());
	setAttackdamage(obj.getAttackDamage());
	return (*this);
}

void	ScavTrap::guardGate()
{
	std::cout << getName() << " is now in Gate keeper mode" << std::endl;
}


// ========================= FOR TEST ==================================
void	ScavTrap::displayStat()
{
	std::cout << "SCR4P-TP Information" << std::endl;
	std::cout <<"NAME = " << getName() << std::endl;
	std::cout <<"ATK  = " << getAttackDamage() << std::endl;
	std::cout <<"EP   = " << getEnergyPoints() << std::endl;
	std::cout <<"HP   = " << getHitPoints() << std::endl;
}
