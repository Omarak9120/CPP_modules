/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:40:38 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/04 22:40:39 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <cstdlib>  // For srand()

void testShrubbery() {
    std::cout << "\n===== SHRUBBERY TEST =====\n";
    Bureaucrat highRanker("CEO", 1);
    Bureaucrat lowRanker("Intern", 145);
    ShrubberyCreationForm form("garden");

    // Try to execute unsigned form
    std::cout << "\n[Test 1] Execute unsigned form:\n";
    highRanker.executeAForm(form);

    // Low grade signing attempt
    std::cout << "\n[Test 2] Low grade signing:\n";
    lowRanker.signAForm(form);

    // Proper signing
    std::cout << "\n[Test 3] Valid signing:\n";
    highRanker.signAForm(form);

    // Low grade execution
    std::cout << "\n[Test 4] Low grade execution:\n";
    lowRanker.executeAForm(form);

    // Valid execution
    std::cout << "\n[Test 5] Valid execution:\n";
    highRanker.executeAForm(form);
    // [Test 6] Execute with unsigned form
    std::cout << "\n[Test 6] Execute unsigned form with valid grade:\n";
    ShrubberyCreationForm unsignedForm("backyard");
    highRanker.executeAForm(unsignedForm);

    // [Test 7] Valid grade but wrong bureaucrat
    std::cout << "\n[Test 7] Valid grade but wrong executor:\n";
    Bureaucrat impostor("FakePresident", 1);
    impostor.executeAForm(form);  // Form signed by highRanker, executed by impostor
}

void testRobotomy() {
    std::cout << "\n\n===== ROBOTOMY TEST =====\n";
    Bureaucrat surgeon("Dr. Robot", 1);
    RobotomyRequestForm form("Patient X");

    surgeon.signAForm(form);
    
    // Test multiple executions to see different outcomes
    std::cout << "\n[Test 1] First execution:\n";
    surgeon.executeBForm(form);
    
    std::cout << "\n[Test 2] Second execution:\n";
    surgeon.executeBForm(form);
}

void testPresidentialPardon() {
    std::cout << "\n\n===== PRESIDENTIAL PARDON TEST =====\n";
    Bureaucrat president("Zaphod", 1);
    Bureaucrat clerk("Clerk", 26);  // Too low to execute
    PresidentialPardonForm form("Arthur Dent");

    // Clerk tries to sign and execute
    std::cout << "\n[Test 1] Clerk attempts:\n";
    clerk.signAForm(form);
    clerk.executeCForm(form);

    // President signs but clerk executes
    std::cout << "\n[Test 2] Mixed execution:\n";
    president.signAForm(form);
    clerk.executeCForm(form);

    // Valid execution
    std::cout << "\n[Test 3] Proper execution:\n";
    president.executeCForm(form);
}

int main() {
    srand(time(0));  // Seed for robotomy randomization

    try {
        testShrubbery();
        testRobotomy();
        testPresidentialPardon();
    } catch (std::exception &e) {
        std::cerr << "\nMAIN ERROR: " << e.what() << std::endl;
    }

    return 0;
}