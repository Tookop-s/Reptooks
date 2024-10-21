/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:32:48 by anferre           #+#    #+#             */
/*   Updated: 2024/10/22 00:09:14 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	if (DEBUG)
		std::cout << _DARKGREY << "MateriaSource Default constructor called" << _END << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	if (DEBUG)
		std::cout << _DARKGREY << "MateriaSource Copy constructor called" << _END << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
	if (this == &rhs)
		return *this;
	if (DEBUG)
		std::cout << _DARKGREY << "MateriaSource Assignation operator called" << _END << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		if (rhs._inventory[i])
			_inventory[i] = rhs._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	if (DEBUG)
		std::cout << _DARKGREY << "MateriaSource Destructor called" << _END << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			std::cout << _DARKGREY << "Deleted " << i << _END << std::endl;	
		}
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << _DARKGREY << "Learned " << m->getType() << _END << std::endl;
			return ;
		}
	}
	std::cout << _BOLD _RED << "Inventory is full" << _END << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] && _inventory[i]->getType() == type)
			return _inventory[i]->clone();
	}
	return 0;
}
