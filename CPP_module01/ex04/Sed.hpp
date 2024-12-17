/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:16:55 by oabdelka          #+#    #+#             */
/*   Updated: 2024/12/13 13:47:15 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <string>

class Sed {
private:
	std::string s1;
	std::string s2;

public:
	// Constructor
	Sed(const std::string& s1, const std::string& s2);

	// Function to perform the replacement
	std::string replaceAll(const std::string& input) const;
};

#endif