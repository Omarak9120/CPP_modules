#ifndef RND_HPP
#define RND_HPP

#include <cctype>
#include <cstddef>
#include <exception>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

#define RED "\033[1;31m"
#define END "\033[1;39m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"

#define OPERATORS "-+*/"
#define NUMBERS "0123456789"
#define VALID_ELEMENTS "0123456789 -+*/"

#define SPACE "\033[1;31m           | \033[1;39m"
#define START "\033[1;31m           _____________\033[1;39m"
#define SPACE_ "\033[1;31m |\n           |-----------|\033[1;39m"
#define RESULT "              \033[1;4;32mResult:\033[1;0;39m\n                 "
#define AREXP "\033[1;4;33mThe arithmetic expression is:\033[1;0;39m "
#define EMPTYARG "\033[1;31mEmpty argument is not a valid input.\033[1;39m"
#define TOOMANYSPACE "\033[1;31mConsecutive spaces in the input.\033[1;39m"
#define LESSSPACE "\033[1;31mMissing spaces in the input.\033[1;39m"
#define NOARG "\033[1;31mThis program needs at least one argument.\033[1;39m"
#define INVALIDORDER "\033[1;31mInvalid order in the expression.\033[1;0;39m"
#define OPERCOUNT "\033[1;31mBad operator count in the expression.\033[1;0;39m"
#define INVALIDCHAR "\033[1;31mThe input contains invalid characters.\033[1;39m"
#define TOOSHORT "\033[1;31mInput has to contain at least 2 number and one operation.\033[1;39m"

class RPN {
   public:
	RPN();
	~RPN();
	RPN(RPN const &cpy);
	RPN &operator=(RPN const &cpy);

	bool isOperator(char character);
	int handleOperator(char operatr);
	void executeArithmeticExpression();
	bool containsOnlyValidChars(std::string input);
	void getArithmeticExpression(std::string input);

   private:
	std::string arithmeticExpression;
	std::stack<int> stackIt;
};

#endif