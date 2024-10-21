/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:00:09 by anferre           #+#    #+#             */
/*   Updated: 2024/10/21 12:59:18 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Format.hpp"

Animal::Animal( void ) {
	if (DEBUG)
		std::cout << _BROWN << "Animal default constructor called" << _END << std::endl;
	this->_type = "Animal";
}

Animal::~Animal( void ) {
	if (DEBUG)
		std::cout << _BROWN << "Animal default destructor called" << _END << std::endl;
}

Animal::Animal( Animal const & src ) {
	if (DEBUG)
		std::cout << _BROWN << "Animal copy constructor called" << _END << std::endl;
	this->_type = src._type;
}

Animal& Animal::operator=( Animal const & rhs ) {
	if (this == &rhs)
		return *this;
	if (DEBUG)
		std::cout << _BROWN << "Animal assignement operator called" << _END << std::endl;
	this->_type = rhs._type;
	return *this;
}

std::string Animal::getType( void ) const {
	return this->_type;
}

void Animal::makeSound( void ) const {
	std::cout << _BROWN << "Animal makes a sound" << _END << std::endl;
}
