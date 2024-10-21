/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:24:29 by anferre           #+#    #+#             */
/*   Updated: 2024/10/21 17:33:33 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	if (DEBUG)
		std::cout << _EMMERALD << "Cure Default constructor called" << _END << std::endl;
}

Cure::Cure(Cure const & src) : AMateria(src)
{
	if (DEBUG)
		std::cout << _EMMERALD << "Cure Copy constructor called" << _END << std::endl;
	this->_type = src._type;
}

Cure & Cure::operator=(Cure const & rhs)
{
	if (this == &rhs)
		return *this;
	if (DEBUG)
		std::cout << _EMMERALD << "Cure Assignation operator called" << _END << std::endl;
	AMateria::operator=(rhs);
	this->_type = rhs._type;
	return *this;
}

Cure::~Cure()
{
	if (DEBUG)
		std::cout << _EMMERALD << "Cure Destructor called" << _END << std::endl;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << _EMMERALD << "* heals " << target.getName() << "'s wound *" << _END << std::endl;
}
