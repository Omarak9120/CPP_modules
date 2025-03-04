/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:44:25 by oabdelka          #+#    #+#             */
/*   Updated: 2025/02/28 15:57:27 by oabdelka         ###   ########.fr       */
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
	// Assign an integer to the input level
	int level_num = -1;

	if (level == "DEBUG")
		level_num = 0;
	else if (level == "INFO")
		level_num = 1;
	else if (level == "WARNING")
		level_num = 2;
	else if (level == "ERROR")
		level_num = 3;

	switch (level_num) {
		case 0:
			this->debug();
			// Fallthrough
		case 1:
			this->info();
			// Fallthrough
		case 2:
			this->warning();
			// Fallthrough
		case 3:
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl << std::endl;
			break;
	}
}