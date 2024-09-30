/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:30:48 by anferre           #+#    #+#             */
/*   Updated: 2024/09/30 13:33:53 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name ) {
	try
	{
		if (name.empty())
			throw std::invalid_argument("Error: Invalid name");
		Zombie *newZombie = new Zombie(name);
		return newZombie;
	}
	catch (std::exception &e)
	{
		throw;
	}
}