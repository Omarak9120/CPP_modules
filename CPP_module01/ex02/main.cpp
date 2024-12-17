/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:05:10 by oabdelka          #+#    #+#             */
/*   Updated: 2024/12/13 13:47:48 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
	// Initialize a string variable
	std::string str = "HI THIS IS BRAIN";

	// Create a pointer to the string
	std::string* stringPTR = &str;

	// Create a reference to the string
	std::string& stringREF = str;

	// Print the memory address of the string variable
	std::cout << "Memory address of the string variable: " << &str << std::endl;

	// Print the memory address held by stringPTR
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;

	// Print the memory address held by stringREF
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << std::endl; // For better readability

	// Print the value of the string variable
	std::cout << "Value of the string variable: " << str << std::endl;

	// Print the value pointed to by stringPTR
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;

	// Print the value referred to by stringREF
	std::cout << "Value referred to by stringREF: " << stringREF << std::endl;

	return 0;
}
