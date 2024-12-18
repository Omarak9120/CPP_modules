/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:29:03 by oabdelka          #+#    #+#             */
/*   Updated: 2024/12/18 15:29:11 by oabdelka         ###   ########.fr       */
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
    Fixed(const int intValue);
    Fixed(const float floatValue);

    // Member Functions
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;

    // Comparison operators
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // Arithmetic operators
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const; // If division by zero occurs, program may crash, as allowed by the exercise.

    // Increment/Decrement operators
    // Pre-increment/decrement
    Fixed& operator++();    // ++a
    Fixed& operator--();    // --a

    // Post-increment/decrement
    Fixed operator++(int);  // a++
    Fixed operator--(int);  // a--

    // Static member functions for min/max
    static Fixed& min(Fixed &a, Fixed &b);
    static const Fixed& min(const Fixed &a, const Fixed &b);
    static Fixed& max(Fixed &a, Fixed &b);
    static const Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif
