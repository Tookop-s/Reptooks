/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:00:06 by anferre           #+#    #+#             */
/*   Updated: 2024/10/18 14:57:24 by anferre          ###   ########.fr       */
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
	*this = src;
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
	std::cout << _GOLD << "Dog bark" << _END << std::endl;
}


std::string Dog::getType( void ) const {
	return this->_type;
}