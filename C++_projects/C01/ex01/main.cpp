/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:15:23 by anferre           #+#    #+#             */
/*   Updated: 2024/09/23 16:40:12 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void ) {
	Zombie* horde = zombieHorde(5, "dudu");
	std::cout << "Horde created" << std::endl;
	for (int i = 0; i < 5; i++) {
		horde[i].announce();
	}	
	delete [] horde;
	return 0;
}