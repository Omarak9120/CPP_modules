/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:13:25 by oabdelka          #+#    #+#             */
/*   Updated: 2025/02/24 13:30:01 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	// 1. Creating ClapTrap Objects (with name)
	ClapTrap clapTrap1("Clap1");
	ClapTrap clapTrap2("Clap2");

	// 2. Displaying Initial Status
	std::cout << "\nInitial Status of ClapTrap1:" << std::endl;
	clapTrap1.status();

	std::cout << "\nInitial Status of ClapTrap2:" << std::endl;
	clapTrap2.status();

	// 3. ClapTrap Attacks Another ClapTrap
	std::cout << "\nClapTrap1 attacks ClapTrap2!" << std::endl;
	clapTrap1.attack("ClapTrap2");

	// 4. ClapTrap Takes Damage
	std::cout << "\nClapTrap2 takes damage!" << std::endl;
	clapTrap2.takeDamage(5); // Takes 5 damage
	clapTrap2.status();

	// 5. ClapTrap Repairs Itself
	std::cout << "\nClapTrap2 repairs itself!" << std::endl;
	clapTrap2.beRepaired(5); // Heals 5 points
	clapTrap2.status();

	// 6. Creating ScavTrap Objects (with name)
	ScavTrap scavTrap1("Scav1");
	ScavTrap scavTrap2("Scav2");

	// 7. Displaying Initial Status of ScavTrap
	std::cout << "\nInitial Status of ScavTrap1:" << std::endl;
	scavTrap1.status();

	std::cout << "\nInitial Status of ScavTrap2:" << std::endl;
	scavTrap2.status();

	// 8. ScavTrap Attacks Another ScavTrap
	std::cout << "\nScavTrap1 attacks ScavTrap2!" << std::endl;
	scavTrap1.attack("ScavTrap2");

	// 9. ScavTrap Takes Damage
	std::cout << "\nScavTrap2 takes damage!" << std::endl;
	scavTrap2.takeDamage(10); // Takes 10 damage
	scavTrap2.status();
	scavTrap1.status();
	
	// 10. ScavTrap Repairs Itself
	std::cout << "\nScavTrap2 repairs itself!" << std::endl;
	scavTrap2.beRepaired(10); // Heals 10 points
	scavTrap2.status();
	scavTrap1.status();
	
	// 11. ScavTrap Uses GuardGate (new function in ScavTrap)
	std::cout << "\nScavTrap1 enters Guard Gate mode!" << std::endl;
	scavTrap1.guardGate();

	// 12. Copy Constructor for ScavTrap
	std::cout << "\nCreating a copy of ScavTrap1:" << std::endl;
	ScavTrap scavTrap3(scavTrap1); // Copy constructor
	scavTrap3.status();

	// 13. Assignment Operator for ScavTrap
	std::cout << "\nAssigning ScavTrap1 to ScavTrap2:" << std::endl;
	scavTrap2 = scavTrap1; // Assignment operator
	scavTrap2.status();

	return 0;
}
