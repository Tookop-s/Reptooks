/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:14:34 by anferre           #+#    #+#             */
/*   Updated: 2024/09/30 13:32:34 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	Zombie* horde = NULL;

	if (N <= 0)
	{
		std::cerr << "Error: Invalid number of zombies" << std::endl;
		return NULL;
	}
	try
	{
		if (name.empty())
			throw std::invalid_argument("Error: Invalid name");
		horde = new Zombie[N];
		for (int i = 0; i < N; i++)
		{
			horde[i].setName(name);
		}
	}
	catch (std::exception &e)
	{
		throw;
	}
	return horde;
}
