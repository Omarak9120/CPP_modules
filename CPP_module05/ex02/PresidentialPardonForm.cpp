/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:57:53 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/04 02:57:54 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destroyed" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > getGrade_execute())
		throw AForm::GradeTooLowException();

	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}