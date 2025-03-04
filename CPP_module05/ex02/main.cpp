/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:57:49 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/04 02:57:50 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Bureaucrat.hpp"
// #include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"
// #include "AForm.hpp"
// #include <iostream>

// int main() {
//     Bureaucrat omar1("omar1", 1);  // Highest rank
//     Bureaucrat omar2("omar2", 140); // Low rank
//     try {
//         std::cout << "\n--- Testing ShrubberyCreationForm ---\n";
//         ShrubberyCreationForm shrubbery("home");
//         std::cout << shrubbery << std::endl;

//         // omar2 tries to sign but her grade is too low
//         // omar2.signForm(shrubbery);
//         // omar1 signs it
//         omar1.signForm(shrubbery);
//         // omar2 can't execute it
//         // omar2.executeForm(shrubbery);
//         // omar1 executes it
//         omar1.executeForm(shrubbery);
//     } catch (AForm::GradeTooHighException  &e) {
//         std::cerr << e.what() << std::endl;
//     } catch (AForm::GradeTooLowException  &e) {
//         std::cerr << e.what() << std::endl;
//     }
    
//     try{
//         std::cout << "\n--- Testing RobotomyRequestForm ---\n";
//         RobotomyRequestForm robotomy("omar1's brain");
//         omar1.signForm(robotomy);
//         omar1.executeForm(robotomy); // 50% success rate

//         std::cout << "\n--- Testing PresidentialPardonForm ---\n";
//         PresidentialPardonForm pardon("Zaphod Beeblebrox");
//         omar1.signForm(pardon);
//         omar1.executeForm(pardon);

//     } catch (AForm::GradeTooHighException  &e) {
//         std::cerr << e.what() << std::endl;
//     } catch (AForm::GradeTooLowException  &e) {
//         std::cerr << e.what() << std::endl;
//     }

//     return 0;
// }

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
    highRanker.executeForm(form);

    // Low grade signing attempt
    std::cout << "\n[Test 2] Low grade signing:\n";
    lowRanker.signForm(form);

    // Proper signing
    std::cout << "\n[Test 3] Valid signing:\n";
    highRanker.signForm(form);

    // Low grade execution
    std::cout << "\n[Test 4] Low grade execution:\n";
    lowRanker.executeForm(form);

    // Valid execution
    std::cout << "\n[Test 5] Valid execution:\n";
    highRanker.executeForm(form);
    // [Test 6] Execute with unsigned form
    std::cout << "\n[Test 6] Execute unsigned form with valid grade:\n";
    ShrubberyCreationForm unsignedForm("backyard");
    highRanker.executeForm(unsignedForm);

    // [Test 7] Valid grade but wrong bureaucrat
    std::cout << "\n[Test 7] Valid grade but wrong executor:\n";
    Bureaucrat impostor("FakePresident", 1);
    impostor.executeForm(form);  // Form signed by highRanker, executed by impostor
}

void testRobotomy() {
    std::cout << "\n\n===== ROBOTOMY TEST =====\n";
    Bureaucrat surgeon("Dr. Robot", 1);
    RobotomyRequestForm form("Patient X");

    surgeon.signForm(form);
    
    // Test multiple executions to see different outcomes
    std::cout << "\n[Test 1] First execution:\n";
    surgeon.executeForm(form);
    
    std::cout << "\n[Test 2] Second execution:\n";
    surgeon.executeForm(form);
}

void testPresidentialPardon() {
    std::cout << "\n\n===== PRESIDENTIAL PARDON TEST =====\n";
    Bureaucrat president("Zaphod", 1);
    Bureaucrat clerk("Clerk", 26);  // Too low to execute
    PresidentialPardonForm form("Arthur Dent");

    // Clerk tries to sign and execute
    std::cout << "\n[Test 1] Clerk attempts:\n";
    clerk.signForm(form);
    clerk.executeForm(form);

    // President signs but clerk executes
    std::cout << "\n[Test 2] Mixed execution:\n";
    president.signForm(form);
    clerk.executeForm(form);

    // Valid execution
    std::cout << "\n[Test 3] Proper execution:\n";
    president.executeForm(form);
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