/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:50:48 by anferre           #+#    #+#             */
/*   Updated: 2024/10/10 13:19:23 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap("default") {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	if (DEBUG)
		std::cout << _SALMON << "FragTrap default constructor called" << _END << std::endl;
	if (INFO)	
		std::cout << _CYAN << " name : " << _name << " |  hitPoints : " << _hitPoints << " |  energyPoints : " \
		<< _energyPoints << " |  attackDamage : " << _attackDamage << _END << std::endl;	
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	if (DEBUG)
		std::cout << _SALMON << "FragTrap string constructor called" << _END << std::endl;
	if (INFO)	
		std::cout << _CYAN << " name : " << _name << " |  hitPoints : " << _hitPoints << " |  energyPoints : " \
		<< _energyPoints << " |  attackDamage : " << _attackDamage << _END << std::endl;	
}

FragTrap::FragTrap( FragTrap const & src) : ClapTrap(src) {
	if (DEBUG)
		std::cout << _SALMON << "FragTrap copy constructor called" << _END << std::endl;
	if (INFO)	
		std::cout << _CYAN << " name : " << _name << " |  hitPoints : " << _hitPoints << " |  energyPoints : " \
		<< _energyPoints << " |  attackDamage : " << _attackDamage << _END << std::endl;	
}

FragTrap::~FragTrap( void ) {
	if (DEBUG)
		std::cout << _SALMON << "FragTrap destructor called" << _END << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const & rhs) {
	if (this == &rhs)
		return *this;
	ClapTrap::operator=(rhs);
	if (DEBUG)
		std::cout << _SALMON << "FragTrap assignement operator called" << _END << std::endl;
	if (INFO)	
		std::cout << _CYAN << " name : " << _name << " |  hitPoints : " << _hitPoints << " |  energyPoints : " \
		<< _energyPoints << " |  attackDamage : " << _attackDamage << _END << std::endl;	
	return *this;
}

void FragTrap::highFivesGuys( void ) {
	std::cout << _SALMON << "FragTrap" << _name << " is asking for a high five !" << _END << std::endl;
}
