/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:05:19 by oabdelka          #+#    #+#             */
/*   Updated: 2024/12/13 13:48:11 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"
#include <iostream>

// Function Prototypes
Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
	// Create a Zombie on the heap
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();

	// Create a Zombie on the stack
	randomChump("StackZombie");

	// Clean up heap-allocated Zombie
	delete heapZombie;

	return 0;
}
