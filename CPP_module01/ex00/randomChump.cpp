/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:05:24 by oabdelka          #+#    #+#             */
/*   Updated: 2024/12/13 13:48:16 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

// Function to create a Zombie on the stack and announce it
void randomChump(std::string name) {
	Zombie z(name);
	z.announce();
}
