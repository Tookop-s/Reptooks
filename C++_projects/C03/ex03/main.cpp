/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:02:14 by anferre           #+#    #+#             */
/*   Updated: 2024/10/09 18:04:20 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

void testDefaultConstructor( void ) {
	std::cout << std::endl << _BOLD << _BLUE << "default constructor test :" << _END << std::endl << std::endl;
	
	DiamondTrap diamond;
}

void testStringConstructor( void ) {
	std::cout << _BOLD << _BLUE << "string constructor test :" << _END << std::endl << std::endl;
	try
	{
		// DiamondTrap diamond0(NULL);
		DiamondTrap diamond("DiamondTrap");
	}
	catch (std::exception &e)
	{
		std::cerr << _RED  << e.what() << _END << std::endl;
	}
}

void testCopyConstructor( void ) {
	std::cout << _BOLD << _BLUE << "copy constructor test :" << _END << std::endl << std::endl;
	try
	{
		DiamondTrap diamond("DiamondTrap");
		DiamondTrap diamond2(diamond);
	}
	catch (std::exception &e)
	{
		std::cerr << _RED << e.what() << _END << std::endl;
	}
}

void testAssignementOperator( void ) {
	std::cout << _BOLD << _BLUE << "assignement operator test :" << _END << std::endl << std::endl;
	try {
		DiamondTrap diamond("DiamondTrap");
		DiamondTrap diamond2("DiamondTrap2");
		diamond2 = diamond;
	}
	catch (std::exception &e)
	{
		std::cerr << _RED << e.what() << _END << std::endl;
	}
}

void testAttack( void ) { 
	std::cout << _BOLD << _BLUE << "attack test :" << _END << std::endl << std::endl;
	try {
		DiamondTrap diamond("DiamondTrap");
		diamond.attack("enemy");
		diamond.takeDamage(10);
		diamond.attack("enemy");
		diamond.beRepaired(10);
		diamond.attack("enemy");
		diamond.takeDamage(1000);
		diamond.attack("enemy");
	}
	catch (std::exception &e)
	{
		std::cerr << _RED << e.what() << _END << std::endl;
	}
}

void testWhoAmI( void ) {
	std::cout << _BOLD << _BLUE << "whoAmI test :" << _END << std::endl << std::endl;
	try {
		DiamondTrap diamond("DiamondTrap");
		diamond.whoAmI();
		diamond.guardGate();
		diamond.highFivesGuys();
		DiamondTrap diamond2;
		diamond2.whoAmI();
		diamond.guardGate();
		diamond.highFivesGuys();
	}
	catch (std::exception &e)
	{
		std::cerr << _RED << e.what() << _END << std::endl;
	}
}


int main( void ) {
	std::cout << _BOLD << _RED << "Starting tests..." << _END << std::endl << std::endl;
	testDefaultConstructor();
	std::cout << std::endl;
	testStringConstructor();
	std::cout << std::endl;
	testCopyConstructor();
	std::cout << std::endl;
	testAssignementOperator();
	std::cout << std::endl;
	testAttack();
	std::cout << std::endl;
	testWhoAmI();
	std::cout << std::endl << _BOLD << _GREEN << _BLINK << "All tests completed." << _END << std::endl << std::endl;
	return 0;
}