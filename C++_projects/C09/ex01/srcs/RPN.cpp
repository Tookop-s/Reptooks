/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:56:00 by anferre           #+#    #+#             */
/*   Updated: 2024/12/04 15:03:34 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string const &input)
{
	if (input.empty())
	{
		std::cerr << "Error: empty input" << std::endl;
		return;
	}
	
	try
	{
		std::string::size_type i = 0;
		for (; i < input.length(); i++)
		{
			if (input[i] == ' ')
				continue;
			if (input[i] >= '0' && input[i] <= '9')
				_stack.push(input[i] - '0');
			else if (input[i] == '+')
				add();
			else if (input[i] == '-')
				sub();
			else if (input[i] == '*')
				mul();
			else if (input[i] == '/')
				div();
			else
				throw std::runtime_error("Error");
		}
		std::cout << _stack.top() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

RPN::RPN(RPN const &src)
{
	*this = src;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
	{
		_stack = rhs._stack;
	}
	return *this;
}

RPN::RPN()
{
}

void RPN::add()
{
	if (_stack.size() < 2)
		throw std::runtime_error("Error");
	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();
	_stack.push(b + a);
}

void RPN::sub()
{
	if (_stack.size() < 2)
		throw std::runtime_error("Error");
	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();
	_stack.push(b - a);
}

void RPN::mul()
{
	if (_stack.size() < 2)
		throw std::runtime_error("Error");
	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();
	_stack.push(b * a);
}

void RPN::div()
{
	if (_stack.size() < 2)
		throw std::runtime_error("Error");
	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();
	if (a == 0)
		throw std::runtime_error("Error : Division by zero");
	_stack.push(b / a);
}
