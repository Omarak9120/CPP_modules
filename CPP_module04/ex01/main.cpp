/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:32:03 by oabdelka          #+#    #+#             */
/*   Updated: 2025/02/25 15:32:03 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "Animal.hpp"

int main()
{
	Animal *OMAR[10];
	for (int i = 0; i < 5; i++)
	{
	    OMAR[i] = new Dog();
	}
	for (int i = 5; i < 10; i++)
	{
	    OMAR[i] = new Cat();
	}
	for (int i = 0; i < 10; i++)
	{
	    delete OMAR[i];
	}
}
