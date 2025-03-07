/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:42:00 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/06 23:42:01 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <cmath>

Span::Span(unsigned int N) : capacity(N) {}

Span::Span(const Span& other) : capacity(other.capacity), numbers(other.numbers) {}

Span::~Span() {}

void Span::addNumber(int number) {
	if (numbers.size() >= capacity)
		throw std::overflow_error("Span is full");
	numbers.push_back(number);
}

int Span::shortestSpan() const {
	if (numbers.size() < 2)
		throw std::logic_error("Insufficient elements for span calculation");
	
	std::vector<int> sorted(numbers);
	std::sort(sorted.begin(), sorted.end());
	
	int min_span = sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); ++i) {
		int current_span = sorted[i] - sorted[i-1];
		if (current_span < min_span)
			min_span = current_span;
	}
	return min_span;
}

int Span::longestSpan() const {
	if (numbers.size() < 2)
		throw std::logic_error("Insufficient elements for span calculation");
	
	std::vector<int> sorted(numbers);
	std::sort(sorted.begin(), sorted.end());
	return sorted.back() - sorted.front();
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		capacity = other.capacity;
		numbers = other.numbers;
	}
	return *this;
}