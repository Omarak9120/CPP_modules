/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:28:57 by oabdelka          #+#    #+#             */
/*   Updated: 2025/02/20 15:02:49 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << "Initial value of a: " << a << std::endl;
    std::cout << "Pre-increment: " << ++a << std::endl;
    std::cout << "After pre-increment: " << a << std::endl;
    std::cout << "Post-increment: " << a++ << std::endl;
    std::cout << "After post-increment: " << a << std::endl;

    std::cout << "Multiplication result (5.05 * 2): " << b << std::endl;

    // Arithmetic operations
    Fixed x(10.5f);
    Fixed y(2.0f);
    std::cout << "x + y = " << x + y << std::endl;
    std::cout << "x - y = " << x - y << std::endl;
    std::cout << "x * y = " << x * y << std::endl;
    std::cout << "x / y = " << x / y << std::endl;

    // Min & Max
    std::cout << "Max of x and y: " << Fixed::max(x, y) << std::endl;
    std::cout << "Min of x and y: " << Fixed::min(x, y) << std::endl;

    return 0;
}
