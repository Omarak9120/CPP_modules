// main.cpp
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA omar1("OMAR1", club);
        omar1.attack();
        club.setType("some other type of club");
        omar1.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB omar2("OMAR2");
        omar2.setWeapon(club);
        omar2.attack();
        club.setType("some other type of club");
        omar2.attack();
    }
    return 0;
}
