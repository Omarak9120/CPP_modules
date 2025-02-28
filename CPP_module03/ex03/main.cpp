/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:20:40 by oabdelka          #+#    #+#             */
/*   Updated: 2025/02/25 13:52:37 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	std::cout << "\n====== CREATING OBJECTS ======\n";
	ClapTrap clap("Clappy");
	ScavTrap scav("Scavvy");
	FragTrap frag("Fraggy");
	DiamondTrap diamond("Diamond");

	std::cout << "\n====== INITIAL STATUS ======\n";
	std::cout << "ClapTrap: " << clap.getName() << " (HP: 10, EP: 10, AD: 0)\n";
	std::cout << "ScavTrap: " << scav.getName() << " (HP: 100, EP: 50, AD: 20)\n";
	std::cout << "FragTrap: " << frag.getName() << " (HP: 100, EP: 100, AD: 30)\n";
	std::cout << "DiamondTrap: " << diamond.getDiamondName() << " (HP: 100, EP: 50, AD: 30)\n";

	std::cout << "\n====== ATTACKING ======\n";
	clap.attack("Enemy1"); // ClapTrap default attack
	scav.attack("Enemy2"); // ScavTrap attack
	frag.attack("Enemy3"); // FragTrap attack
	diamond.attack("Enemy4"); // DiamondTrap attack (ScavTrap's attack)

	std::cout << "\n====== TAKING DAMAGE ======\n";
	clap.takeDamage(5);
	scav.takeDamage(20);
	frag.takeDamage(50);
	diamond.takeDamage(40);

	std::cout << "\n====== REPAIRING ======\n";
	clap.beRepaired(3);
	scav.beRepaired(10);
	frag.beRepaired(20);
	diamond.beRepaired(30);

	std::cout << "\n====== SPECIAL ACTIONS ======\n";
	scav.guardGate(); // ScavTrap special ability
	frag.highFivesGuys(); // FragTrap special ability
	diamond.whoAmI(); // DiamondTrap special ability

	std::cout << "\n====== COPY CONSTRUCTOR TEST ======\n";
	DiamondTrap diamondCopy(diamond);
	diamondCopy.whoAmI();

	std::cout << "\n====== ASSIGNMENT OPERATOR TEST ======\n";
	DiamondTrap diamondAssigned = diamond;
	diamondAssigned.whoAmI();

	std::cout << "\n====== DESTRUCTORS CALLED AUTOMATICALLY AT END ======\n";
	return 0;
}
/*
		ClapTrap
	   /        \
  ScavTrap     FragTrap
	   \        /
	  DiamondTrap
*/