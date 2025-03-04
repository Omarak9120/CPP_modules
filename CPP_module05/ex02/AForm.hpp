/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:57:32 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/04 02:57:33 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class AForm {
	private:
		const std::string name;
		bool is_signed;
		const int grade_sign;
		const int grade_execute;

	protected:
		AForm(std::string name, int grade_sign, int grade_execute);
		
	public :
		virtual ~AForm();
		std::string getName() const ;
		bool getIs_signed() const;
		int getGrade_sign() const;
		int getGrade_execute() const;
		void beSigned(Bureaucrat& b);
		virtual void execute(Bureaucrat const & executor) const = 0;
		class GradeTooHighException: std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				const char *what() const throw();
		};
		class FormNotSignedException : public std::exception {
			const char* what() const throw() {
				return "Form not signed";
			}
		};
};

std::ostream& operator << (std::ostream &os, AForm& f);
#endif
