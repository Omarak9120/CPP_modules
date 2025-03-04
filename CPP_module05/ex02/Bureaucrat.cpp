/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:57:36 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/04 02:57:37 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
	if (grade < 1) {
		throw GradeTooHighException();
	}
	if (grade > 150) {
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(Bureaucrat& other) {
	*this = other;
}

Bureaucrat::~Bureaucrat() {
	std::cout << name << " Destroyed\n";
}

Bureaucrat& Bureaucrat::operator = (Bureaucrat& other) {
	if  (this != &other) 
		this->grade = other.grade;
	return *this;
}

int Bureaucrat::getGrade() const {
	return grade;
}

std::string Bureaucrat::getName() {
	return name;
}

void Bureaucrat::incrementGrade() {
	this->grade--;
	if (grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
	this->grade++;
	if (grade > 150)
		throw GradeTooLowException();
}

std::ostream& operator << (std::ostream &os, Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
	return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!\n";
}

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	} catch (AForm::GradeTooHighException &e) {
		std::cout << name << " couldn’t sign " << form.getName() 
				  << " because " << e.what() << std::endl;
	} catch (AForm::GradeTooLowException &e) {
		std::cout << name << " couldn’t sign " << form.getName() 
				  << " because " << e.what() << std::endl;
	}
}

// void Bureaucrat::executeForm(AForm const &form) {
//     try {
//         form.execute(*this);
//         std::cout << this->getName() << " executed " << form.getName() << std::endl;
//     } catch (std::exception &e) {
//         std::cout << "Failed to execute " << form.getName() << ": " << e.what() << std::endl;
//     }
// }

void Bureaucrat::executeForm(AForm const &form) {
	try {
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Failed to execute " << form.getName()
				  << ": " << e.what() << std::endl;
	}
}