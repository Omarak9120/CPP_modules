#include "../includes/RPN.hpp"

/*__________________________________ CONSTRUCTORS / DESTRUCTOR __________________________________*/

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(RPN const &cpy) { *this = cpy; }

/*_____________________________________ OPERATOR OVERLOADS ______________________________________*/

RPN &RPN::operator=(const RPN &cpy) {
	if (this != &cpy) arithmeticExpression = cpy.arithmeticExpression;
	return *this;
}

/*__________________________________________ FUNCTIONS __________________________________________*/

void RPN::getArithmeticExpression(std::string input) {
	if (input.length() == 0) throw std::logic_error(EMPTYARG);
	if (input.length() < 3) throw std::logic_error(TOOSHORT);
	if (containsOnlyValidChars(input) == false) throw std::logic_error(INVALIDCHAR);
	arithmeticExpression = input;
	std::cout << std::endl << AREXP << arithmeticExpression << std::endl;
}

bool RPN::containsOnlyValidChars(std::string input) {
	int numbers = 0, operators = 0;
	for (size_t i = 0; i < input.length(); i++) {
		if (std::string(VALID_ELEMENTS).find(input[i]) == std::string::npos) return false;
		if (i > 0 && input[i] == ' ' && input[i - 1] == ' ') throw std::logic_error(TOOMANYSPACE);
		if (i > 0 && input[i] != ' ' && input[i - 1] != ' ') throw std::logic_error(LESSSPACE);
		if (std::string(NUMBERS).find(input[i]) != std::string::npos) numbers++;
		if (std::string(OPERATORS).find(input[i]) != std::string::npos) operators++;
	}
	if (operators + 1 != numbers) throw std::logic_error(OPERCOUNT);
	return true;
}

void RPN::executeArithmeticExpression() {
	std::cout << START << std::endl;
	for (size_t i = 0; i < arithmeticExpression.length(); i++) {
		if (std::isdigit(arithmeticExpression[i])) {
			stackIt.push(arithmeticExpression[i] - '0');
		} else if (isOperator(arithmeticExpression[i]) == true) {
			stackIt.push(handleOperator(arithmeticExpression[i]));
			std::cout << stackIt.top() << SPACE_ << std::endl;
		}
	}
	std::cout << RESULT << stackIt.top() << std::endl;
}

bool RPN::isOperator(char character) {
	if (std::string(OPERATORS).find(character) == std::string::npos) return false;
	return true;
}

int RPN::handleOperator(char operatr) {
	if (stackIt.size() < 2) throw std::logic_error(INVALIDORDER);
	int num2 = stackIt.top();
	stackIt.pop();
	int num1 = stackIt.top();
	stackIt.pop();
	if (operatr == '+') return std::cout << SPACE << num1 << " + " << num2 << " = ", num1 + num2;
	if (operatr == '-') return std::cout << SPACE << num1 << " - " << num2 << " = ", num1 - num2;
	if (operatr == '*') return std::cout << SPACE << num1 << " * " << num2 << " = ", num1 * num2;
	if (operatr == '/') return std::cout << SPACE << num1 << " / " << num2 << " = ", num1 / num2;
	return -42;
}
