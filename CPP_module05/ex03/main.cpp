/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:41:42 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/04 22:41:45 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	Intern intern;
	Bureaucrat ceo("CEO", 1);

	// Create forms using the intern
	AForm* form1 = intern.makeForm("shrubbery creation", "home");
	AForm* form2 = intern.makeForm("robotomy request", "Bender");
	AForm* form3 = intern.makeForm("presidential pardon", "Zaphod");
	AForm* form4 = intern.makeForm("invalid form", "target"); // Should fail

	// Sign and execute forms
	if (form1) {
		ceo.signAForm(*form1);
		ceo.executeForm(*form1); // Use base class AForm
		delete form1;
	}
	if (form2) {
		ceo.signAForm(*form2);
		ceo.executeForm(*form2); // Use base class AForm
		delete form2;
	}
	if (form3) {
		ceo.signAForm(*form3);
		ceo.executeForm(*form3); // Use base class AForm
		delete form3;
	}
	if (form4) {
		delete form4; // Cleanup (should not happen)
	}

	return 0;
}