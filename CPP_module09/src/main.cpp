/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:27:21 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/17 23:37:27 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <cerrno>
#include <set>

// Function to check if the container is sorted
template <typename T>
bool isSorted(const T& container) {
    size_t i = 1;
    while (i < container.size()) {
        if (container[i] < container[i - 1]) {
            return false; // Not sorted
        }
        ++i;
    }
    return true; // Sorted
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "\033[1;31mError: No input provided.\033[1;39m" << std::endl;
        return 1;
    }

    std::vector<int> input;
    std::set<int> unique_numbers; // To check for duplicates

    int i = 1;
    while (i < argc) {
        char* endptr;
        long num = strtol(argv[i], &endptr, 10);

        // Check for conversion errors
        if (*endptr != '\0' || num <= 0 || errno == ERANGE) {
            std::cerr << "\033[1;31mError: Invalid input '" << argv[i] << "'. Must be a positive integer.\033[1;39m" << std::endl;
            return 1;
        }

        // Check for duplicates
        if (!unique_numbers.insert(num).second) { 
            std::cerr << "\033[1;31mError: Duplicate number '" << num << "' found.\033[1;39m" << std::endl;
            return 1;
        }

        input.push_back(static_cast<int>(num));
        ++i;
    }

    // Display unsorted sequence
    std::cout << "\033[1;34mBefore:\033[1;39m";
    for (size_t j = 0; j < input.size(); ++j) {
        std::cout << " " << input[j];
    }
    std::cout << std::endl;

    // Create containers for sorting
    std::deque<int> dq(input.begin(), input.end());
    std::vector<int> vec(input.begin(), input.end());

    // Time deque sorting
    clock_t start = clock();
    sort_deque(dq);
    clock_t end = clock();
    double deque_time = (double)(end - start) / CLOCKS_PER_SEC * 1e6; // Convert to microseconds

    // Time vector sorting
    start = clock();
    sort_vector(vec);
    end = clock();
    double vector_time = (double)(end - start) / CLOCKS_PER_SEC * 1e6;

    // Display sorted sequence
    std::cout << "\033[1;34mAfter:\033[1;39m";
    for (std::deque<int>::iterator it = dq.begin(); it != dq.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;

    // Display timing results
    std::cout << "\033[1;33mTime to process " << input.size() << " elements with std::deque : " 
              << deque_time << " us\033[1;39m" << std::endl;
    std::cout << "\033[1;33mTime to process " << input.size() << " elements with std::vector : " 
              << vector_time << " us\033[1;39m" << std::endl;

    // Verify if both containers are sorted
    std::cout << (isSorted(dq) ? "\033[1;32mDeque is sorted.\033[1;39m" : "\033[1;31mDeque is not sorted.\033[1;39m") << std::endl;
    std::cout << (isSorted(vec) ? "\033[1;32mVector is sorted.\033[1;39m" : "\033[1;31mVector is not sorted.\033[1;39m") << std::endl;

    return 0;
}
