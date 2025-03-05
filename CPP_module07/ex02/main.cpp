/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:31:57 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/05 15:34:33 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <stdlib.h>

#define MAX_VAL 10

int main(int, char**) {
    Array<int> numbers(MAX_VAL); // Create an array of MAX_VAL elements
    int* mirror = new int[MAX_VAL]; // Create a raw array to mirror the values
    
    srand(time(NULL)); // Seed random number generator

    std::cout << "Initiating <int> numbers[] and mirror with random values:" << std::endl;
    
    // Fill both arrays with random values
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand() % 100;
        numbers[i] = value;    // Store value in Array class instance
        mirror[i] = value;     // Store value in raw array (mirror)
        std::cout << value << ", ";  // Print each random value
    }
    std::cout << std::endl;

    // Creating a temporary Array and copy to another to test copy constructor and assignment operator
    {
        std::cout << "Entering SCOPE to test copy constructor and assignment operator..." << std::endl;
        Array<int> tmp = numbers; // Copy constructor is called
        Array<int> test(tmp); // Copy constructor is called again
        std::cout << "Exiting SCOPE. Arrays tmp and test are now destructed." << std::endl;
    }

    // Check if the values are identical in both the original array (numbers) and the mirror array
    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "Values do not match! There was an error during copy or assignment!" << std::endl;
            return 1;
        }
    }
    std::cout << "Values matched, copy and assignment seem to work correctly." << std::endl;

    // Test out-of-bounds exceptions with invalid indices
    try {
        std::cout << "Attempting to access out-of-bounds index (-2)..." << std::endl;
        numbers[-2] = 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Attempting to access out-of-bounds index (MAX_VAL)..." << std::endl;
        numbers[MAX_VAL] = 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    // Fill the array again with new random values
    std::cout << "Filling numbers array with new random values:" << std::endl;
    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand() % 100;
    }
    std::cout << "Done filling numbers array." << std::endl;

    delete[] mirror; // Free the mirror array
    
    return 0;
}


// #include <iostream>
// #include <Array.hpp>

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }