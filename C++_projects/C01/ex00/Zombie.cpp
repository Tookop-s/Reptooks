/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:26:45 by anferre           #+#    #+#             */
/*   Updated: 2024/09/24 15:06:59 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce( void ) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie( void ) {
	return;
}

Zombie::Zombie( std::string name ) {
	this->_name = name;
	return;
}

Zombie::~Zombie( void ) {
	std::cout  << this->_name << " has been destroyed" << std::endl;
	return;
}