/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:30:48 by anferre           #+#    #+#             */
/*   Updated: 2024/09/25 12:04:23 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name ) {
	try
	{
		Zombie *newZombie = new Zombie(name);
		return newZombie;
	}
	catch (std::bad_alloc &e)
	{
		std::cerr << "Allocation failed: " << e.what() << std::endl;
		return nullptr;
	}
}