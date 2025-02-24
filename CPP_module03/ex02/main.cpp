/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:01:40 by oabdelka          #+#    #+#             */
/*   Updated: 2025/02/24 13:30:36 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	std::cout << "*** Creating and Testing ClapTrap ***" << std::endl;
	ClapTrap clap("Clappy");
	clap.attack("an enemy");
	std::cout << std::endl << "*** The status ***" << std::endl;
	clap.status();
	
	std::cout << std::endl << "*** Creating and Testing ScavTrap ***" << std::endl;
	ScavTrap scav("Scavy");
	scav.attack("an enemy");
	scav.guardGate();  // Unique method for ScavTrap
	std::cout << std::endl << "*** The status ***" << std::endl;
	scav.status();

	std::cout << std::endl << "*** Creating and Testing FragTrap ***" << std::endl;
	FragTrap frag("Fraggy");
	frag.attack("an enemy");
	frag.highFivesGuys();  // Unique method for FragTrap
	std::cout << std::endl << "*** The status ***" << std::endl;
	frag.status();

	std::cout << std::endl << "*** Testing FragTrap Copy Constructor ***" << std::endl;
	FragTrap fragCopy(frag);
	fragCopy.attack("another enemy");

	std::cout << std::endl << "*** Testing FragTrap Assignment Operator ***" << std::endl;
	FragTrap fragAssigned;
	fragAssigned = frag;
	fragAssigned.attack("yet another enemy");

	std::cout << std::endl << "*** Creating and Testing Multiple Objects ***" << std::endl;
	ClapTrap clap1("Clap1");
	ScavTrap scav1("Scav1");
	FragTrap frag1("Frag1");
	
	clap1.attack("an enemy");
	scav1.attack("an enemy");
	scav1.guardGate();
	frag1.attack("an enemy");
	frag1.highFivesGuys();
	std::cout << std::endl << "*** The status ***" << std::endl;
	clap1.status();
	scav1.status();
	frag1.status();

	std::cout << std::endl << "*** End of Tests ***" << std::endl;
	return 0;
}
