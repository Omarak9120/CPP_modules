/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:35:35 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/04 22:35:45 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept> 
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	
	private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;

	public:
	Form();
	Form(const std::string& name, const int gradeToSign, const int gradeToExecute);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();


	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
		
	void beSigned(const Bureaucrat& bureaucrat);
	
	int getGradeToSign() const;
	int getGradeToExecute() const;
	std::string getName() const;
	bool getIsSigned() const;
	

};

std::ostream& operator<<(std::ostream& os, const Form& form);


#endif