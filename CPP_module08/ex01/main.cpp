/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:42:17 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/06 23:42:18 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Basic functionality test
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Overflow test
    try {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4); // Should throw
    } catch (const std::exception& e) {
        std::cout << "Overflow test: " << e.what() << std::endl;
    }

    // Large dataset test
    try {
        Span sp(10000);
        for (int i = 0; i < 10000; ++i) {
            sp.addNumber(i * 2);
        }
        std::cout << "Large dataset shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Large dataset longest: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Random numbers test
    try {
        Span sp(10000);
        std::srand(std::time(0));
        for (int i = 0; i < 10000; ++i) {
            sp.addNumber(std::rand() % 1000000);
        }
        std::cout << "Random shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Random longest: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
