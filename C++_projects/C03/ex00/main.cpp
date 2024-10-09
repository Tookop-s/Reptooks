/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:43:38 by anferre           #+#    #+#             */
/*   Updated: 2024/10/09 14:44:31 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void ) {
	try {
		// ClapTrap claptrap0(NULL);
		ClapTrap claptrap("claptrap");

		claptrap.takeDamage(5);
		claptrap.beRepaired(10);
		claptrap.takeDamage(16); //check the unsigned int is well handled
		std::cout << std::endl;

		ClapTrap claptrap2("claptrap2");

		claptrap2.beRepaired(10);
		std::cout << std::endl;
		
		std::cout << _RED << "attack 10 times :" << _END << std::endl;
		for(int i = 0; i < 10; i++)
		{
			std::cout << _RED << "attack " << i + 1 << " : " << _END;
			claptrap2.attack("enemy");
		}
		std::cout << std::endl;
		
		claptrap2.takeDamage(1);
		claptrap2.beRepaired(10);
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << _RED << "Exception caught in main : " << e.what() << _END << std::endl;
		return 1;
	}
}