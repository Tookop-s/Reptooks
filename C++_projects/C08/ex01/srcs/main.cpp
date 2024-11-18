/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookops <tookops@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:54:06 by tookops           #+#    #+#             */
/*   Updated: 2024/11/18 16:49:52 by tookops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <cstdlib>
#include <list>

int main()
{
	std::cout << _GOLD << "Basic Test:" << _END << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.printNumbers();
		std::cout << "Shortest Span: " << _BLUE << sp.shortestSpan() << _END << std::endl;
		std::cout << "Longest Span: " << _BLUE << sp.longestSpan() << _END << std::endl;
		std::cout << "-------------------------------" << std::endl;

		std::cout << _GOLD << "Test with 20000 numbers:" << _END << std::endl;
		Span bigSpan(20000);
		std::srand(std::time(0));
		for (int i = 0; i < 20000; i++)
			bigSpan.addNumber(std::rand() % 200000);
		bigSpan.printNumbers();
		std::cout << "Shortest Span: " << _BLUE << bigSpan.shortestSpan() << _END << std::endl;
		std::cout << "Longest Span: " << _BLUE << bigSpan.longestSpan() << _END << std::endl;
		std::cout << "-------------------------------" << std::endl;

		std::cout << _GOLD << "testing addRange:" << _END << std::endl;
		std::vector<int> range;
		for (int i = 0; i < 100; i++)
			range.push_back(i * 10);
		Span rangeSpan(100);
		rangeSpan.addRange(range.begin(), range.end());
		rangeSpan.printNumbers();
		std::cout << "Shortest Span: " << _BLUE << rangeSpan.shortestSpan() << _END << std::endl;
		std::cout << "Longest Span: " << _BLUE << rangeSpan.longestSpan() << _END << std::endl;
		std::cout << "-------------------------------" << std::endl;

		std::cout << _GOLD << "testing exceptions:" << _END << std::endl;
		try
		{
			rangeSpan.addRange(range.begin(), range.end());
		} catch (std::exception &e)
		{
			std::cout << _RED << "Caught exception: " << e.what() << _END << std::endl;
		}
		try
		{
			rangeSpan.addNumber(42);
		} catch (std::exception &e)
		{
			std::cout << _RED << "Caught exception: " << e.what() << _END << std::endl;
		}
		try
		{
			Span emptySpan(5);
			emptySpan.shortestSpan();
		} catch (std::exception &e)
		{
			std::cout << _RED << "Caught exception: " << e.what() << _END << std::endl;
		}
		std::cout << "-------------------------------" << std::endl;

		std::cout << _GOLD << "testing with a list" << _END << std::endl;
		std::list<int> listRange;
		for (int i = 0; i < 5; i++)
			listRange.push_back(i * 5);
		Span listSpan(10);
		listSpan.addRange(listRange.begin(), listRange.end());
		listSpan.printNumbers();
		std::cout << "Shortest Span: " << _BLUE << listSpan.shortestSpan() << _END << std::endl;
		std::cout << "Longest Span: " << _BLUE << listSpan.longestSpan() << _END << std::endl;
		std::cout << "-------------------------------" << std::endl;
		
	return 0;
}
