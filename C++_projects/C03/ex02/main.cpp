/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:02:14 by anferre           #+#    #+#             */
/*   Updated: 2024/10/09 16:10:23 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

void testDefaultConstructor( void ) {
	std::cout << std::endl << _BOLD << _BLUE << "default constructor test :" << _END << std::endl << std::endl;
	
	{
		FragTrap frag;
	}
	std::cout << std::endl;
	{
		ScavTrap scav;
	}
}

void testStringConstructor( void ) {
	std::cout << _BOLD << _BLUE << "string constructor test :" << _END << std::endl << std::endl;
	try
	{
		{
		// FragTrap frag(NULL);
		FragTrap frag1("Fragtrap");	
		}
		std::cout << std::endl;
		{
		// ScavTrap scav(NULL);
		ScavTrap scav1("Scavtrap");
		}
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
		{
		// FragTrap frag(NULL);
		FragTrap frag1("Fragtrap");
		FragTrap frag2(frag1);
		}
		std::cout << std::endl;
		{
		// ScavTrap scav(NULL);
		ScavTrap scav1("ScavTrap");
		ScavTrap scav2(scav1);
		}
	}
	catch (std::exception &e)
	{
		std::cerr << _RED << e.what() << _END << std::endl;
	}
}

void testAssignementOperator( void ) {
	std::cout << _BOLD << _BLUE << "assignement operator test :" << _END << std::endl << std::endl;
	try {
		{
		// FragTrap frag0(NULL);
		FragTrap frag("Fragtrap");
		FragTrap frag2("Fragtrap2");
		frag2 = frag;
		}
		std::cout << std::endl;
		{
		// ScavTrap scav0(NULL);
		ScavTrap scav("ScavTrap");
		ScavTrap scav2("ScavTrap2");
		scav2 = scav;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << _RED << e.what() << _END << std::endl;
	}
}

void testAttack( void ) { 
	std::cout << _BOLD << _BLUE << "attack test :" << _END << std::endl << std::endl;
	try {
		{
		// FragTrap frag0(NULL);
		FragTrap frag("Fragtrap");
		frag.attack("target");
		frag.takeDamage(90);
		frag.attack("target");
		frag.beRepaired(20);
		frag.takeDamage(90);
		frag.attack("target");
		}
		std::cout << std::endl;
		{
		// ScavTrap scav0(NULL);
		ScavTrap scav("ScavTrap");
		scav.attack("target");
		scav.takeDamage(90);
		scav.attack("target");
		scav.beRepaired(20);
		scav.takeDamage(90);
		scav.attack("target");
		}
	}
	catch (std::exception &e)
	{
		std::cerr << _RED << e.what() << _END << std::endl;
	}
}

void testGuardGate( void ) {
	std::cout << _BOLD << _BLUE << "guardGate test :" << _END << std::endl << std::endl;
	try {
		// ScavTrap scav0(NULL);
		ScavTrap scav("ScavTrap");
		scav.guardGate();
	}
	catch (std::exception &e)
	{
		std::cerr << _RED << e.what() << _END << std::endl;
	}
}

void testHighFivesGuys( void ) {
	std::cout << _BOLD << _BLUE << "highFivesGuys test :" << _END << std::endl << std::endl;
	try {
		// FragTrap frag0(NULL);
		FragTrap frag("Fragtrap");
		frag.highFivesGuys();
	}
	catch (std::exception &e)
	{
		std::cerr << _RED << e.what() << _END << std::endl;
	}
}

int main( void ) {
	std::cout << _BOLD << _RED << "Starting tests..." << _END << std::endl;
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
	testGuardGate();
	std::cout << std::endl;
	testHighFivesGuys();
	std::cout << std::endl << _BOLD << _GREEN << _BLINK << "All tests completed." << _END << std::endl << std::endl;
	return 0;
}