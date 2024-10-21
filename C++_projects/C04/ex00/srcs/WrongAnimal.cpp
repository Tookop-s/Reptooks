/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:30:46 by anferre           #+#    #+#             */
/*   Updated: 2024/10/21 13:00:01 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "Format.hpp"

WrongAnimal::WrongAnimal( void ) {
	if (DEBUG)
		std::cout << _BORDEAUX << "WrongAnimal default constructor called" << _END << std::endl;
	this->_type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal( void ) {
	if (DEBUG)
		std::cout << _BORDEAUX << "WrongAnimal default destructor called" << _END << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & src ) {
	if (DEBUG)
		std::cout << _BORDEAUX << "WrongAnimal copy constructor called" << _END << std::endl;
	this->_type = src._type;
}

WrongAnimal& WrongAnimal::operator=( WrongAnimal const & rhs ) {
	if (this == &rhs)
		return *this;
	if (DEBUG)
		std::cout << _BORDEAUX << "WrongAnimal assignement operator called" << _END << std::endl;
	this->_type = rhs._type;
	return *this;
}

void WrongAnimal::makeSound( void ) const {
	std::cout << _BORDEAUX << "WrongAnimal makes a sound" << _END << std::endl;
}

std::string WrongAnimal::getType( void ) const {
	return this->_type;
}
