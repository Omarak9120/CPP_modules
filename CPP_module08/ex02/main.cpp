/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 02:06:17 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/07 02:06:19 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	{
		std::cout << "Test Case 1: \n";
		MutantStack<int> mstack;
		mstack.push(5); 
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while(it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "========================\n";
		std::cout << "Test Case 2: \n";
		MutantStack<int> mstack;
		std::cout << "Stack size: " << mstack.size() << std::endl;  // Expected: 0
		std::cout << "Stack empty: " << mstack.empty() << std::endl;  // Expected: 1 (true)

	}
	{
		std::cout << "========================\n";
		std::cout << "Test Case 3: \n";
		MutantStack<std::string> strStack;
		strStack.push("Hello");
		strStack.push("World");

		std::cout << "Top of string stack: " << strStack.top() << std::endl;  // Expected: World
		std::cout << "Stack size: " << strStack.size() << std::endl;  // Expected: 2

		MutantStack<float> floatStack;
		floatStack.push(3.14f);
		floatStack.push(2.71f);

		std::cout << "Top of float stack: " << floatStack.top() << std::endl;  // Expected: 2.71
		std::cout << "Stack size: " << floatStack.size() << std::endl;  // Expected: 2

	}
	{
		std::cout << "========================\n";
		std::cout << "Test Case 4: \n";
		MutantStack<int> mstack;
		mstack.push(10);
		mstack.push(20);

		MutantStack<int> copyStack(mstack);  // Using copy constructor
		std::cout << "Top of copy stack: " << copyStack.top() << std::endl;  // Expected: 20
		std::cout << "Size of copy stack: " << copyStack.size() << std::endl;  // Expected: 2

		MutantStack<int> assignedStack;
		assignedStack.push(100);
		assignedStack = mstack;  // Using assignment operator
		std::cout << "Top of assigned stack: " << assignedStack.top() << std::endl;  // Expected: 20
		std::cout << "Size of assigned stack: " << assignedStack.size() << std::endl;  // Expected: 2
	}
	{
		std::cout << "========================\n";
		std::cout << "Test Case 5: \n";
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(737);

		std::cout << "Iterating in reverse order:" << std::endl;
		MutantStack<int>::iterator it = mstack.end();
		--it;  // Points to the last element (737)
		while (it != mstack.begin()) {
			std::cout << *it << std::endl;
			--it;
		}
		std::cout << *it << std::endl;  // Expected: 5 (the first element)
	}

	return 0;
}
