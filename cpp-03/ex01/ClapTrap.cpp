#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	
	_name = "NoNameClapTrap";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "ClapTrap " << _name << " has been create." << std::endl;
}

ClapTrap::ClapTrap( std::string name )
{
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "ClapTrap " << _name << " has been create." << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &obj)
{
	*this = obj;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " has been destroy" << std::endl;
}
ClapTrap &ClapTrap::operator=( const ClapTrap &obj )		// copy assgin overload
{
	if (this == &obj)
		return (*this);
	_name = obj.getName();
	_hitPoints = obj.getHitPoints();
	_energyPoints = obj.getEnergyPoints();
	_attackDamage = obj.getAttackDamage();
	return (*this);
}

std::string	ClapTrap::getName() const
{
	return _name;
}

int	ClapTrap::getHitPoints() const
{
	return _hitPoints;
}

int	ClapTrap::getEnergyPoints() const
{
	return _energyPoints;
}

int	ClapTrap::getAttackDamage() const
{
	return _attackDamage;
}

void	ClapTrap::setName( std::string name)
{
	_name = name;
}

void	ClapTrap::setHitPoints( int hp )
{
	_hitPoints = hp;
}

void	ClapTrap::setEnergyPoints( int ep )
{
	_energyPoints = ep;
}

void	ClapTrap::setAttackdamage( int atkdmg )
{
	_attackDamage = atkdmg;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << _name << " has died" << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "No Energy left" << std::endl; 
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage" << std::endl;
	_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << _name << " has died" << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "No Energy left" << std::endl; 
		return ;
	}
	std::cout << _name << " recover " << amount << " HP" << std::endl;
	_hitPoints += amount;
	_energyPoints--;
}
