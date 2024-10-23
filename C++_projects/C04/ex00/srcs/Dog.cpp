/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:00:06 by anferre           #+#    #+#             */
/*   Updated: 2024/10/23 11:31:29 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Format.hpp"

Dog::Dog( void ) {
	if (DEBUG)
		std::cout << _GOLD << "Dog default constructor called" << _END << std::endl;
	this->_type = "Dog";
}

Dog::~Dog( void ) {
	if (DEBUG)
		std::cout << _GOLD << "Dog default destructor called" << _END << std::endl;
}

Dog::Dog( Dog const & src ) {
	if (DEBUG)
		std::cout << _GOLD << "Dog copy constructor called" << _END << std::endl;
	this->_type = src._type;
}

Dog& Dog::operator=( Dog const & rhs ) {
	if (this == &rhs)
		return *this;
	if (DEBUG)
		std::cout << _GOLD << "Dog assignement operator called" << _END << std::endl;
	this->_type = rhs._type;
	return *this;
}

void Dog::makeSound( void ) const {
	std::cout << _GOLD << "Waf" << _END << std::endl;
}


std::string Dog::getType( void ) const {
	return this->_type;
}