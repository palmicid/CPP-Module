#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
// #include <string>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap( std::string );
		ClapTrap( const ClapTrap &);
		~ClapTrap();
		ClapTrap &operator=( const ClapTrap &obj );

		std::string	getName() const;
		int			getHitPoints() const;
		int			getEnergyPoints() const;
		int			getAttackDamage() const;

		void		setName( std::string );
		void		setHitPoints( int );
		void		setEnergyPoints( int );
		void		setAttackdamage( int );

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
	protected:
		std::string		_name;
		int				_hitPoints;
		int				_energyPoints;
		int				_attackDamage;
};

#endif
