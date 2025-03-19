#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

class BitcoinExchange
{
private:
    std::map<std::string, float> btcPrices;

public:
    BitcoinExchange();
    ~BitcoinExchange();
    
    void loadDatabase(const std::string& filename);
    void processInput(const std::string& filename);
    float getClosestPrice(const std::string& date);
    bool isValidDate(const std::string& date);
    bool isValidValue(const std::string& value);
};

#endif
