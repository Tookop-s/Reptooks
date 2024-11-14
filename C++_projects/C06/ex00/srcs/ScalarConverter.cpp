/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookops <tookops@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:34:48 by anferre           #+#    #+#             */
/*   Updated: 2024/11/14 18:09:02 by tookops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <string>
#include <cmath>

ScalarConverter::~ScalarConverter()
{
}

static bool isValidNumber(const std::string &input)
{
	if (input.empty())
		return false;

	size_t i = 0;
	if (input[i] == '-' || input[i] == '+')
		++i;

	bool hasDigits = false;
	bool hasDecimalPoint = false;

	for (; i < input.size(); ++i)
	{
		if (std::isdigit(input[i]))
		{
			hasDigits = true;
		}
		else if (input[i] == '.' && !hasDecimalPoint)
		{
			hasDecimalPoint = true;
		}
		else if ((input[i] == 'e' || input[i] == 'E') && hasDigits)
		{
			++i;
			if (i < input.size() && (input[i] == '-' || input[i] == '+'))
				++i;
			
			bool exponentHasDigits = false;
			for (; i < input.size(); ++i)
			{
				if (std::isdigit(input[i]))
				{
					exponentHasDigits = true;
				}
				else if (input[i] == 'f' && i == input.size() - 1)
				{
					return hasDigits;
				}
				else
				{
					return false;
				}
			}
			return exponentHasDigits;
		}
		else if (input[i] == 'f' && i == input.size() - 1)
		{
			return hasDigits;
		}
		else
		{
			return false;
		}
	}

	return hasDigits;
}

static int stringToInt(const std::string &input)
{
	std::istringstream iss(input);
	int i;
	iss >> i;
	if (iss.fail() || !iss.eof())
		throw std::invalid_argument("Invalid input");
	return i;
}

static float stringToFloat(const std::string &input)
{
	std::istringstream iss(input);
	float f;
	iss >> f;
	if (iss.fail() || !iss.eof())
		throw std::invalid_argument("Invalid input");
	return f;
}

static double stringToDouble(const std::string &input)
{
	std::string inputCopy;
	if (!input.empty() && input[input.size() - 1] == 'f')
		inputCopy = input.substr(0, input.size() - 1);
	else
		inputCopy = input;
	std::istringstream iss(inputCopy);
	double d;
	iss >> d;
	if (iss.fail() || !iss.eof())
		throw std::invalid_argument("Invalid input");
	return d;
}

static bool convertPseudoLiterals(const std::string &input)
{
	if (input == "nanf" || input == "+inff" || input == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << std::endl;
		std::cout << "double: " << input.substr(0, input.size() - 1) << std::endl;
		return true;
	}
	if (input == "nan" || input == "+inf" || input == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << "f" << std::endl;
		std::cout << "double: " << input << std::endl;
		return true;
	}
	return false;
}

static void convertChar(const std::string &input)
{
	char c = input[0];
	if (std::isprint(static_cast<int>(c)))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

static void convertInt(const std::string &input)
{
	int i = stringToInt(input);
	std::cout << "char: ";
	if (i >= 0 && i <= 127 && std::isprint(i))
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
	else if (i >= 0 && i <= 127)
		std::cout << "non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

static void convertFloat(const std::string &input)
{
	std::string floatstr = input;
	if (floatstr[floatstr.size() - 1] == 'f')
		floatstr.resize(floatstr.size() - 1);
	float f = stringToFloat(floatstr);
	std::cout << "char: ";
	if (f >= 0 && f <= 127 && std::isprint(f))
		std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
	else if (f >= 0 && f <= 127)
		std::cout << "non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int: ";
	if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
		std::cout << static_cast<int>(f) << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}

static void convertDouble(const std::string &input)
{
	double d;
	try
	{
		d = stringToDouble(input);
	}
	catch (...)
	{
		if (input[0] == '-')
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
		else
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		}
		return;
	}
	std::cout << "char: ";
	if (d >= 0 && d <= 127 && std::isprint(d))
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	else if (d >= 0 && d <= 127)
		std::cout << "non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "int: ";
	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
		std::cout << static_cast<int>(d) << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "float: ";
	if (d > std::numeric_limits<float>::max())
		std::cout << "+inff" << std::endl;
	else if (d < -std::numeric_limits<float>::max())
		std::cout << "-inff" << std::endl;
	else 
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::convert(std::string input)
{
	if (convertPseudoLiterals(input))
		return;
	if (input.size() == 1 && !std::isdigit(input[0]))
	{
		convertChar(input);
		return;
	}
	if (!isValidNumber(input))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	try
	{
		convertInt(input);
		return;
	}
	catch (...)
	{
	}
	try
	{
		if (input[input.size() - 1] == 'f')
		{
			convertFloat(input);
			return;	
		}
	}
	catch (...)
	{
	}
	convertDouble(input);
}
