/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:52:26 by anferre           #+#    #+#             */
/*   Updated: 2024/09/30 13:49:09 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL) {
	if (name.empty())
		throw std::invalid_argument("Name cannot be empty");
	if (DEBUG)
		std::cout << "HumanB constructor called" << std::endl;
	return ;
}

HumanB::~HumanB( void ) {
	if (DEBUG)
		std::cout << "HumanB destructor called" << std::endl;
	return ;
}

void HumanB::setWeapon( Weapon& weapon ) {
	this->_weapon = &weapon;
}

void HumanB::attack( void ) const {
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " has no weapon to attack with" << std::endl;
}