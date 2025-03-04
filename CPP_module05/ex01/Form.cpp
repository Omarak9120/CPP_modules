/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:35:32 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/04 22:35:42 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Default Form"), isSigned(false), gradeToSign(50), gradeToExecute(50) {}

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExecute) : name(name) , isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if(gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooLowException();
	else if(gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooHighException();
	
}

Form::Form(const Form& other) : name(other.name), isSigned(false), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
	std::cout << "Form copy asignment called" << std::endl ;
}

Form& Form::operator=(const Form& other) {
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

Form::~Form() {
	std::cout << name << " destroyed." << std::endl;
}

int Form::getGradeToSign() const {
	return gradeToSign;
}

int Form::getGradeToExecute() const {
	return gradeToExecute;
}

std::string Form::getName() const {
	return name;
}

bool Form::getIsSigned() const {
	return isSigned;
}
const char* Form::GradeTooHighException::what() const throw() {
	return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form grade is too low!";
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form: " << form.getName() 
	   << " | Signed: " << (form.getIsSigned() ? "Yes" : "No")
	   << " | Grade Required to Sign: " << form.getGradeToSign()
	   << " | Grade Required to Execute: " << form.getGradeToExecute();
	return os;
}