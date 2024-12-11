/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:27:11 by oabdelka          #+#    #+#             */
/*   Updated: 2024/12/11 15:27:12 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
private:
    std::string name;

public:
    // Constructors
    Zombie();
    Zombie(std::string name);

    // Destructor
    ~Zombie();

    // Member Functions
    void announce(void);
    void setName(std::string name);
};

#endif // ZOMBIE_HPP
