/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:00:18 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/05 15:00:20 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T> void iter(T* arr, std::size_t len, void (*func)(T&)) {
	for (std::size_t i = 0 ;i < len; i++)
		func(arr[i]);
}

#endif