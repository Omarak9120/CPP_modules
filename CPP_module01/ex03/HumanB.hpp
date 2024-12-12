/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:55:34 by oabdelka          #+#    #+#             */
/*   Updated: 2024/12/12 11:55:55 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#endif
