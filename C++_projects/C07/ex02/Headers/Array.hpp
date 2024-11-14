/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookops <tookops@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:55:25 by tookops           #+#    #+#             */
/*   Updated: 2024/11/14 19:08:22 by tookops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include "Format.hpp"

template <typename T>
class Array
{
public:
	Array() : _array(0), _size(0) {};

	Array(unsigned int n) : _array(new T[n]()), _size(n) {};

	Array(const Array &src) : _array(new T[src._size]()), _size(src._size)
	{
		for (unsigned int i = 0; i < src._size; i++)
			_array[i] = src._array[i];
	};
	~Array()
	{
		delete[] _array;
	};

	Array &operator=(const Array &src)
	{
		if (this != &src)
		{
			delete[] _array;
			_size = src._size;
			_array = new T[src._size]();
			for (unsigned int i = 0; i < src._size; i++)
				_array[i] = src._array[i];
		}
		return *this;
	};

	T &operator[](unsigned int i)
	{
		if (i >= _size)
			throw OutOfLimitsException();
		return _array[i];
	};

	unsigned int size() const
	{
		return _size;
	};

	class OutOfLimitsException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Out of limits";
		};
	};

private:
	T *_array;
	unsigned int _size;
};

#endif