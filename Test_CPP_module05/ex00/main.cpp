/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:27:36 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/03 23:55:45 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat bob("omar1", 75);
        std::cout << bob;
        
        bob.incrementGrade();
		bob.decrementGrade();
        std::cout << "After incrementing,grade: " << bob;

        Bureaucrat alice("omar2", 1);
        std::cout << alice;
        alice.incrementGrade();
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat charlie("omar3", 150);
        std::cout << charlie << std::endl;
        charlie.decrementGrade(); 
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}