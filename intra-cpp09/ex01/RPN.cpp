/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:45:42 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/19 21:45:46 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int RPN::evaluate(const std::string &expression)
{
	std::stack<int> stack;
	std::istringstream ss(expression);
	std::string token;

	while (ss >> token)
	{
		if (isdigit(token[0]) && token.length() == 1)
		{  
			// If it's a single digit number
			stack.push(token[0] - '0');
		} 
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (stack.size() < 2)
			{
				std::cerr << "Error: Invalid expression" << std::endl;
				return -1;
			}
			int b = stack.top(); stack.pop();
			int a = stack.top(); stack.pop();
			
			if (token == "+") stack.push(a + b);
			else if (token == "-") stack.push(a - b);
			else if (token == "*") stack.push(a * b);
			else if (token == "/") {
				if (b == 0)
				{
					std::cerr << "Error: Division by zero" << std::endl;
					return -1;
				}
				stack.push(a / b);
			}
		} 
		else
		{
			std::cerr << "Error: Invalid character" << std::endl;
			return -1;
		}
	}

	if (stack.size() != 1)
	{
		std::cerr << "Error: Invalid expression" << std::endl;
		return -1;
	}
	return stack.top();
}
