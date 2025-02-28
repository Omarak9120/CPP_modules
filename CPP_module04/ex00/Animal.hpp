/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:04:40 by oabdelka          #+#    #+#             */
/*   Updated: 2025/02/25 14:04:40 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string type;
	public:
		Animal();                            
		Animal(const Animal& other);         
		Animal& operator=(const Animal& other);
		Animal(std::string type);            
		virtual ~Animal();                   
		virtual void makeSound() const;
		std::string getType() const;
};

#endif
