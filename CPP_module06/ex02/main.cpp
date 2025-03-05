/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:43:23 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/05 02:43:37 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify.hpp"

int main() {
    Base* obj = Identify::generate();
    Identify::identify(obj);
    Identify::identify(*obj);
    delete obj;
    return 0;
}