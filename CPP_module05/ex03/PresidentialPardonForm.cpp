/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:41:49 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/04 22:41:53 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

// Default constructor
PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5) {}

// Parameterized constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm(target, 25, 5) {}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other) {}

// Assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// Execute function to generate ASCII trees
void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	// Check if the Bureaucrat has permission
	if (!this->getIsSigned())
		throw PresidentialPardonForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}
