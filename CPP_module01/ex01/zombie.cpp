/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:27:07 by oabdelka          #+#    #+#             */
/*   Updated: 2024/12/11 15:27:08 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"
#include <iostream>

// Default Constructor Implementation
Zombie::Zombie() : name("Unnamed") {
    std::cout << "Zombie " << this->name << " has been created." << std::endl;
}

// Parameterized Constructor Implementation
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

// setName() Implementation
void Zombie::setName(std::string name) {
    this->name = name;
}
