/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:26:45 by anferre           #+#    #+#             */
/*   Updated: 2024/09/30 13:23:54 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce( void ) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie( void ): _name("default") {
	if (DEBUG)
		std::cout << "Zombie created named : default" << std::endl;
	return;
}

Zombie::Zombie( std::string name ): _name(name) {
	if (DEBUG)
		std::cout << "Zombie created named : " << name << std::endl;
	return;
}

Zombie::~Zombie( void ) {
		std::cout  << this->_name << ": has been destroyed" << std::endl;
	return;
}