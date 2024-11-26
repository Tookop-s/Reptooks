/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookops <tookops@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:06:57 by tookops           #+#    #+#             */
/*   Updated: 2024/11/26 16:09:22 by tookops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>


class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();
	
	void	processData(const std::string &filename);

private:
	std::map<std::string, double>	_data;

	void	parseLineData(const std::string &line);
	void	parseLine(const std::string &line);
	void 	printDateValue(const std::string &date, const double &value);
	bool	isDateValid(const std::string &date);
	bool	isValueValid(const double &value);
};

#endif