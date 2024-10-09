/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:22:28 by anferre           #+#    #+#             */
/*   Updated: 2024/10/09 17:28:25 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("default_clap_name"), _hitPoints(100), _energyPoints(100), _attackDamage(30) {
	if (DEBUG)
		std::cout << _GOLD << "ClapTrap default constructor called" << _END << std::endl;
}

ClapTrap::ClapTrap( std::string name) : _name(name), _hitPoints(100), _energyPoints(100), _attackDamage(30) {
	if (DEBUG)
		std::cout << _GOLD << "ClapTrap string constructor called" << _END << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & src) {
	if (DEBUG)
		std::cout << _GOLD << "ClapTrap copy constructor called" << _END << std::endl;
	*this = src;
}

ClapTrap& ClapTrap::operator=(ClapTrap const & rhs){
	if (this == &rhs)
		return *this;
	if (DEBUG)
		std::cout << _GOLD << "ClapTrap assignement operator called" << _END << std::endl;
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap( void ){
	std::cout << _GOLD << "ClapTrap destructor called" << _END << std::endl;
	return ; 
}

void ClapTrap::attack( std::string const & target ) {
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << _GOLD << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage !" << _END << std::endl;
		_energyPoints--;
	}
	else if (_hitPoints <= 0)
		std::cout << _GOLD << "ClapTrap " << this->_name << " is already dead cannot attack !" << _END << std::endl;
	else
		std::cout << _GOLD << "ClapTrap " << this->_name << " is out of energy cannot attack !" << _END << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount ) {
	if (_hitPoints > 0 && _energyPoints > 0 && amount > 0)
	{
		std::cout << _GOLD << "ClapTrap " << this->_name << " is being repaired for " << amount << " points !" << _END << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
	else if (_hitPoints <= 0)
		std::cout << _GOLD << "ClapTrap " << this->_name << " is already dead cannot repair !" << _END << std::endl;
	else
		std::cout << _GOLD << "ClapTrap " << this->_name << " is out of energy cannot repair !" << _END << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount ) { 
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		if (amount > _hitPoints)
			_hitPoints = 0;
		else
			_hitPoints -= amount;
		std::cout << _GOLD << "ClapTrap " << this->_name << " takes " << amount << " points of damage !" << _END << std::endl;
	}
	else if (_hitPoints <= 0)
		std::cout << _GOLD << "ClapTrap " << this->_name << " is already dead cannot take more damage !" << _END << std::endl;
	else
		std::cout << _GOLD << "ClapTrap " << this->_name << " is out of energy cannot take more damage !" << _END << std::endl;
}
