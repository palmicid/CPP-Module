#include <iostream>
#include "ScavTrap.hpp"

int	main ( void )
{
	ScavTrap	scav("SC4P-TP");
	ClapTrap	clap;

	// Test copy constructor
	ScavTrap	scav_2("SC4P-TP MKII");

	// compare scavtrap and claptrap
	std::cout << "\n===== COMPARE SC4v-TP vs CLAPTRAP ======\n" << std::endl;
	scav.displayStat();
	std::cout << "\nOLD CLAPTRAP" << std::endl;
	std::cout << "Name = " << clap.getName() << std::endl;
	std::cout << "HP   = " << clap.getHitPoints() << std::endl;
	std::cout << "EP   = " << clap.getEnergyPoints() << std::endl;
	std::cout << "ATK  = " << clap.getAttackDamage() << std::endl;

	std::cout << "\n==== TEST COPY CONSTRUCTOR ====\n" << std::endl;
	scav_2.displayStat();


	// attck
	std::cout << "\n==== ATK TEST ====\n" << std::endl;
	scav.attack("Unknown target");
	// take damage
	scav.takeDamage(50);
	// berepair
	scav.beRepaired(20);

	std::cout << "EP   = " << scav.getEnergyPoints() << std::endl;
	// test gate keeper
	std::cout << "\nTEST GATE KEEPER MODE\n" << std::endl;

	scav.guardGate();

	std::cout << "\n END TEST \n" << std::endl;

	return 0;
}

// HAVE TO FIX !!!!! 
// HOW TO CALL CONSTRUCTOR FOR INHERITANCE CLASS