/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:52:29 by anferre           #+#    #+#             */
/*   Updated: 2024/09/23 17:18:23 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA ( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon) {
	return ;
}

HumanA::~HumanA( void ) {
	return ;
}

void HumanA::attack( void ) const { 
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}