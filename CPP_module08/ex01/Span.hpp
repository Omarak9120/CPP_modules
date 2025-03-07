/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:41:45 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/06 23:41:52 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span {
private:
	unsigned int capacity;
	std::vector<int> numbers;

public:
	Span(unsigned int N);
	Span(const Span& other);
	~Span();
	
	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;
	
	Span& operator=(const Span& other);
};

#endif
