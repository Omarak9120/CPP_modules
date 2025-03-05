/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:42:05 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/05 02:48:43 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137) {}

// Parameterized constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm(target, 145, 137) {}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other) {}

// Assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Execute function to generate ASCII trees
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	// Check if the Bureaucrat has permission
	if (!this->getIsSigned())
		throw ShrubberyCreationForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	// Create a file "<target>_shrubbery"
	std::ofstream file((this->getName() + "_shrubbery").c_str());
	if (!file.is_open()) {
		std::cerr << "Error: Could not open file" << std::endl;
		return;
	}

	// Write ASCII trees
	file << "         42🌲42       " << std::endl;

	file.close();
	std::cout << "Shrubbery has been planted in " << this->getName() << "_shrubbery" << std::endl;
}
