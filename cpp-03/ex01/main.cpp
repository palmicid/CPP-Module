#include <iostream>
#include "ClapTrap.hpp"

int	main ( void )
{
	ClapTrap	octoJom("Jom");
	ClapTrap	unknown;

	// use for loop to test decrease energy and what if it out of energy
	for (int i = 0; i <= 5; i++)
	{
		octoJom.attack("noname");
		octoJom.beRepaired(2);
		std::cout << octoJom.getName() << " energy = " << octoJom.getEnergyPoints() << std::endl;
		std::cout << octoJom.getName() << " HP     = " << octoJom.getHitPoints() << std::endl;
	}

	std::cout << "==============================================" << std::endl;

	// test reduce HP until it die and use action when die
	unknown.takeDamage(5);
	std::cout << unknown.getName() << " HP = " << unknown.getHitPoints() << std::endl;
	unknown.takeDamage(5);
	std::cout << unknown.getName() << " HP = " << unknown.getHitPoints() << std::endl;
	unknown.attack("trainingTarget");
	unknown.beRepaired(10);
	
	std::cout << "================= END OF TEST =================" << std::endl;
	return 0;
}
