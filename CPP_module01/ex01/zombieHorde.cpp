/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:27:15 by oabdelka          #+#    #+#             */
/*   Updated: 2024/12/12 15:01:12 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// Function to create a horde of Zombies
Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0) {
        std::cerr << "Error : Number of zombies must be positive." << std::endl;
        return NULL;
    }

    // Allocate memory for N Zombies on the heap
    Zombie* horde = new Zombie[N];

    // Initialize each Zombie's name
    for (int i = 0; i < N; ++i) {
        horde[i].setName(name);
    }

    return horde;
}
