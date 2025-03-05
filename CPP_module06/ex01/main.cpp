/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:30:30 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/05 02:36:11 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
    Data* original = new Data;
    original->value = 42;
    original->message = "I'm omar";

    // Serialize the pointer
    uintptr_t raw = Serializer::serialize(original);
    
    // Deserialize back to pointer
    Data* restored = Serializer::deserialize(raw);

    // Verify pointer equality
    if (original == restored) {
        std::cout << "Serialization/deserialization successful!\n";
        std::cout << "Original value: " << original->value 
                  << ", message: " << original->message << "\n";
        std::cout << "Restored value: " << restored->value 
                  << ", message: " << restored->message << "\n";
    } else {
        std::cout << "Error: Pointers don't match!\n";
    }

    delete original;
    return 0;
}