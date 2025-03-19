/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:45:38 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/19 21:45:39 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: Usage ./RPN \"expression\"" << std::endl;
        return 1;
    }

    int result = RPN::evaluate(argv[1]);
    if (result != -1)
        std::cout << result << std::endl;

    return 0;
}
