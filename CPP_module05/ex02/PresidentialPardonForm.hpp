/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:57:57 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/04 02:57:58 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	std::string target;

public:
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();

	void execute(Bureaucrat const &executor) const;
};

#endif