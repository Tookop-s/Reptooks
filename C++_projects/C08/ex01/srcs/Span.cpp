/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookops <tookops@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:54:01 by tookops           #+#    #+#             */
/*   Updated: 2024/11/18 16:50:42 by tookops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>

Span::Span(unsigned int N) : _N(N)
{
}

Span::Span(Span const &other) : _N(other._N), _numbers(other._numbers)
{
}

Span::~Span()
{
}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		_N = other._N;
		_numbers = other._numbers;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _N)
		throw length_error();
	_numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
	if (_numbers.size() <= 1)
		throw NoSpan();
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	unsigned int shortest = UINT_MAX;
	for (size_t i = 1; i < sorted.size(); i++)
	{
		unsigned int diff = sorted[i] - sorted[i - 1];
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() <= 1)
		throw NoSpan();
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	return sorted.back() - sorted.front();
}

const char* Span::length_error::what() const throw()
{
	return "Not enough space to add number";
}

const char* Span::NoSpan::what() const throw()
{
	return "Not enough numbers to calculate span";
}

void Span::printNumbers() const
{
	std::cout << "Span contains: ";
	for (size_t i = 0; i < _numbers.size(); i++)
	{
		if (i < 10 || i >= _numbers.size() - 10)
		{
			std::cout << _numbers[i] << " ";
			if (i != _numbers.size() - 1)
				std::cout << ", ";
		}
		else if (i == 10 && _numbers.size() > 20)
			std::cout << "... ";
	}
	std::cout << std::endl;
}
