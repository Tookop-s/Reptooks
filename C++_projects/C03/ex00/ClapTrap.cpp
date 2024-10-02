/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:22:28 by anferre           #+#    #+#             */
/*   Updated: 2024/10/02 14:54:24 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	if (DEBUG)
		std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap string constructor called" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & src) {
	if (DEBUG)
		std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
	return;
}

ClapTrap& ClapTrap::operator=(ClapTrap const & rhs){
	if (DEBUG)
		std::cout << "ClapTrap assignement operator called" << std::endl;
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap( void ){
	std::cout << "ClapTrap destructor called" << std::endl;
	return ; 
}

void ClapTrap::attack( std::string const & target ) {
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage !" << std::endl;
		_energyPoints--;
	}
	else if (_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " is already dead cannot attack !" << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " is out of energy cannot attack !" << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount ) {
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " is being repaired for " << amount << " points !" << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
	else if (_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " is already dead cannot repair !" << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " is out of energy cannot repair !" << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount ) { 
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		if (amount > _hitPoints)
			_hitPoints = 0;
		else
			_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage !" << std::endl;
		std::cout << "hitPoints :" << _hitPoints << std::endl;
	}
	else if (_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " is already dead cannot take more damage !" << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " is out of energy cannot take more damage !" << std::endl;
}
