/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:41:24 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/04 22:41:27 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <string>
#include <stdexcept> 

class Bureaucrat;

class AForm {
	
	private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;

	public:
	AForm();
	AForm(const std::string& name, const int gradeToSign, const int gradeToExecute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();


	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
		
	class FormNotSignedException : public std::exception {
		const char* what() const throw();
	};
	
	void beSigned(const Bureaucrat& bureaucrat);
	
	int getGradeToSign() const;
	int getGradeToExecute() const;
	std::string getName() const;
	bool getIsSigned() const;

	virtual void execute(const Bureaucrat& executor) const = 0;
	

};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);


#endif