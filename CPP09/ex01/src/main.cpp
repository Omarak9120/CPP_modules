#include "../includes/RPN.hpp"

int main(int argc, char **argv) {
	try {
		if (argc < 2) throw std::logic_error(NOARG);
		RPN reversePolishNotation;
		reversePolishNotation.getArithmeticExpression(argv[1]);
		reversePolishNotation.executeArithmeticExpression();
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	return 0;
}