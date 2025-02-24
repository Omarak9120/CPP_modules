/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:19:31 by oabdelka          #+#    #+#             */
/*   Updated: 2025/02/24 13:30:55 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap ,public FragTrap {
	private:
		std::string name; // Private attribute specific to DiamondTrap

	public:
		// Constructor & Destructor
		DiamondTrap(void);                           // Default constructor
		DiamondTrap(std::string name);               // Parameterized constructor
		DiamondTrap(const DiamondTrap &src);        // Copy constructor
		~DiamondTrap(void);                         // Destructor
		
		// Operator overloading
		DiamondTrap &operator=(const DiamondTrap &src); // Assignment operator
		
		// New functionality (specific to DiamondTrap)
		void attack(const std::string &target);
		void whoAmI(void);

		std::string getDiamondName() const { return name; }

		//using
		using ClapTrap::beRepaired;
		using ClapTrap::takeDamage;
};

#endif
