/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:21:25 by anferre           #+#    #+#             */
/*   Updated: 2024/10/01 12:24:26 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


Point::Point( void ) : x(0), y(0) {
	if (DEBUG)
		std::cout << "Default constructor called" << std::endl;
	return;
}

Point::Point( float const x, float const y ) : x(x), y(y) {
	if (DEBUG)
		std::cout << "Parametric constructor called" << std::endl;
	return;
}

Point::Point( Point const & src ) : x(src.x), y(src.y) {
	if (DEBUG)
		std::cout << "Copy constructor called" << std::endl;
	return;
}

Point::~Point( void ) {
	if (DEBUG)
		std::cout << "Destructor called" << std::endl;
	return;
}

Point & Point::operator=( Point const & rhs ) {
	(void)rhs;
	std::cout << "Assignation operator called nothing can be done x & y are const" << std::endl;
	return *this;
}

Fixed const Point::getX( void ) const {
	return this->x;
}

Fixed const Point::getY( void ) const {
	return this->y;
}