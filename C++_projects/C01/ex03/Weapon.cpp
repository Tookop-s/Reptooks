/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:52:39 by anferre           #+#    #+#             */
/*   Updated: 2024/09/30 13:53:17 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void ) {
	if (DEBUG)
		std::cout << "default Weapon constructor called" << std::endl;
	return ;
}

Weapon::Weapon(const std::string& type ): _type(type) {
	if (type.empty())
		throw std::invalid_argument("Type cannot be empty");
	if (DEBUG)
		std::cout << "Weapon constructor called" << std::endl;
	return ;
}

Weapon::~Weapon( void ) {
	if (DEBUG)
		std::cout << "Weapon destructor called" << std::endl;
	return ;
}

void Weapon::setType( std::string type ) {
	this->_type = type;
}

const std::string& Weapon::getType(void) const {
	return this->_type;
}