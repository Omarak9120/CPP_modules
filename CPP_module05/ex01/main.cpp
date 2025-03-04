/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:35:48 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/04 22:35:49 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat boss("Alice", 5);
		Bureaucrat intern("Bob", 120);

		Form contract("Contract", 50, 30);

		std::cout << contract << std::endl;

		intern.signForm(contract); // Should fail
		boss.signForm(contract); // Should succeed

		std::cout << contract << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
