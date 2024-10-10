/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:25:11 by anferre           #+#    #+#             */
/*   Updated: 2024/10/10 14:13:16 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap("default_clap_name"), ScavTrap(),  FragTrap(), _name("default") {
	_hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
	if (DEBUG)
		std::cout << _LAGOON << "DiamondTrap default constructor called" << _END << std::endl;
	if (INFO)
		std::cout << _CYAN << " name : " << _name << " |  hitPoints : " << _hitPoints << " |  energyPoints : " \
		<< _energyPoints << " |  attackDamage : " << _attackDamage << _END << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name) {
	_hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
	if (DEBUG)
		std::cout << _LAGOON<< "DiamondTrap string constructor called" << _END << std::endl;
	if (INFO)
		std::cout << _CYAN << " name : " << _name << " |  hitPoints : " << _hitPoints << " |  energyPoints : " \
		<< _energyPoints << " |  attackDamage : " << _attackDamage << _END << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src) : ClapTrap(src) {
	if (DEBUG)
		std::cout << _LAGOON << "DiamondTrap copy constructor called" << _END << std::endl;
	if (INFO)
		std::cout << _CYAN << " name : " << _name << " |  hitPoints : " << _hitPoints << " |  energyPoints : " \
		<< _energyPoints << " |  attackDamage : " << _attackDamage << _END << std::endl;
}

DiamondTrap::~DiamondTrap( void ) {
	if (DEBUG)
		std::cout << _LAGOON << "DiamondTrap destructor called" << _END << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const & rhs) {
	if (this == &rhs)
		return *this;
	ClapTrap::operator=(rhs);
	if (DEBUG)
		std::cout << _LAGOON << "DiamondTrap assignement operator called" << _END << std::endl;
	if (INFO)
		std::cout << _CYAN << " name : " << _name << " |  hitPoints : " << _hitPoints << " |  energyPoints : " \
		<< _energyPoints << " |  attackDamage : " << _attackDamage << _END << std::endl;
	return *this;
}

void DiamondTrap::attack( std::string const & target ) {
	ScavTrap::attack(target);
	if (INFO)
		std::cout << _CYAN << " name : " << _name << " |  hitPoints : " << _hitPoints << " |  energyPoints : " \
		<< _energyPoints << " |  attackDamage : " << _attackDamage << _END << std::endl;
}

void DiamondTrap::whoAmI( void ) {
	std::cout << _LAGOON << "DiamondTrap name : " << _name << " ClapTrap name : " << ClapTrap::_name << _END << std::endl;
}
