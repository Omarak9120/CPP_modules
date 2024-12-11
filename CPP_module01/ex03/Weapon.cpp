#include "Weapon.hpp"

// Constructor Implementation
Weapon::Weapon(std::string type) : type(type) {}

// Getter Implementation
const std::string& Weapon::getType() const {
    return type;
}

// Setter Implementation
void Weapon::setType(std::string type) {
    this->type = type;
}
