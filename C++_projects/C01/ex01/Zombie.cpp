/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:13:21 by anferre           #+#    #+#             */
/*   Updated: 2024/09/23 16:35:46 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce( void ) {
	std::cout << "<" << this->_name << ">: BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->_name = name;
	return;
}

Zombie::Zombie( void ) : _name("default") {
	return;
}

Zombie::Zombie( std::string name ) : _name(name) {
	Zombie::announce();
	return;
}

Zombie::~Zombie( void ) {
	std::cout << "<" << this->_name << "> has been destroyed" << std::endl;
	return;
}