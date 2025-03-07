/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:56:57 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/06 22:56:59 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>


int main() {
    try {
        std::cout << "Test case 1: [Vector]" << std::endl;
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        std::cout << "Found: " << *easyfind(vec, 3) << std::endl;

        std::cout << "======================\n";
        std::cout << "Test case 2: [List]" << std::endl;
        std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);
        lst.push_back(4);
        lst.push_back(5);
        std::cout << "Found: " << *easyfind(lst, 3) << std::endl;

        std::cout << "======================\n";
        std::cout << "Test case 3: [Deque]" << std::endl;
        std::deque<int> deq;
        deq.push_back(1);
        deq.push_back(2);
        deq.push_back(3);
        deq.push_back(4);
        deq.push_back(5);
        std::cout << "Found: " << *easyfind(deq, 3) << std::endl;

        std::cout << "======================\n";
        std::cout << "Attempting to find value 10..." << std::endl;
        easyfind(vec, 10);  // Should throw an exception

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

// int main() {
//     try {
//         std::vector<int> vec = {1, 2, 3, 4, 5};
//         std::cout << "Found: " << *easyfind(vec, 3) << std::endl;

//         std::list<int> lst = {1, 2, 3, 4, 5};
//         std::cout << "Found: " << *easyfind(lst, 3) << std::endl;

//         std::deque<int> deq = {1, 2, 3, 4, 5};
//         std::cout << "Found: " << *easyfind(deq, 3) << std::endl;

//         std::array<int, 5> arr = {1, 2, 3, 4, 5};
//         std::cout << "Found: " << *easyfind(arr, 3) << std::endl;

//         easyfind(vec, 10);  // Should throw an exception
//     }
//     catch (const std::exception& e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//     }

//     return 0;
// }

// #include "easyfind.hpp"
// #include <string>
// #include <vector>
// #include <list>
// #include <map>

// int main() {
//     try {
//         std::cout << "Test case 1: [Vector]"<< std::endl;
//         std::vector<int> vec;
//         vec.push_back(1);
//         vec.push_back(2);
//         vec.push_back(3);
//         vec.push_back(4);
//         vec.push_back(5);
//         std::vector<int>::iterator it = easyfind(vec, 3);
//         std::cout << "Found value: " << *it << std::endl;

//         it = easyfind(vec, 10);
//     } catch (const std::exception& e) {
//         std::cout << "Error: " << e.what() << std::endl;
//     }

//     try {
//         std::cout << "======================\n";
//         std::cout << "Test case 2: [List]"<< std::endl;
//         std::list<int> list;
//         list.push_back(1);
//         list.push_back(2);
//         list.push_back(3);
//         list.push_back(4);
//         list.push_back(5);
//         std::list<int>::iterator it = easyfind(list, 3);
//         std::cout << "Found value: " << *it << std::endl;

//         it = easyfind(list, 10);
//     } catch (const std::exception& e) {
//         std::cout << "Error: " << e.what() << std::endl;
//     }

//     return 0;
// }