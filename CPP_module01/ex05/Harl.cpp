/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:07:40 by oabdelka          #+#    #+#             */
/*   Updated: 2024/12/13 13:46:28 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

// Private member function implementations

void Harl::debug( void ) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my "
			  << "7XL-double-cheese-triple-pickle-specialketchup burger. "
			  << "I really do!" << std::endl << std::endl;
}

void Harl::info( void ) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. "
			  << "You didn’t put enough bacon in my burger! "
			  << "If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning( void ) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. "
			  << "I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error( void ) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

// Public member function implementation

void Harl::complain( std::string level ) {
	// Define a pointer to member function
	void (Harl::*func_ptr)() = NULL;

	// Array of levels and corresponding member function pointers
  void (Harl::*functions[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string levels[] = {
		"DEBUG", 
		"INFO", 
		"WARNING", 
		"ERROR"
	};

	int size = sizeof(levels) / sizeof(levels[0]);
	int i = 0;

	// Find the matching level
	while (i < size) {
		if (level == levels[i]) {
			func_ptr = functions[i];
			break;
		}
		i++;
	}

	// Call the corresponding function if found
	if (func_ptr != NULL)
		(this->*func_ptr)();
	else
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl << std::endl;
}
