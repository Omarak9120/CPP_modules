/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:19:40 by oabdelka          #+#    #+#             */
/*   Updated: 2025/02/24 13:30:52 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

// Constructor
DiamondTrap::DiamondTrap(std::string name) 
	: ClapTrap(name + "_clap_OMAR"), ScavTrap(), FragTrap(), name(name) {
	hitPoints = FragTrap::hitPoints;   // From FragTrap (100 HP)
	energyPoints = ScavTrap::energyPoints;  // From ScavTrap (50 EP)
	attackDamage = FragTrap::attackDamage;  // From FragTrap (30 AD)

	std::cout << "DiamondTrap constructor called for " << name << std::endl;
}

// Default Constructor
DiamondTrap::DiamondTrap()
	: ClapTrap("Default_clap_OMAR"), ScavTrap(), FragTrap(), name("Default") {
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;

	std::cout << "DiamondTrap default constructor called" << std::endl;
}

// Copy Constructor
DiamondTrap::DiamondTrap(const DiamondTrap &src) 
	: ClapTrap(src), ScavTrap(src), FragTrap(src), name(src.name) {
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
}

// Copy Assignment Operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src) {
	std::cout << "DiamondTrap Copy Assignment Operator called" << std::endl;
	if (this != &src) {
		ClapTrap::operator=(src);  // Assign base ClapTrap
		name = src.name;
		hitPoints = src.hitPoints;
		energyPoints = src.energyPoints;
		attackDamage = src.attackDamage;
	}
	return *this;
}

// Destructor
DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << name << " is being destroyed" << std::endl;
}

// Attack function (uses ScavTrap's attack method)
void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);  // Uses ScavTrap's attack function
}

// WhoAmI function to display both DiamondTrap and ClapTrap names
void DiamondTrap::whoAmI() {
	std::cout << "I am " << name << " and my ClapTrap name is " << ClapTrap::name << "!" << std::endl;
}
