// HumanB.cpp
#include "HumanB.hpp"
#include <iostream>

// Constructor Implementation
HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

// Setter Implementation
void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
}

// attack() Implementation
void HumanB::attack() const {
    if (weapon != NULL) {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    } else {
        std::cout << name << " has no weapon to attack with." << std::endl;
    }
}
