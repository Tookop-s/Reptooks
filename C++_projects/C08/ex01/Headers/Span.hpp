/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookops <tookops@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:54:03 by tookops           #+#    #+#             */
/*   Updated: 2024/11/18 16:45:56 by tookops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>
#include <Format.hpp>


class Span
{
	private:
		unsigned int _N;
		std::vector<int> _numbers;
		Span();
	
	public:
		Span(unsigned int N);
		Span(Span const &other);
		~Span();
		Span &operator=(Span const &other);

		void addNumber(int number);
		
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		class length_error : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class NoSpan : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		template <typename T>
		void addRange(T begin, T end)
		{
			size_t size = std::distance(begin, end);
			if (_numbers.size() + size > _N)
				throw std::length_error("Not enough space to add range");
			_numbers.insert(_numbers.end(), begin, end);
		}

		void printNumbers() const;
};

#endif