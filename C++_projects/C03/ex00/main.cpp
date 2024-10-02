/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:43:38 by anferre           #+#    #+#             */
/*   Updated: 2024/10/02 14:57:19 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap claptrap("Claptrap");

	claptrap.takeDamage(5);
	claptrap.beRepaired(10);
	claptrap.takeDamage(16); //check the unsigned int is well handled
	std::cout << std::endl;

	ClapTrap claptrap2("claptrap2");

	claptrap2.beRepaired(10);
	std::cout << "attack 10 times :" << std::endl;
	for(int i = 0; i < 10; i++)
		claptrap2.attack("enemy");
	std::cout << std::endl;
	
	claptrap2.takeDamage(1);
	claptrap2.beRepaired(10);
	std::cout << std::endl;
}