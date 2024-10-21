/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:26:11 by anferre           #+#    #+#             */
/*   Updated: 2024/10/22 00:08:32 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"


void testAMateria()
{
	//test the clone function returns a new instance of the class
	//test the use function for both Ice and Cure
	std::cout << "---------------------" << std::endl;
	std::cout << _BOLD << "Testing AMateria" << _END << std::endl;
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();
	AMateria *tmp;
	ICharacter *bob = new Character("bob");
	tmp = ice->clone();
	std::cout << "should be Ice: " << ice->getType() << std::endl;
	delete tmp;
	tmp = cure->clone();
	std::cout << "should be Cure: " << cure->getType() << std::endl;
	delete tmp;
	ice->use(*bob);
	cure->use(*bob);
	delete bob;
	delete ice;
	delete cure;
}

void testMaterialSource()
{
	//test the learnMateria function max 4 materia
	//test the createMateria function returns a new instance of the class
	std::cout << "---------------------" << std::endl;
	std::cout << _BOLD << "Testing MateriaSource" << _END << std::endl;
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	AMateria *tmp;
	tmp = src->createMateria("ice");
	std::cout << "should be Ice: " << tmp->getType() << std::endl;
	src->learnMateria(tmp);
	tmp = src->createMateria("cure");
	std::cout << "should be Cure: " << tmp->getType() << std::endl;
	src->learnMateria(tmp); //should not be added and print inventory full
	tmp = tmp->clone();
	src->learnMateria(tmp); //should not be added and print inventory full
	delete tmp;
	delete src;
}

void testCharacter()
{
	//test the equip function max 4 materia
	//test the unequip function
	//test the use function
}

int main()
{
	testAMateria();
	testMaterialSource();
	testCharacter();
	std::cout << "---------------------" << std::endl;
	// IMateriaSource *src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// ICharacter *me = new Character("me");
	// AMateria *tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// ICharacter *bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);
	// delete bob;
	// delete me;
	// delete src;
	return 0;
}
