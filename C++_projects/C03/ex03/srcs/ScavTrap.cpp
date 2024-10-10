/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:57:46 by anferre           #+#    #+#             */
/*   Updated: 2024/10/10 17:21:43 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap("default") {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	if (DEBUG)
		std::cout << _LILAC << "ScavTrap default constructor called" << _END << std::endl;
	if (INFO)	
		std::cout << _CYAN << " name : " << _name << " |  hitPoints : " << _hitPoints << " |  energyPoints : " \
		<< _energyPoints << " |  attackDamage : " << _attackDamage << _END << std::endl;	
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	if (DEBUG)
		std::cout << _LILAC << "ScavTrap string constructor called" << _END << std::endl;
	if (INFO)
		std::cout << _CYAN << " name : " << _name << " |  hitPoints : " << _hitPoints << " |  energyPoints : " \
		<< _energyPoints << " |  attackDamage : " << _attackDamage << _END << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & src) : ClapTrap(src) {
	if (DEBUG)
		std::cout << _LILAC << "ScavTrap copy constructor called" << _END << std::endl;
	if (INFO)
		std::cout << _CYAN << " name : " << _name << " |  hitPoints : " << _hitPoints << " |  energyPoints : " \
		<< _energyPoints << " |  attackDamage : " << _attackDamage << _END << std::endl;
}

ScavTrap::~ScavTrap( void ) {
	if (DEBUG)
		std::cout << _LILAC << "ScavTrap destructor called" << _END << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const & rhs) {
	if (this == &rhs)
		return *this;
	ClapTrap::operator=(rhs);
	if (DEBUG)
		std::cout << _LILAC << "ScavTrap assignement operator called" << _END << std::endl;
	if (INFO)
		std::cout << _CYAN << " name : " << _name << " |  hitPoints : " << _hitPoints << " |  energyPoints : " \
		<< _energyPoints << " |  attackDamage : " << _attackDamage << _END << std::endl;
	return *this;
}

void ScavTrap::attack( std::string const & target ) {
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << _LILAC << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage !" << _END << std::endl;
		if (INFO)
			std::cout << _CYAN << "ScavTrap " << _name << " has " << _energyPoints << " energy points !" << _END << std::endl;
		_energyPoints--;
	}
	else if (_hitPoints<= 0)
		std::cout << _LILAC << "ScavTrap " << _name << " is already dead cannot attack !" << _END << std::endl;
	else
		std::cout << _LILAC << "ScavTrap " << _name << " is out of energy cannot attack !" << _END << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << _LILAC << "ScavTrap " << _name << " have entered in Gate keeper mode" << _END << std::endl;
}
