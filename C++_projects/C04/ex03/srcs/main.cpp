/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:26:11 by anferre           #+#    #+#             */
/*   Updated: 2024/10/21 17:41:47 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"


int main()
{
	IMateriaSource *src = new MateriaSource();
	std::cout << std::endl << _RIVIERA << "Learning Ice and Cure" << _END << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << std::endl << _RIVIERA << "Creating me" << _END << std::endl;
	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;
	delete bob;
	delete me;
	delete src;

	return 0;
}
