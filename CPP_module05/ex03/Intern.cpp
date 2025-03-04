/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:41:35 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/04 22:41:38 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Initialize static members
const std::string Intern::_formNames[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

const Intern::FormCreator Intern::_formCreators[3] = {
	&Intern::createShrubberyCreationForm,
	&Intern::createRobotomyRequestForm,
	&Intern::createPresidentialPardonForm
};

// Constructor and Destructor
Intern::Intern() {}
Intern::~Intern() {}

// Copy Constructor and Assignment Operator
Intern::Intern(const Intern& other) { (void)other; }
Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

// Form Creation Functions
AForm* Intern::createShrubberyCreationForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

// makeForm Function
AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	for (int i = 0; i < 3; i++) {
		if (_formNames[i] == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*_formCreators[i])(target);
		}
	}
	std::cerr << "Error: Form name '" << formName << "' not found." << std::endl;
	return NULL;
}