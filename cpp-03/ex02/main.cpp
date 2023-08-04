#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main ( void )
{
	FragTrap	frag("FR4F-TP");
	ScavTrap	scav("SC4P-TP");
	ClapTrap	clap;

	// compare scavtrap and claptrap
	std::cout << "\n===== COMPARE FR4G-TP vs SC4V-TP vs CLAPTRAP ======\n" << std::endl;
	frag.displayStat();
	std::cout << std::endl;
	scav.displayStat();
	std::cout << "\nOLD CLAPTRAP" << std::endl;
	std::cout << "Name = " << clap.getName() << std::endl;
	std::cout << "HP   = " << clap.getHitPoints() << std::endl;
	std::cout << "EP   = " << clap.getEnergyPoints() << std::endl;
	std::cout << "ATK  = " << clap.getAttackDamage() << std::endl;

	// attck
	std::cout << "\n==== ATK TEST ====\n" << std::endl;
	scav.attack(frag.getName());
	// take damage
	frag.takeDamage(scav.getAttackDamage());
	// berepair
	frag.beRepaired(frag.getAttackDamage());
	// show stat
	std::cout << std::endl;
	frag.displayStat();
	std::cout << std::endl;
	scav.displayStat();

	// test gate keeper
	std::cout << "\nTEST ADDITIONAL MODE\n" << std::endl;

	frag.highFivesGuys();
	scav.guardGate();

	std::cout << "\n END ADDITIONAL TEST \n" << std::endl;

	frag.attack(scav.getName());
	scav.takeDamage(frag.getAttackDamage());
	frag.attack(scav.getName());
	scav.takeDamage(frag.getAttackDamage());
	frag.attack(scav.getName());
	scav.takeDamage(frag.getAttackDamage());
	frag.attack(scav.getName());
	scav.takeDamage(frag.getAttackDamage());
	scav.beRepaired(scav.getAttackDamage());
	std::cout << std::endl;
	scav.displayStat();
	std::cout << std::endl;
	frag.displayStat();
	std::cout << std::endl;
	return 0;
}
