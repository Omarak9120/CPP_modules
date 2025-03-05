/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:31:52 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/05 15:31:56 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <cstddef>

template <typename T>
class Array {
private:
	T* elements;
	std::size_t _size;

public:
	Array() : elements(NULL), _size(0) {}

	Array(unsigned int n) : elements(new T[n]()), _size(n) {}

	Array(const Array& other) : elements(NULL), _size(0) {
		*this = other;
	}

	~Array() {
		delete[] elements;
	}

	Array& operator=(const Array& other) {
		if (this != &other) {
			delete[] elements;

			_size = other._size;
			elements = (_size > 0) ? new T[_size]() : NULL;

			for (std::size_t i = 0; i < _size; i++) {
				elements[i] = other.elements[i];
			}
		}
		return *this;
	}

	T& operator[](std::size_t index) {
		if (index >= _size) {
			throw std::out_of_range("Index out of bounds");
		}
		return elements[index];
	}

	const T& operator[](std::size_t index) const {
		if (index >= _size) {
			throw std::out_of_range("Index out of bounds");
		}
		return elements[index];
	}

	std::size_t size() const {
		return _size;
	}
};

#endif
