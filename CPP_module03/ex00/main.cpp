/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:42:54 by oabdelka          #+#    #+#             */
/*   Updated: 2025/02/24 13:29:32 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	// Create ClapTrap objects
	ClapTrap clapTrap1("omar1");
	ClapTrap clapTrap2("omar2");
	
	// Show initial status
	std::cout << "Initial status:" << std::endl;
	clapTrap1.status();
	clapTrap2.status();
	
	// ClapTrap1 attacks ClapTrap2
	clapTrap1.attack("omar2");
	clapTrap1.status();
	clapTrap2.status();
	std::cout << "after omar2 attack:" << std::endl;
	clapTrap2.takeDamage(5);  // ClapTrap2 takes damage
	clapTrap1.status();
	clapTrap2.status();
	std::cout << "after takeDamage (omar2):" << std::endl;

	// Repair ClapTrap2
	clapTrap2.beRepaired(3);
	clapTrap1.status();
	clapTrap2.status();
	std::cout << "after omar2 beRepaired:" << std::endl;

	
	// Show updated status
	std::cout << "\nUpdated status after some actions:" << std::endl;
	clapTrap1.status();
	clapTrap2.status();
	
	// Copy constructor and assignment operator in action
	ClapTrap clapTrap3 = clapTrap2;  // Copy constructor
	clapTrap1 = clapTrap2;            // Assignment operator
	
	// Final status
	std::cout << "\nFinal status after copying and assigning:" << std::endl;
	clapTrap1.status();
	clapTrap2.status();
	clapTrap3.status();
	
	return 0;
}
