/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:52:39 by anferre           #+#    #+#             */
/*   Updated: 2024/09/27 11:32:04 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void ) {
	return ;
}

Weapon::Weapon( std::string type ): _type(type) {
	return ;
}

Weapon::~Weapon( void ) {
	return ;
}

void Weapon::setType( std::string type ) {
	this->_type = type;
}

const std::string& Weapon::getType(void) const {
	return this->_type;
}