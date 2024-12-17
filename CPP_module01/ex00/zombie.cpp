/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:05:26 by oabdelka          #+#    #+#             */
/*   Updated: 2024/12/13 13:48:19 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"
#include <iostream>

// Constructor Implementation
Zombie::Zombie(std::string name) : name(name) {
	std::cout << "Zombie " << this->name << " has been created." << std::endl;
}

// Destructor Implementation
Zombie::~Zombie() {
	std::cout << "Zombie " << this->name << " has been destroyed." << std::endl;
}

// announce() Implementation
void Zombie::announce(void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
