/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:00:11 by anferre           #+#    #+#             */
/*   Updated: 2024/10/21 12:59:41 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Format.hpp"

Cat::Cat( void ) {
	if (DEBUG)
		std::cout << _ORANGE << "Cat default constructor called" << _END << std::endl;
	this->_type = "Cat";
}

Cat::~Cat( void ) {
	if (DEBUG)
		std::cout << _ORANGE << "Cat default destructor called" << _END << std::endl;
}

Cat::Cat( Cat const & src ) {
	if (DEBUG)
		std::cout << _ORANGE << "Cat copy constructor called" << _END << std::endl;
	this->_type = src._type;
}

Cat& Cat::operator=( Cat const & rhs ) {
	if (this == &rhs)
		return *this;
	if (DEBUG)
		std::cout << _ORANGE << "Cat assignement operator called" << _END << std::endl;
	this->_type = rhs._type;
	return *this;
}

void Cat::makeSound( void ) const {
	std::cout << _ORANGE << "Cat meow" << _END << std::endl;
}

std::string Cat::getType( void ) const {
	return this->_type;
}
