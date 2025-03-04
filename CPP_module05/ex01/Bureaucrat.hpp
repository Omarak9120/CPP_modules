/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:35:30 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/04 22:35:39 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept> 
#include "Form.hpp"

class Form;

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

	
	void signForm(Form& form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);


#endif