/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:58:09 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/04 02:58:11 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destroyed" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > getGrade_execute())
		throw GradeTooLowException();
	std::ofstream of((target + "_shrubbery").c_str());
	of << "	      42 42 424242 42 42 \n"
	   << "      42 42\\/42\\42 42| 42 ,\n"
	   << "      42\\/(/42/42||/42 /42/42\n"
	   << "   42()42\\/42||()|/42\\/ 42\"()\n"
	   << "  42_\\_42 |42||42/42__42_/_\n"
	   << "42   42 4242| || /2 4 % ()\n"
	   <<" ()42 42 ()42\\42\\|42-42-()~\n"
	   << "     42     \\|||\n"
	   << "              ||\n"
	   << "              ||\n"
	   << "              ||\n"
	   << " 4242424244242424242424242424242424\"\n";
	of.close();
	std::cout << "Shrubbery created at " << target << std::endl;
}