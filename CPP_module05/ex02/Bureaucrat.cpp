/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:40:28 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/04 22:40:31 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) , grade(grade) {
	if(grade < 1)
		throw GradeTooLowException();
	else if(grade > 150)
		throw GradeTooHighException();
	
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {
	std::cout << "Bureaucrat copy asignment called" << std::endl ;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		this->grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << name << " destroyed." << std::endl;
}

int Bureaucrat::getGrade() const {
	return grade;
}

std::string Bureaucrat::getName() const {
	return name;
}

void Bureaucrat::incrementGrade() {
	if (grade - 1 < 1) {
		throw GradeTooHighException();
	}
	grade--;
}

void Bureaucrat::decrementGrade() {
	if (grade + 1 > 150) {
		throw GradeTooLowException();
	}
	grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}

void Bureaucrat::signAForm(AForm& Aform) {
	try {
		Aform.beSigned(*this);
		std::cout << name << " signed " << Aform.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << name << " couldn't sign " << Aform.getName() 
				  << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeAForm(ShrubberyCreationForm& ShrubberyCreationForm) {
	try {
		ShrubberyCreationForm.execute(*this);
		std::cout << name << " executed " << ShrubberyCreationForm.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << name << " couldn't execute " << ShrubberyCreationForm.getName() 
				  << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeBForm(RobotomyRequestForm& RobotomyRequestForm) {
	try {
		RobotomyRequestForm.execute(*this);
		std::cout << name << " executed " << RobotomyRequestForm.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << name << " couldn't execute " << RobotomyRequestForm.getName() 
				  << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeCForm(PresidentialPardonForm& PresidentialPardonForm) {
	try {
		PresidentialPardonForm.execute(*this);
		std::cout << name << " executed " << PresidentialPardonForm.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << name << " couldn't execute " << PresidentialPardonForm.getName() 
				  << " because " << e.what() << std::endl;
	}
}