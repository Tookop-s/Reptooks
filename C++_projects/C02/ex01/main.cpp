/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:27:49 by anferre           #+#    #+#             */
/*   Updated: 2024/10/01 12:11:39 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <climits>

int main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	// Fixed const e(-1024);
	// Fixed const f(0.0f);
	// Fixed const g(INT_MAX);
	// Fixed const h(INT_MIN);
	// Fixed const i(-1);
	// Fixed const j(123456.789f);
	// Fixed const k(-123456.789f);
	// Fixed const l(1.0f);
	a = Fixed(1234.4321f);
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	// std::cout << "e is " << e << std::endl;
	// std::cout << "f is " << f << std::endl;
	// std::cout << "g is " << g << std::endl;
	// std::cout << "h is " << h << std::endl;
	// std::cout << "i is " << i << std::endl;
	// std::cout << "j is " << j << std::endl;
	// std::cout << "k is " << k << std::endl;
	// std::cout << "l is " << l << std::endl;
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	// std::cout << "e is " << e.toInt() << " as integer" << std::endl;
	// std::cout << "f is " << f.toInt() << " as integer" << std::endl;
	// std::cout << "g is " << g.toInt() << " as integer" << std::endl;
	// std::cout << "h is " << h.toInt() << " as integer" << std::endl;
	// std::cout << "i is " << i.toInt() << " as integer" << std::endl;
	// std::cout << "j is " << j.toInt() << " as integer" << std::endl;
	// std::cout << "k is " << k.toInt() << " as integer" << std::endl;
	// std::cout << "l is " << l.toInt() << " as integer" << std::endl;


	//imprecisions due to the rounding of the float to int
	// std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	// std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	// std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	// std::cout << "d is " << d.toFloat() << " as float" << std::endl;
	// std::cout << "e is " << e.toFloat() << " as float" << std::endl;
	// std::cout << "f is " << f.toFloat() << " as float" << std::endl;
	// std::cout << "g is " << g.toFloat() << " as float" << std::endl;
	// std::cout << "h is " << h.toFloat() << " as float" << std::endl;
	// std::cout << "i is " << i.toFloat() << " as float" << std::endl;
	// std::cout << "j is " << j.toFloat() << " as float" << std::endl;
	// std::cout << "k is " << k.toFloat() << " as float" << std::endl;
	// std::cout << "l is " << l.toFloat() << " as float" << std::endl;
	
	return 0;
}