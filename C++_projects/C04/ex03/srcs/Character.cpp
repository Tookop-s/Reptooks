/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:43:52 by anferre           #+#    #+#             */
/*   Updated: 2024/10/22 15:13:57 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Default")
{
	if (DEBUG)
		std::cout << _MAGENTA << "Character Default constructor called" << _END << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	if (DEBUG)
		std::cout << _MAGENTA << "Character Default constructor called" << _END << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(Character const & src)
{
	if (DEBUG)
		std::cout << _MAGENTA << "Character Copy constructor called" << _END << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = src._inventory[i]->clone();
	this->_name = src._name;
}

Character & Character::operator=(Character const & rhs)
{
	if (DEBUG)
		std::cout << _MAGENTA << "Character Assignation operator called" << _END << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = rhs._inventory[i]->clone();
	}
	this->_name = rhs._name;
	return *this;
}

Character::~Character()
{
	if (DEBUG)
		std::cout << _MAGENTA << "Character Destructor called" << _END << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			return ;
		}
	}
	std::cout << _BOLD _RED << "Inventory full" << _END << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return ;
	if (this->_inventory[idx] == NULL)
	{
		std::cout << _BOLD _RED << "No materia to unequip" << _END << std::endl;
		return ;
	}
	else
		this->_inventory[idx] = NULL; // need to save the address of the materia to delete it later on 
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || !this->_inventory[idx])
	{
		if (idx < 0 || idx >= 4)
			std::cout << _BOLD _RED << "Index out of range" << _END << std::endl;
		else
			std::cout << _BOLD _RED << "No materia to use" << _END << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
}
