/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:32:47 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/04 22:32:50 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b1("Alice", 1);
		Bureaucrat b2("Bob", 150);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;

		b1.decrementGrade();
		b2.incrementGrade();
		
		std::cout << "After modification:" << std::endl;
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;

		Bureaucrat b3("Charlie", 151);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
