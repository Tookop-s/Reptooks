/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:43:38 by anferre           #+#    #+#             */
/*   Updated: 2024/10/10 12:30:57 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void testDefaultConstructor( void ) {
	std::cout << std::endl << _BOLD << _BLUE << "default constructor test :" << _END << std::endl << std::endl;
	ClapTrap claptrap;
}

void testStringConstructor( void ){
	std::cout << _BOLD << _BLUE << "string constructor test :" << _END << std::endl << std::endl;
		// ClapTrap claptrap0(NULL);
		ClapTrap claptrap("claptrap");
}

void testCopyConstructor( void ){
	std::cout << _BOLD << _BLUE << "copy constructor test :" << _END << std::endl << std::endl;
	ClapTrap claptrap("claptrap");
	ClapTrap claptrap2(claptrap);
}

void testAssignementOperator( void ){
	std::cout << _BOLD << _BLUE << "assignement operator test :" << _END << std::endl << std::endl;
	ClapTrap claptrap("claptrap");
	ClapTrap claptrap2("claptrap2");
	claptrap2 = claptrap;
}

void testAttack( void ) {
	std::cout << _BOLD << _BLUE << "attack test :" << _END << std::endl << std::endl;
	ClapTrap claptrap("claptrap");

	claptrap.takeDamage(5);
	claptrap.beRepaired(10);
	claptrap.takeDamage(16); // check the unsigned int is well handled
	std::cout << std::endl;

	ClapTrap claptrap2("claptrap2");

	claptrap2.beRepaired(10);
	std::cout << std::endl;

	std::cout << _RED << "attack 10 times :" << _END << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << _RED << "attack " << i + 1 << " : " << _END;
		claptrap2.attack("enemy");
	}
	std::cout << std::endl;

	claptrap2.takeDamage(1);
	claptrap2.beRepaired(10);
	std::cout << std::endl;
}

int main( void ) {
	try {
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
		std::cout << std::endl << _BOLD << _GREEN << "Tests finished." << _END << std::endl;
		return 0;
		
	}
	catch (std::exception &e)
	{
		std::cerr << _RED << "Exception caught in main : " << e.what() << _END << std::endl;
		return 1;
	}
}