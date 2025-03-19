#include "../includes/BitcoinExchange.hpp"

int main(int argc, char **argv) {
	try {
		if (argc != 2) throw std::logic_error(WRONGARG);
		Bitcoin coin;
		coin.isInputCorrect(argv);
		coin.exchange(argv[1]);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	return 0;
}

void Bitcoin::printMap(std::map<std::string, float> dataBaseType) {
	std::map<std::string, float> print = dataBaseType;
	int i = 0;
	for (std::map<std::string, float>::iterator printIt = print.begin(); printIt != print.end();
		 printIt++) {
		if (printIt->second == -42)
			std::cout << i++ << ": " << printIt->first.substr(0, 10) << std::endl;
		else
			std::cout << i++ << ": " << printIt->first.substr(0, 10) << " | " << printIt->second
					  << std::endl;
	}
}
