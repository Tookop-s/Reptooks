/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:14:34 by anferre           #+#    #+#             */
/*   Updated: 2024/09/26 17:52:52 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	Zombie* horde = NULL;
	
	try {
		horde = new Zombie[N];
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Allocation failed: " << e.what() << std::endl;
		return NULL;
	}
	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
	}
	return horde;
}
