/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:52:26 by anferre           #+#    #+#             */
/*   Updated: 2024/09/27 11:34:38 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name) : _name(name), _weapon(NULL) {
	return ;
}

HumanB::~HumanB( void ) {
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