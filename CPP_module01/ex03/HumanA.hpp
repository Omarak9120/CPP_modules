// HumanA.hpp
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
private:
    std::string name;
    Weapon& weapon; // Reference ensures HumanA is always armed

public:
    // Constructor
    HumanA(std::string name, Weapon& weapon);

    // Attack function
    void attack() const;
};

#endif // HUMANA_HPP
