/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:14:34 by anferre           #+#    #+#             */
/*   Updated: 2024/09/24 10:47:24 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	Zombie* horde = nullptr;
	
	try {
		horde = new Zombie[N];
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Allocation failed: " << e.what() << std::endl;
		return nullptr;
	}
	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
	}
	return horde;
}
