/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:55:40 by oabdelka          #+#    #+#             */
/*   Updated: 2024/12/12 11:55:41 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
