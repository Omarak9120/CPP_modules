/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:12:27 by oabdelka          #+#    #+#             */
/*   Updated: 2025/02/24 13:32:31 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{

	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "\n **Using toFloat() Function** \n";
	std::cout << "a.toFloat() = " << a.toFloat() << std::endl;
	std::cout << "b.toFloat() = " << b.toFloat() << std::endl;
	std::cout << "c.toFloat() = " << c.toFloat() << std::endl;
	std::cout << "d.toFloat() = " << d.toFloat() << std::endl;
	
	std::cout << "\n **Converting to Integer using toInt()** \n";
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}