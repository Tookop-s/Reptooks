/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:17:26 by anferre           #+#    #+#             */
/*   Updated: 2024/10/18 22:34:53 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = "great idea";
	}
	if (DEBUG)
		std::cout << _BROWN << "Brain default constructor called" << _END << std::endl;
}

Brain::Brain(const Brain &src)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = src.ideas[i];
	}
	if (DEBUG)
		std::cout << _BROWN << "Brain copy constructor called" << _END << std::endl;
}

Brain &Brain::operator=(const Brain &rhs)
{
	if (this == &rhs)
		return *this;
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = rhs.ideas[i];
	}
	if (DEBUG)
		std::cout << _BROWN << "Brain assignement operator called" << _END << std::endl;
	return *this;
}

Brain::~Brain( void )
{
	if (DEBUG)
		std::cout << _BROWN << "Brain default destructor called" << _END << std::endl;
}
