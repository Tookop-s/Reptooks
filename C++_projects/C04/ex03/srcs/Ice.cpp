/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:15:15 by anferre           #+#    #+#             */
/*   Updated: 2024/10/21 17:44:27 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	if (DEBUG)
		std::cout << _AQUAMARINE << "Ice Default constructor called" << _END << std::endl;
}

Ice::Ice(Ice const & src) : AMateria(src)
{
	if (DEBUG)
		std::cout << _AQUAMARINE << "Ice Copy constructor called" << _END << std::endl;
	this->_type = src._type;
}

Ice & Ice::operator=(Ice const & rhs)
{
	if (this == &rhs)
		return *this;
	if (DEBUG)
		std::cout << _AQUAMARINE << "Ice Assignation operator called" << _END << std::endl;
	AMateria::operator=(rhs);
	this->_type = rhs._type;
	return *this;
}

Ice::~Ice()
{
	if (DEBUG)
		std::cout << _AQUAMARINE << "Ice Destructor called" << _END << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << _AQUAMARINE << "* shoots an ice bolt at " << target.getName() << " *" << _END << std::endl;
}
