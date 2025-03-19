/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:45:32 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/19 21:45:51 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <limits>
#include <cstdlib>
#include <sstream>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

float stringToFloat(const std::string& str)
{
	std::stringstream ss(str);
	float num;
	ss >> num;
	if (ss.fail())
	{
		throw std::runtime_error("Invalid float conversion: " + str);
	}
	return num;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file)
	{
		std::cerr << "Error: could not open file " << filename << std::endl;
		exit(1);
	}
	
	std::string line, date;
	float price;
	getline(file, line); 

	while (getline(file, line))
	{
		std::stringstream ss(line);
		getline(ss, date, ',');
		ss >> price;
		btcPrices[date] = price;
	}
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') return false;
	int y, m, d;
	char dash1, dash2;
	std::stringstream ss(date);
	if (!(ss >> y >> dash1 >> m >> dash2 >> d)) return false;
	if (dash1 != '-' || dash2 != '-') return false;
	if (m < 1 || m > 12 || d < 1 || d > 31) return false;
	return true;
}

bool BitcoinExchange::isValidValue(const std::string& value)
{
	try
	{
		float num = stringToFloat(value);
		if (num < 0 || num > 1000) return false;
	}
	catch (...)
	{
		return false;
	}
	return true;
}

float BitcoinExchange::getClosestPrice(const std::string& date)
{
	std::map<std::string, float>::iterator it = btcPrices.lower_bound(date);
	if (it == btcPrices.begin()) return it->second;
	if (it == btcPrices.end() || it->first != date) --it;
	return it->second;
}

void BitcoinExchange::processInput(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file)
	{
		std::cerr << "Error: could not open file " << filename << std::endl;
		return;
	}
	
	std::string line, date, value;
	getline(file, line);

	while (getline(file, line))
	{
		std::stringstream ss(line);
		getline(ss, date, '|');
		getline(ss, value);
		
		date = date.substr(0, date.find_last_not_of(" ") + 1);
		value = value.substr(value.find_first_not_of(" "));

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		if (!isValidValue(value))
		{
			std::cerr << "Error: invalid value " << value << std::endl;
			continue;
		}

		float btcAmount = stringToFloat(value);
		float price = getClosestPrice(date);
		std::cout << date << " => " << btcAmount << " = " << (btcAmount * price) << std::endl;
	}
}
