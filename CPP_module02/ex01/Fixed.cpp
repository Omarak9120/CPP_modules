/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:12:16 by oabdelka          #+#    #+#             */
/*   Updated: 2025/02/24 13:32:25 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>    // For roundf

// Default Constructor
Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Copy Constructor
Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other; // Utilize copy assignment operator
}

// Copy Assignment Operator
Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_fixedPointValue = other.getRawBits();
	}
	return *this;
}

// Destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// Integer Constructor(multiplying by 256)
Fixed::Fixed(const int intValue) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = intValue << _fractionalBits;
}

// Floating-Point Constructor(multiplying by 256 and rounding)
Fixed::Fixed(const float floatValue) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(floatValue * (1 << _fractionalBits));
}

// getRawBits
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

// setRawBits
void Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

// toFloat
float Fixed::toFloat(void) const {
	return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

// toInt(/ 256)
int Fixed::toInt(void) const {
	return this->_fixedPointValue >> _fractionalBits;
}

// Overload of the insertion operator
std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
