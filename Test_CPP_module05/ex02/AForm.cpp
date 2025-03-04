/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:57:25 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/04 20:36:26 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

AForm::AForm(std::string name, int grade_sign, int grade_execute)
    : name(name), is_signed(false), grade_sign(grade_sign), grade_execute(grade_execute) {
    if (grade_sign < 1 || grade_execute < 1) {
        throw GradeTooHighException();
    }
    if (grade_sign > 150 || grade_execute > 150) {
        throw GradeTooLowException();
    }
}

AForm::~AForm() {
	std::cout << name << " Form Destroyed" << std::endl;
}

std::string AForm::getName() const {
	return name;
}

bool AForm::getIs_signed() const {
	return is_signed;
}

int AForm::getGrade_sign() const { 
	return this->grade_sign;
}

int AForm::getGrade_execute() const {
	return this->grade_execute;
}

std::ostream& operator << (std::ostream &os, AForm& f) {
	os << "Name: " << f.getName()
	   << "\nGrade sign: " << f.getGrade_sign()
	   << "\nGrade Execute: " << f.getGrade_execute()
	   << "\nIs Signed: " << f.getIs_signed()
	   << "\nGrade required to execute: " << f.getGrade_execute()
	   << std::endl;
	return os;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade too High !\n";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade too Low !\n";
}

void AForm::beSigned(Bureaucrat& b) {
	if (b.getGrade() > grade_execute)
		throw GradeTooLowException();
	is_signed = true;
}