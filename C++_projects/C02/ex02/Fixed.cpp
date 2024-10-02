/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:33:32 by anferre           #+#    #+#             */
/*   Updated: 2024/10/02 12:01:50 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ) : _value(0) {
	if (DEBUG)
		std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed( Fixed const & src ) {
	if (DEBUG)
		std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed( void ) {
	if (DEBUG)
		std::cout << "Destructor called" << std::endl;
	return;
}

int Fixed::getRawBits( void ) const {
	if (DEBUG)
		std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits( int const raw ) {
	if (DEBUG)
		std::cout << "setrawBits member function called" << std::endl;
	this->_value = raw;
}

Fixed::Fixed( int const value ) {
	if (DEBUG)
		std::cout << "Int constructor called" << std::endl;
	this->_value = value << this->_bits;
}

// 1 << 8 = 256 = 2^8 scaling factor to move the decimal point
Fixed::Fixed( float const value ) {
	if (DEBUG)
		std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << this->_bits));
}

float Fixed::toFloat( void ) const {
	return (float)this->_value / (1 << this->_bits);
}

int Fixed::toInt( void ) const {
	return this->_value >> this->_bits;
}

Fixed& Fixed::operator=( Fixed const & rhs ) {
	if (DEBUG)
		std::cout << "Copy assignement operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
}

std::ostream& operator<<( std::ostream& o, Fixed const& rhs) {
	o << rhs.toFloat();
	return o;
}

bool Fixed::operator>( Fixed const & rhs ) const {
	return this->_value > rhs.getRawBits();
}

bool Fixed::operator<( Fixed const & rhs ) const {
	return this->_value < rhs.getRawBits();
}

bool Fixed::operator>=( Fixed const & rhs ) const {
	return this->_value >= rhs.getRawBits();
}

bool Fixed::operator<=( Fixed const & rhs ) const {
	return this->_value <= rhs.getRawBits();
}

bool Fixed::operator==( Fixed const & rhs ) const {
	return this->_value == rhs.getRawBits();
}

bool Fixed::operator!=( Fixed const & rhs ) const {
	return this->_value != rhs.getRawBits();
}

Fixed Fixed::operator+(Fixed const & rhs ) const {
	Fixed result;
	result._value = this->_value + rhs.getRawBits();
	return (result);
}

Fixed Fixed::operator-(Fixed const & rhs ) const {
	Fixed result;
	result._value = this->_value - rhs.getRawBits();
	return (result);
}

//multiplying two fixed point numbers results in a value scaled by the square of the og factor (2^16),
// so we bit shift right by the number of bits in the fixed point number
Fixed Fixed::operator*(Fixed const & rhs ) const {
	Fixed result;
	result._value = (this->_value * rhs.getRawBits()) >> this->_bits;
	return (result);
}

//dividing two fixed point numbers can result in an underflow,
//so the numerator is shifted left by the number of bits in the fixed point number to preserve the scale

Fixed Fixed::operator/(Fixed const & rhs ) const {
	Fixed result;
	result._value = (this->_value << this->_bits) / rhs.getRawBits();
	return (result);
}

Fixed& Fixed::operator++( void ) {
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++( int ) { 
	Fixed temp = *this;
	this->_value++;
	return (temp);
}

Fixed& Fixed::operator--( void ) {
	this->_value--;
	return (*this);
}

Fixed Fixed::operator--( int ) { 
	Fixed temp = *this;
	this->_value--;
	return (temp);
}

//condition ? expression_if_true : expression_if_false;
// the caller can modify the returned value
Fixed& Fixed::max( Fixed & a, Fixed & b ) {
	return (a > b ? a : b);
}

// the caller cannot modify the returned value
Fixed const & Fixed::max( Fixed const & a, Fixed const & b ) {
	return (a > b ? a : b);
}

Fixed& Fixed::min( Fixed & a, Fixed & b ) {
	return (a < b ? a : b);
}

Fixed const & Fixed::min( Fixed const & a, Fixed const & b ) {
	return (a < b ? a : b);
}

//https://www.notion.so/C-1049a7fe5c91804fa04fe409dd69a3cb?pvs=4#10d9a7fe5c918055a90cd3f337fbd408
