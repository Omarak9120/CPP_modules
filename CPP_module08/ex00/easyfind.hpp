/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:56:48 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/06 22:56:49 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <exception>
#include <string>
#include <sstream>

template <typename T>
typename T::iterator easyfind(T& container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		std::ostringstream oss;
		oss << "Value " << value << " not found in container";
		throw std::runtime_error(oss.str());
	}
	return it;
}


#endif

// #ifndef EASYFIND_HPP
// #define EASYFIND_HPP

// #include <iostream>
// #include <algorithm>
// #include <iterator>
// #include <exception>

// template <typename T> typename T::iterator easyfind(T& container, int value) {
//     typename T::iterator it = std::find(container.begin(), container.end(), value);
//     if (it == container.end()) {
//         throw std::runtime_error("Value not found");
//     }
//     return it;
// }

// #endif