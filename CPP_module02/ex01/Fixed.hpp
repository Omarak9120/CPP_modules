/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:08:09 by oabdelka          #+#    #+#             */
/*   Updated: 2024/12/18 12:07:20 by oabdelka         ###   ########.fr       */
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

    // Additional Constructors
    Fixed(const int intValue);               // Integer Constructor
    Fixed(const float floatValue);           // Floating-Point Constructor

    // Member Functions
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
};

// Overload of the insertion operator
std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP

