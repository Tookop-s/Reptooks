/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:52:29 by anferre           #+#    #+#             */
/*   Updated: 2024/09/30 13:49:02 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA (const std::string& name, Weapon& weapon ) : _name(name), _weapon(weapon) {
	if (name.empty())
		throw std::invalid_argument("Name cannot be empty");
	if (DEBUG)
		std::cout << "HumanA constructor called" << std::endl;
	return ;
}

HumanA::~HumanA( void ) {
	if (DEBUG)
		std::cout << "HumanA destructor called" << std::endl;
	return ;
}

void HumanA::attack( void ) const { 
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}