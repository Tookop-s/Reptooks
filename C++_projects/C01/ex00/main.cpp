/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:47:09 by anferre           #+#    #+#             */
/*   Updated: 2024/09/27 11:28:39 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void ) {
	std::cout << "allocated on the heap" << std::endl;
	Zombie *zombie = newZombie("Foo");
	Zombie *zombie2 = newZombie("Bar");
	zombie->announce();
	zombie2->announce();
	std::cout << "allocated on the stack" << std::endl;
	randomChump("Bar");
	randomChump("Foo");
	delete zombie;
	delete zombie2;
	return 0;
}