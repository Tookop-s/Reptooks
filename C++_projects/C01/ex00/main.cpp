/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:47:09 by anferre           #+#    #+#             */
/*   Updated: 2024/09/23 15:51:06 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void ) {
	std::cout << "allocated on the heap" << std::endl;
	Zombie *zombie = newZombie("Foo");
	Zombie *zombie2 = newZombie("Bar");
	zombie->announce();
	zombie2->announce();
	delete zombie;
	delete zombie2;
	std::cout << "allocated on the stack" << std::endl;
	randomChump("Bar");
	randomChump("Foo");
	return 0;
}