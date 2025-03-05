/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 01:50:55 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/05 02:11:05 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <string.h>
#include <cmath>
#include <limits>
#include <sstream>
#include <iostream>

static bool isChar(const std::string &input) {
    return (input.size() == 3 && input[0] == '\'' && input[2] == '\'') || input.size() == 1;
}

// Parse char from quoted or unquoted input
static char parseChar(const std::string &input) {
    if (input.size() == 3) // Quoted char like 'a'
        return input[1];
    else // Single character like a
        return input[0];
}

static bool isFloat(const std::string &input) {
    if (input.empty() || input[input.size() - 1] != 'f')  // Fixed for C++98
        return false;
    if (input.size() == 1)
        return false;
    std::string substr = input.substr(0, input.size() - 1);
    if (substr == "inf" || substr == "+inf" || substr == "-inf" || substr == "nan")
        return true;
    char* end;
    std::strtod(substr.c_str(), &end);
    return end == substr.c_str() + substr.size();
}

static float parseFloat(const std::string &input) {
    std::string substr = input.substr(0, input.size() - 1);
    if (substr == "inf" || substr == "+inf")
        return std::numeric_limits<float>::infinity();
    if (substr == "-inf")
        return -std::numeric_limits<float>::infinity();
    if (substr == "nan")
        return std::numeric_limits<float>::quiet_NaN();
    return static_cast<float>(std::strtod(substr.c_str(), NULL));
}

static bool isDouble(const std::string &input) {
    if (input == "inf" || input == "+inf" || input == "-inf" || input == "nan")
        return true;
    char* end;
    std::strtod(input.c_str(), &end);
    return end == input.c_str() + input.size();
}

static double parseDouble(const std::string &input) {
    if (input == "inf" || input == "+inf")
        return std::numeric_limits<double>::infinity();
    if (input == "-inf")
        return -std::numeric_limits<double>::infinity();
    if (input == "nan")
        return std::numeric_limits<double>::quiet_NaN();
    return std::strtod(input.c_str(), NULL);
}

static bool isInt(const std::string &input) {
    if (input.empty())
        return false;
    size_t start = 0;
    if (input[0] == '-' || input[0] == '+') {
        start = 1;
        if (input.size() == 1)
            return false;
    }
    for (size_t i = start; i < input.size(); ++i) {
        if (!isdigit(input[i]))
            return false;
    }
    long l = std::strtol(input.c_str(), NULL, 10);
    return l >= std::numeric_limits<int>::min() && l <= std::numeric_limits<int>::max();
}

static int parseInt(const std::string &input) {
    return std::atoi(input.c_str());
}

static void printChar(char c) {
    if (c >= 32 && c <= 126)
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

static void handleCharCase(char c) {
    printChar(c);
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void handleIntCase(int i) {
    if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else
        printChar(static_cast<char>(i));
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

static void handleFloatCase(float f) {
    if (std::isnan(f) || std::isinf(f))
        std::cout << "char: impossible" << std::endl;
    else {
        double integral;
        double fractional = std::modf(f, &integral);
        if (fractional != 0.0 || integral < std::numeric_limits<char>::min() || integral > std::numeric_limits<char>::max())
            std::cout << "char: impossible" << std::endl;
        else
            printChar(static_cast<char>(integral));
    }

    if (std::isnan(f) || std::isinf(f))
        std::cout << "int: impossible" << std::endl;
    else {
        double integral;
        double fractional = std::modf(f, &integral);
        if (fractional != 0.0 || integral < std::numeric_limits<int>::min() || integral > std::numeric_limits<int>::max())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(integral) << std::endl;
    }

    if (std::isnan(f))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(f))
        std::cout << "float: " << (f < 0 ? "-inff" : "inff") << std::endl;
    else {
        double integral;
        std::modf(f, &integral);
        std::cout << "float: " << f << (integral == f ? ".0f" : "f") << std::endl;
    }

    double d = static_cast<double>(f);
    if (std::isnan(d))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(d))
        std::cout << "double: " << (d < 0 ? "-inf" : "inf") << std::endl;
    else {
        double integral;
        std::modf(d, &integral);
        std::cout << "double: " << d << (integral == d ? ".0" : "") << std::endl;
    }
}

static void handleDoubleCase(double d) {
    if (std::isnan(d) || std::isinf(d))
        std::cout << "char: impossible" << std::endl;
    else {
        double integral;
        double fractional = std::modf(d, &integral);
        if (fractional != 0.0 || integral < std::numeric_limits<char>::min() || integral > std::numeric_limits<char>::max())
            std::cout << "char: impossible" << std::endl;
        else
            printChar(static_cast<char>(integral));
    }

    if (std::isnan(d) || std::isinf(d))
        std::cout << "int: impossible" << std::endl;
    else {
        double integral;
        double fractional = std::modf(d, &integral);
        if (fractional != 0.0 || integral < std::numeric_limits<int>::min() || integral > std::numeric_limits<int>::max())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(integral) << std::endl;
    }

    float f = static_cast<float>(d);
    if (std::isnan(f))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(f))
        std::cout << "float: " << (f < 0 ? "-inff" : "inff") << std::endl;
    else {
        double integral;
        std::modf(d, &integral);
        std::cout << "float: " << f << (integral == d ? ".0f" : "f") << std::endl;
    }

    if (std::isnan(d))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(d))
        std::cout << "double: " << (d < 0 ? "-inf" : "inf") << std::endl;
    else {
        double integral;
        std::modf(d, &integral);
        std::cout << "double: " << d << (integral == d ? ".0" : "") << std::endl;
    }
}


void ScalarConverter::convert(const std::string &input) {
    if (isFloat(input)) {
        handleFloatCase(parseFloat(input));
    } else if (isDouble(input)) {
        handleDoubleCase(parseDouble(input));
    } else if (isInt(input)) {
        handleIntCase(parseInt(input));
    } else if (isChar(input)) {
        handleCharCase(parseChar(input));
    } else {
        std::cout << "Invalid input" << std::endl;
    }
}