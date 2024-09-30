/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:47:09 by anferre           #+#    #+#             */
/*   Updated: 2024/09/30 14:05:49 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void ) {
	Zombie *zombie = NULL;
	Zombie *zombie2 = NULL;

	try
	{
		std::cout << "allocated on the heap " << std::endl;
		zombie = newZombie("dudu");
		zombie2 = newZombie("didi");
		if (!zombie || !zombie2)
			throw std::runtime_error("Error: Memory allocation failed");
		zombie->announce();
		zombie2->announce();
		std::cout << "allocated on the stack " << std::endl;
		randomChump("dodo");
		randomChump("dede");
		delete zombie;
		delete zombie2;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught in main : " << e.what() << std::endl;
		if (zombie)
			delete zombie;
		if (zombie2)
			delete zombie2;
		return 1;
	}
	return 0;
}