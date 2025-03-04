/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:40:32 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/04 22:40:36 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept> 
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Bureaucrat {
	
	private:
	const std::string name;
	int grade;

	public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();


	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return "Grade is too high";
		}
	};
	
	class GradeTooLowException : public std::exception {
	public:
	const char* what() const throw() {
			return "Grade is too low";
		}
	};
		
	
	int getGrade() const;
	std::string getName() const;
	
	void incrementGrade();
	void decrementGrade();

	
	void signAForm(AForm& Aform);
	void executeAForm(ShrubberyCreationForm& ShrubberyCreationForm);
	void executeBForm(RobotomyRequestForm& RobotomyRequestForm);
	void executeCForm(PresidentialPardonForm& PresidentialPardonForm);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);


#endif