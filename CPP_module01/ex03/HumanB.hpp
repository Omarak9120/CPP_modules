// HumanB.hpp
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon* weapon; // Pointer allows HumanB to be unarmed initially

public:
    // Constructor
    HumanB(std::string name);

    // Setter for weapon
    void setWeapon(Weapon& weapon);

    // Attack function
    void attack() const;
};

#endif // HUMANB_HPP
