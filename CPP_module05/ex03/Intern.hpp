/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:41:38 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/04 23:01:26 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern {
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm* makeForm(const std::string& formName, const std::string& target);

private:
	// Helper function to create forms
	AForm* createShrubberyCreationForm(const std::string& target);
	AForm* createRobotomyRequestForm(const std::string& target);
	AForm* createPresidentialPardonForm(const std::string& target);

	// Array of function pointers for form creation
	typedef AForm* (Intern::*FormCreator)(const std::string&);
	static const std::string _formNames[3];
	static const FormCreator _formCreators[3];
};

#endif