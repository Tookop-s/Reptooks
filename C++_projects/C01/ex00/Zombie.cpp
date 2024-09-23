/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:26:45 by anferre           #+#    #+#             */
/*   Updated: 2024/09/23 15:44:06 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce( void ) {
	if (this->_name == "Foo")
		std::cout  << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	else
		std::cout << "<" << this->_name << ">: BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie( void ) {
	return;
}

Zombie::Zombie( std::string name ) {
	this->_name = name;
	return;
}

Zombie::~Zombie( void ) {
	if (this->_name == "Foo")
		std::cout << "Foo has been destroyed" << std::endl;
	else
		std::cout << "<" << this->_name << "> has been destroyed" << std::endl;
	return;
}