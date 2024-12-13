/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:13:50 by oabdelka          #+#    #+#             */
/*   Updated: 2024/12/13 13:13:51 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Harl.hpp"

int main(int argc, char* argv[]) {
    Harl harl;

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
        std::cerr << "Levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
        return 1;
    }

    std::string level = argv[1];
    harl.complain(level);

    return 0;
}
