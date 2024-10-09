/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:50:48 by anferre           #+#    #+#             */
/*   Updated: 2024/10/09 18:04:59 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {
	if (DEBUG)
		std::cout << _SALMON << "FragTrap default constructor called" << _END << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
	if (DEBUG)
		std::cout << _SALMON << "FragTrap string constructor called" << _END << std::endl;
}

FragTrap::FragTrap( FragTrap const & src) : ClapTrap(src) {
	if (DEBUG)
		std::cout << _SALMON << "FragTrap copy constructor called" << _END << std::endl;
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
	return *this;
}

void FragTrap::highFivesGuys( void ) {
	std::cout << _SALMON << "FragTrap " << _name << " is asking for a high five ! " << _END << std::endl;
}
