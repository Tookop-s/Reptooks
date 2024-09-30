/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:15:23 by anferre           #+#    #+#             */
/*   Updated: 2024/09/30 13:32:11 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void ) {
	int N = -2;

	try
	{
		Zombie *horde = zombieHorde(N, "dudu");
		if (!horde)
			return 1;
		std::cout << "Horde created" << std::endl;
		for (int i = 0; i < N; i++)
		{
			horde[i].announce();
		}
		delete[] horde;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught in main : " << e.what() << std::endl;
		return 1;
	}
	return 0;
}