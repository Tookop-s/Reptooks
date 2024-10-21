/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:00:09 by anferre           #+#    #+#             */
/*   Updated: 2024/10/21 15:04:15 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Format.hpp"

AAnimal::AAnimal( void ) {
	if (DEBUG)
		std::cout << _BROWN << "AAnimal default constructor called" << _END << std::endl;
	this->_type = "AAnimal";
}

AAnimal::AAnimal( AAnimal const & src ) {
	if (DEBUG)
		std::cout << _BROWN << "AAnimal copy constructor called" << _END << std::endl;
	this->_type = src._type;
}

AAnimal& AAnimal::operator=( AAnimal const & rhs ) {
	if (this == &rhs)
		return *this;
	if (DEBUG)
		std::cout << _BROWN << "AAnimal assignement operator called" << _END << std::endl;
	this->_type = rhs._type;
	return *this;
}

AAnimal::~AAnimal( void ) {
	if (DEBUG)
		std::cout << _BROWN << "AAnimal default destructor called" << _END << std::endl;
}