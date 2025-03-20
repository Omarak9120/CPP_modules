#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
public:
    static int evaluate(const std::string &expression);
};

#endif
