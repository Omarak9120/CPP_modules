/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:55:26 by oabdelka          #+#    #+#             */
/*   Updated: 2024/12/13 13:47:42 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

// Constructor Implementation
HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

// attack() Implementation
void HumanA::attack() const {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
