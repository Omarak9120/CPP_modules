#include "../includes/BitcoinExchange.hpp"

/*__________________________________ CONSTRUCTORS / DESTRUCTOR __________________________________*/

Bitcoin::Bitcoin() {
	std::ifstream csvFile("./src/data.csv");
	std::string line;

	setMonths();
	if (csvFile.is_open()) {
		std::getline(csvFile, line);
		if (csvFile.peek() == std::ifstream::traits_type::eof()) throw std::logic_error(CSVFAIL);
		if (line.compare("date,exchange_rate") != 0) throw std::logic_error("invalid file header");
		while (std::getline(csvFile, line))
			csvDataBase.insert(std::make_pair(saveDate(line), saveRate(line)));
		csvFile.close();
		validDataBase();
		return;
	} else
		throw std::logic_error(NODATA);
}

Bitcoin::~Bitcoin() {}
Bitcoin::Bitcoin(Bitcoin const &cpy) { *this = cpy; }

/*_____________________________________ OPERATOR OVERLOADS ______________________________________*/

Bitcoin &Bitcoin::operator=(Bitcoin const &cpy) {
	this->months = cpy.months;
	this->csvDataBase = cpy.csvDataBase;
	return *this;
}

/*__________________________________________ FUNCTIONS __________________________________________*/

void Bitcoin::validDataBase() {
	std::map<std::string, float>::iterator dataIt = csvDataBase.begin();
	for (; dataIt != csvDataBase.end(); dataIt++) {
		if (validDate(dataIt->first) == false) throw std::logic_error(CSVFAIL);
		if (dataIt->second < 0) throw std::logic_error(CSVFAIL);
	}
}

void Bitcoin::isInputCorrect(char **argv) {
	std::string inputFile = argv[1];
	if (inputFile.find(".csv") == std::string::npos || inputFile.length() < 5)
		throw std::logic_error(WRONGEXT);
	chechkInputFile(inputFile);
}

void Bitcoin::chechkInputFile(std::string inputFile) {
	std::string line, date, value;
	std::ifstream input("./" + inputFile);
	if (input.is_open()) {
		std::getline(input, line);
		if (line.compare("date | value") != 0) throw std::logic_error("invalid file header");
		return input.close();
	}
}

void Bitcoin::exchange(std::string inputFile) {
	std::string line;
	std::ifstream input("./" + inputFile);
	if (input.is_open()) {
		int i = 0;
		while (std::getline(input, line))
			if (i++ > 0)
				if (validData(line) == true) {
					std::string date = line.substr(0, line.find(" "));
					float coins = std::atof(line.substr(line.find("|") + 2).c_str());
					float value = getExchangeRate(date);
					if (value != -42)
						std::cout << date << " => " << coins << " = " << std::fixed
								  << std::setprecision(2) << coins * value << std::endl;
				}
		return input.close();
	}
}

bool Bitcoin::validData(std::string line) {
	std::string date = line.substr(0, line.find(" ")), value;
	if (line.find("|") != std::string::npos) value = line.substr(line.find("|") + 2);
	if (line.find("|") == std::string::npos) value = "-42";
	if (validDate(date) == false || validValue(value) == false) return false;
	return true;
}

std::string Bitcoin::saveDate(std::string line) const { return line.substr(0, line.find(",")); }

float Bitcoin::saveRate(std::string line) const {
	if (line.find(",") != std::string::npos && line[line.size() - 1] != ',')
		return std::stof(line.substr(line.find(",") + 1));
	else
		throw std::logic_error(CSVFAIL);
	return -42;
}

bool Bitcoin::validDate(std::string line) {
	std::string date = line.substr(0, line.find(" "));
	std::string year = date.substr(0, date.find("-"));
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);
	std::stringstream yy(year), mm(month), dd(day);
	int int_Y, int_M, int_D;
	yy >> int_Y, mm >> int_M, dd >> int_D;

	if (int_Y < 1970 || int_Y > 2042) return std::cout << WRONGYEAR << std::endl, false;
	if (validMonth(month) == false) return std::cout << WRONGMONTH << std::endl, false;
	if (validDay(day, month) == false) return std::cout << WRONGDAY << std::endl, false;
	return true;
}

bool Bitcoin::validMonth(std::string month) {
	std::map<int, int>::iterator monthIt = months.begin();
	if (month[0] == '0' && month.length() == 2) month = month.substr(1);
	for (; monthIt != months.end(); monthIt++)
		if (monthIt->first == std::atoi(month.c_str())) return true;
	return false;
}

bool Bitcoin::validDay(std::string day, std::string month) {
	std::map<int, int>::iterator monthIt = months.begin();
	if (day[0] == '0' && day.length() == 2) day = day.substr(1);
	if (month[0] == '0' && month.length() == 2) month = month.substr(1);
	for (; monthIt != months.end(); monthIt++)
		if (monthIt->first == std::atoi(month.c_str()) && std::atoi(day.c_str()) > 0 &&
			monthIt->second >= std::atoi(day.c_str()))
			return true;
	return false;
}

bool Bitcoin::validValue(std::string line) {
	std::string strValue = line.substr(line.find("|") + 1);
	std::stringstream numValue(strValue);
	float num;
	numValue >> num;
	if (num == -42) return std::cout << INVALID << std::endl, false;
	if (num < 0) return std::cout << NOTPOS << std::endl, false;
	if (num > 1000) return std::cout << TOOBIG << std::endl, false;
	return true;
}

float Bitcoin::getExchangeRate(std::string date) {
	std::map<std::string, float>::iterator dataBase = csvDataBase.begin();
	for (; dataBase != csvDataBase.end(); dataBase++)
		if (dataBase->first.compare(date) == 0) return dataBase->second;
	dataBase = csvDataBase.lower_bound(date);
	if (dataBase == csvDataBase.begin()) return std::cout << NODATAONDATE << std::endl, -42;
	dataBase--;
	return dataBase->second;
}

/*___________________________________________ SETTERS ___________________________________________*/

void Bitcoin::setMonths() {
	months.insert(std::make_pair(1, 31));
	months.insert(std::make_pair(2, 28));
	months.insert(std::make_pair(3, 31));
	months.insert(std::make_pair(4, 30));
	months.insert(std::make_pair(5, 31));
	months.insert(std::make_pair(6, 30));
	months.insert(std::make_pair(7, 31));
	months.insert(std::make_pair(8, 31));
	months.insert(std::make_pair(9, 30));
	months.insert(std::make_pair(10, 31));
	months.insert(std::make_pair(11, 30));
	months.insert(std::make_pair(12, 31));
}
