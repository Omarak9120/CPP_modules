/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:40:17 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/04 22:40:21 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default AForm"), isSigned(false), gradeToSign(50), gradeToExecute(50) {}

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExecute) : name(name) , isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if(gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooLowException();
	else if(gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooHighException();
	
}

AForm::AForm(const AForm& other) : name(other.name), isSigned(false), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
	std::cout << "AForm copy asignment called" << std::endl ;
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

AForm::~AForm() {
	std::cout << name << " destroyed." << std::endl;
}

int AForm::getGradeToSign() const {
	return gradeToSign;
}

int AForm::getGradeToExecute() const {
	return gradeToExecute;
}

std::string AForm::getName() const {
	return name;
}

bool AForm::getIsSigned() const {
	return isSigned;
}
const char* AForm::GradeTooHighException::what() const throw() {
	return "AForm grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "AForm grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed!";
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const {
	if (!isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException();
}


std::ostream& operator<<(std::ostream& os, const AForm& AForm) {
	os << "AForm: " << AForm.getName() 
	   << " | Signed: " << (AForm.getIsSigned() ? "Yes" : "No")
	   << " | Grade Required to Sign: " << AForm.getGradeToSign()
	   << " | Grade Required to Execute: " << AForm.getGradeToExecute();
	return os;
}