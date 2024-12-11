// HumanA.cpp
#include "HumanA.hpp"
#include <iostream>

// Constructor Implementation
HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

// attack() Implementation
void HumanA::attack() const {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
