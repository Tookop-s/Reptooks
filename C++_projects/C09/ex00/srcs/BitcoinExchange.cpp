/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookops <tookops@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:07:17 by tookops           #+#    #+#             */
/*   Updated: 2024/11/26 16:15:42 by tookops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream file("data.csv");
	std::string line;

	if (!file.is_open())
		std::cerr << "Error: could not open file. " << std::endl;
	std::getline(file, line);
	int i = 0;
	while (std::getline(file, line) && i < 5)
	{
		parseLineData(line);
		i++;
	}
	file.close();
}

void BitcoinExchange::parseLineData(const std::string &line)
{
	std::istringstream iss(line);
	std::string date;
	double dValue;
	if (std::getline(iss, date, ',') && iss >> dValue)
	{
		_data[date] = dValue;
		std::cout << "Date: " << date << " => " << dValue << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {};

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_data = other._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {};

void BitcoinExchange::processData(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	std::string line;

	if (!file.is_open())
		throw std::runtime_error("Could not open file");
	std::getline(file, line);
	int i = 0;
	while (std::getline(file, line) && i < 5)
	{
		parseLine(line);
		i++;
	}
	file.close();
}

void BitcoinExchange::parseLine(const std::string &line)
{
	std::istringstream iss(line);
	std::string date;
	double dValue;
	if (std::getline(iss, date, '|') && iss >> dValue)
	{
		if (isDateValid(date) && isValueValid(dValue))
		{
			printDateValue(date, dValue);
		}
	}
}

bool BitcoinExchange::isDateValid(const std::string &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	int year, month, day;
	char dash1, dash2;
	std::istringstream iss(date);
	if (!(iss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-')
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	if (month < 1 || month > 12)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	if (day < 1 || day > 31)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day > daysInMonth[month - 1])
	{
		if (month == 2 && day == 29 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
			return true;
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::isValueValid(const double &value)
{
	if (value < 0)
	{
		std::cerr << "Error: not a positive number" << std::endl;
		return false;
	}
	if (value > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::printDateValue(const std::string &date, const double &value)
{
	std::cout << "Date: " << date << " => " << value << " = ";
	std::map<std::string, double>::iterator it = _data.lower_bound(date);
	if (it != _data.end() && it->first == date)
	{
		std::cout << it->second << std::endl;
	}
	else if (it != _data.begin())
	{
		--it;
		std::cout << it->second << std::endl;
	}
}
