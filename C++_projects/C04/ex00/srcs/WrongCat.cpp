/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:34:45 by anferre           #+#    #+#             */
/*   Updated: 2024/10/18 15:03:56 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Format.hpp"

WrongCat::WrongCat( void ) {
	if (DEBUG)
		std::cout << _KAKI << "WrongCat default constructor called" << _END << std::endl;
	this->_type = "WrongCat";
}

WrongCat::~WrongCat( void ) {
	if (DEBUG)
		std::cout << _KAKI << "WrongCat default destructor called" << _END << std::endl;
}

WrongCat::WrongCat( WrongCat const & src ) {
	if (DEBUG)
		std::cout << _KAKI << "WrongCat copy constructor called" << _END << std::endl;
	*this = src;
}

WrongCat& WrongCat::operator=( WrongCat const & rhs ) {
	if (this == &rhs)
		return *this;
	if (DEBUG)
		std::cout << _KAKI << "WrongCat assignement operator called" << _END << std::endl;
	this->_type = rhs._type;
	return *this;
}

void WrongCat::makeSound( void ) const {
	std::cout << _KAKI << "WrongCat meow" << _END << std::endl;
}

std::string WrongCat::getType( void ) const {
	return this->_type;
}
