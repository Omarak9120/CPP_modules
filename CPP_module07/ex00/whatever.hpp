/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:54:45 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/05 14:54:46 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include "iostream"

template <typename T> void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

// Min function template
template <typename T> const T& min(const T& a, const T& b) {
	return (a < b) ? a : b;
}

// Max function template
template <typename T> const T& max(const T& a, const T& b) {
	return (a > b) ? a : b;
}
#endif