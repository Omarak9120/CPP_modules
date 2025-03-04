/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:41:57 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/04 22:42:00 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

// Default constructor
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45) {}

// Parameterized constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm(target, 72, 45) {}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other) {}

// Assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// Execute function to generate ASCII trees
void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	// Check if the Bureaucrat has permission
	if (!this->getIsSigned())
		throw RobotomyRequestForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::cout << "Some Drilling Noises..." << std::endl;
	std::srand(std::time(0)); // Seed the random number generator
	int i = std::rand() % 100 + 1; // Random number between 1 and 100
	if ( i <= 50)
		std::cout << executor.getName() << " has been robotomized!" << std::endl;
	else
		std::cout <<  "The Robotomy of " << executor.getName() << " has Failed!" << std::endl;
}
