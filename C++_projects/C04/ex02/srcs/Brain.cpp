/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:17:26 by anferre           #+#    #+#             */
/*   Updated: 2024/10/21 13:53:46 by anferre          ###   ########.fr       */
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
		std::cout << _CYAN << "Brain default constructor called" << _END << std::endl;
}

Brain::Brain(const Brain &src)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = src.ideas[i];
	}
	if (DEBUG)
		std::cout << _CYAN << "Brain copy constructor called" << _END << std::endl;
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
		std::cout << _CYAN << "Brain assignement operator called" << _END << std::endl;
	return *this;
}

Brain::~Brain( void )
{
	if (DEBUG)
		std::cout << _CYAN << "Brain default destructor called" << _END << std::endl;
}

void Brain::setIdea(std::string idea, int index)
{
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return this->ideas[index];
	return "Index out of bounds";
}
