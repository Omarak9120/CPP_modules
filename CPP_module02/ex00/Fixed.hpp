/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:08:09 by oabdelka          #+#    #+#             */
/*   Updated: 2025/02/24 13:32:17 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int                 _fixedPointValue;
	static const int    _fractionalBits = 8;

public:
	// Orthodox Canonical Form
	Fixed();                                 // Default Constructor
	Fixed(const Fixed &other);               // Copy Constructor
	Fixed& operator=(const Fixed &other);    // Copy Assignment Operator
	~Fixed();                                // Destructor

	// Member Functions
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
