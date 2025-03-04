/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:27:13 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/03 23:31:55 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	std::cout << "Bureaucrat " << name << " created with grade " << grade << "\n";
}

Bureaucrat::Bureaucrat(Bureaucrat& other)
{
	std::cout << "Bureaucrat Copy constructor called.\n";
	*this = other;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << name << " destroyed\n";
}

Bureaucrat& Bureaucrat::operator = (Bureaucrat& other)
{
	std::cout << "Bureaucrat Copy assignment operator called.\n";
	if  (this != &other) 
		this->grade = other.grade;
	return *this;
}

int Bureaucrat::getGrade()
{
	return grade;
}

std::string Bureaucrat::getName()
{
	return name;
}

void Bureaucrat::incrementGrade()
{
	this->grade--;
	if (grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	this->grade++;
	if (grade > 150)
		throw GradeTooLowException();
}

std::ostream& operator << (std::ostream &os, Bureaucrat& b)
{
	os << b.getName() << ",bureaucrat grade " << b.getGrade() << "\n";
	return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low\n";
}
