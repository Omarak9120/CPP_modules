/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:07:19 by oabdelka          #+#    #+#             */
/*   Updated: 2024/12/11 15:10:23 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"
#include <iostream>
#include <limits>

// Function Prototype for zombieHorde
Zombie* zombieHorde(int N, std::string name);

int main() {
    int numberOfZombies;
    std::string zombieName;

    std::cout << "Welcome to the Zombie Horde Creator!" << std::endl;

    // Prompt user for the number of zombies
    std::cout << "Enter the number of zombies you want to create: ";
    std::cin >> numberOfZombies;

    // Validate input
    if (std::cin.fail()) {
        std::cerr << "Invalid input. Please enter a valid integer." << std::endl;
        return 1;
    }

    // Clear the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Prompt user for the zombie name
    std::cout << "Enter the name for the zombies: ";
    std::getline(std::cin, zombieName);

    // Create the horde
    Zombie* horde = zombieHorde(numberOfZombies, zombieName);

    if (horde == NULL) {
        std::cerr << "Failed to create zombie horde." << std::endl;
        return 1;
    }

    // Announce each zombie in the horde
    std::cout << "\nZombie Horde Announcement:" << std::endl;
    for (int i = 0; i < numberOfZombies; ++i) {
        horde[i].announce();
    }

    // Clean up memory
    delete[] horde;
    std::cout << "\nZombie horde has been destroyed." << std::endl;

    return 0;
}
