#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#define INVALID "\033[1;31mError: No value provided.\033[0;39m"
#define WRONGDAY "\033[1;31mError: The day is invalid.\033[0;39m"
#define WRONGYEAR "\033[1;31mError: The year is invalid.\033[0;39m"
#define WRONGMONTH "\033[1;31mError: The month is invalid.\033[0;39m"
#define CSVFAIL "\033[1;31mError: csv database is corrupted.\033[0;39m"
#define WRONGEXT "\033[1;31mThis program only runs with a csv file.\033[0;39m"
#define WRONGARG "\033[1;31mThis program only runs with 2 arguments.\033[0;39m"
#define NODATA "\033[1;31mWe have backup right? Yes. Where? On the server...\033[0;39m"
#define TOOBIG "\033[1;31mError: Too big number. The allowed range is 0-1000.\033[0;39m"
#define NOTPOS "\033[1;31mError: Not a positive number. The allowed range is 0-1000.\033[0;39m"
#define NODATAONDATE "\033[1;31mError: csv database has no information about this date.\033[0;39m"

class Bitcoin {
   public:
	Bitcoin();
	~Bitcoin();
	Bitcoin(Bitcoin const &cpy);
	Bitcoin &operator=(Bitcoin const &cpy);

	void setMonths();
	// CSV FILE
	float saveRate(std::string line) const;
	std::string saveDate(std::string line) const;
	void validDataBase();
	// INPUT FILE
	void isInputCorrect(char **argv);
	void chechkInputFile(std::string inputFile);
	std::map<std::string, float> getCsvData() const;
	// EXCHANGE AND VALUE CHECKS
	bool validDate(std::string line);
	bool validData(std::string line);
	bool validValue(std::string line);
	bool validMonth(std::string month);
	void exchange(std::string inputFile);
	float getExchangeRate(std::string date);
	bool validDay(std::string day, std::string month);

	// for testing
	void printMap(std::map<std::string, float> dataBaseType);

   private:
	std::map<std::string, float> csvDataBase;  // data and exchange rate
	std::map<int, int> months;				   // months with days
};

#endif