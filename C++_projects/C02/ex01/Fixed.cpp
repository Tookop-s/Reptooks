/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:33:32 by anferre           #+#    #+#             */
/*   Updated: 2024/09/25 17:58:25 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed( Fixed const & src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
	return;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setrawBits member function called" << std::endl;
	this->_value = raw;
}

Fixed& Fixed::operator=( Fixed const & src ) {
	std::cout << "Copy assignement operator called" << std::endl;
	this->_value = src.getRawBits();
	return *this;
}

Fixed::Fixed( int const value ) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << this->_bits;
}

// 1 << 8 = 256 = 2^8 scaling factor to move the decimal point
Fixed::Fixed( float const value ) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << this->_bits));
}

float Fixed::toFloat( void ) const {
	return (float)this->_value / (1 << this->_bits);
}

int Fixed::toInt( void ) const {
	return this->_value >> this->_bits;
}

std::ostream& operator<<( std::ostream& o, Fixed const& src) {
	o << src.toFloat();
	return o;
}
