/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:29:15 by oabdelka          #+#    #+#             */
/*   Updated: 2024/12/18 15:29:18 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// Default Constructor
Fixed::Fixed() : _fixedPointValue(0) {
    // Could print debug messages if desired
}

// Copy Constructor
Fixed::Fixed(const Fixed &other) {
    *this = other; // Utilize copy assignment operator
}

// Copy Assignment Operator
Fixed& Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

// Destructor
Fixed::~Fixed() {
    // Could print debug messages if desired
}

// Integer Constructor(multiplying by 256)
Fixed::Fixed(const int intValue) {
    this->_fixedPointValue = intValue << _fractionalBits;
}

// Floating-Point Constructor(multiplying by 256 and rounding)
Fixed::Fixed(const float floatValue) {
    this->_fixedPointValue = (int)roundf(floatValue * (1 << _fractionalBits));
}

// getRawBits
int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

// setRawBits
void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

// toFloat
float Fixed::toFloat(void) const {
    return (float)this->_fixedPointValue / (float)(1 << _fractionalBits);
}

// toInt(/ 256)
int Fixed::toInt(void) const {
    return this->_fixedPointValue >> _fractionalBits;
}

// Comparison operators
bool Fixed::operator>(const Fixed &other) const {
    return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->_fixedPointValue != other._fixedPointValue;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->_fixedPointValue + other._fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->_fixedPointValue - other._fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    // Multiplying two fixed-point numbers:
    // (this * other) = (this_raw * other_raw) / 2^(fractionalBits = 8)
    long long product = (long long)this->_fixedPointValue * (long long)other._fixedPointValue;
    // Shift right by fractionalBits to scale back
    Fixed result;
    result.setRawBits((int)(product >> _fractionalBits));
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    // Dividing two fixed-point numbers:
    // (this / other) = (this_raw * 2^(fractionalBits)) / other_raw
    if (other._fixedPointValue == 0) {
        // 7a 5alliya ta3mel crash XD
    }

    long long numerator = ((long long)this->_fixedPointValue << _fractionalBits);
    long long quotient = numerator / other._fixedPointValue;

    Fixed result;
    result.setRawBits((int)quotient);
    return result;
}

// Increment/Decrement operators
// Pre-increment: ++a
Fixed& Fixed::operator++() {
    this->_fixedPointValue += 1;
    return *this;
}

// Post-increment: a++
Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->_fixedPointValue += 1;
    return temp;
}

// Pre-decrement: --a
Fixed& Fixed::operator--() {
    this->_fixedPointValue -= 1;
    return *this;
}

// Post-decrement: a--
Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->_fixedPointValue -= 1;
    return temp;
}

// Static member functions for min and max
Fixed& Fixed::min(Fixed &a, Fixed &b) {
    if (a < b)
        return a;
    else
        return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    if (a < b)
        return a;
    else
        return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    if (a > b)
        return a;
    else
        return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b)
        return a;
    else
        return b;
}

// Overload of the insertion operator
std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
