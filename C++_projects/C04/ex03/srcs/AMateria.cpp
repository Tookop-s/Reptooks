/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:58:35 by anferre           #+#    #+#             */
/*   Updated: 2024/10/21 17:17:26 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	if (DEBUG)
		std::cout << _BROWN << "AMateria default constructor called" << _END << std::endl;
	this->_type = "default";
}

AMateria::AMateria(AMateria const & src)
{
	if (DEBUG)
		std::cout << _BROWN << "AMateria copy constructor called" << _END << std::endl;
	this->_type = src._type;
}

AMateria & AMateria::operator=( AMateria const & rhs)
{
	if (this == &rhs)
		return *this;
	if (DEBUG)
		std::cout << _BROWN << "AMateria assignement operator called" << _END << std::endl;
	this->_type = rhs._type;
	return *this;
}

AMateria::~AMateria()
{
	if (DEBUG)
		std::cout << _BROWN << "AMateria default destructor called" << _END << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	if (DEBUG)
		std::cout << _BROWN << "AMateria type constructor called" << _END << std::endl;
	this->_type = type;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
 	(void)target;
}
