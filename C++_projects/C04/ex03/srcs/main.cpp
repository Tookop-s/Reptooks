/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:26:11 by anferre           #+#    #+#             */
/*   Updated: 2024/10/22 15:19:31 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"


void testAMateria()
{
	std::cout << std::endl << _BLUE << "---------------------------------------------------------------" << _END << std::endl;
	std::cout << _BOLD _BLUE << "Testing AMateria" << _END << std::endl << std::endl;

	ICharacter *bob = new Character("bob");
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();
	AMateria *tmp;

	tmp = ice->clone();
	std::cout << "Should be Ice: " << _AQUAMARINE << ice->getType() << _END << std::endl;
	delete tmp;
	
	tmp = cure->clone();
	std::cout << "Should be Cure: " << _EMMERALD << cure->getType() << _END << std::endl;
	delete tmp;
	
	ice->use(*bob);
	cure->use(*bob);
	
	delete bob;
	delete ice;
	delete cure;
}

void testMaterialSource()
{
	std::cout << std::endl << _BLUE << "---------------------------------------------------------------" << _END << std::endl;
	std::cout << _BOLD _BLUE << "Testing MateriaSource" << _END << std::endl << std::endl;
	
	IMateriaSource *src = new MateriaSource();
	
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	AMateria *tmp;
	
	if ((tmp = src->createMateria("ice")) != 0)
	{
		std::cout << "should be Ice: " << _AQUAMARINE << tmp->getType() << _END << std::endl;
		src->learnMateria(tmp);
	}
	if ((tmp = src->createMateria("cure")) != 0)
	{
		std::cout << "should be Cure: " << _EMMERALD << tmp->getType() << _END << std::endl;
		src->learnMateria(tmp);
	}
	tmp = tmp->clone();
	src->learnMateria(tmp); // should not be added and print inventory full
	src->createMateria("fire"); // should not be created and print materia not found
	
	delete tmp;
	delete src;
}

void testCharacter()
{
	std::cout << std::endl << _BLUE << "---------------------------------------------------------------" << _END << std::endl;
	std::cout << _BOLD _BLUE << "Testing Character" << _END << std::endl << std::endl;
	
	IMateriaSource *src = new MateriaSource();
	
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter *me = new Character("me");
	ICharacter *bob = new Character("bob");
	AMateria *tmp;
	AMateria *tmp2;
	
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp2 = tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp); //should not be added and print inventory full
	
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(5, *bob);
	me->unequip(0);
	me->use(0, *bob);
	me->unequip(0); // should not be unequiped and print no materia to unequip
	me->equip(tmp);
	me->use(0, *bob);
	
	delete tmp2;
	delete bob;
	delete me;
	delete src;	
}

int main()
{
	testAMateria();
	testMaterialSource();
	testCharacter();
	std::cout << std::endl
			  << _BLUE << "---------------------------------------------------------------" << _END << std::endl;
	std::cout << _BOLD _BLUE << "Subject Tests" << _END << std::endl
			  << std::endl;

	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}
