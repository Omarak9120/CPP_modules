#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
    std::string type;

public:
    // Constructor
    Weapon(std::string type);

    // Getter for type
    const std::string& getType() const;

    // Setter for type
    void setType(std::string type);
};

#endif // WEAPON_HPP
