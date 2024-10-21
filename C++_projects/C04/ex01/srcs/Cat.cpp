/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:00:11 by anferre           #+#    #+#             */
/*   Updated: 2024/10/21 13:45:30 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Format.hpp"
#include "Brain.hpp"

Cat::Cat( void ) : Animal() {
	if (DEBUG)
		std::cout << _ORANGE << "Cat default constructor called" << _END << std::endl;
	this->_brain = new Brain();
	this->_type = "Cat";
}

Cat::Cat( Cat const & src ) : Animal(src) {
	if (DEBUG)
		std::cout << _ORANGE << "Cat copy constructor called" << _END << std::endl;
	this->_type = src._type;
	this->_brain = new Brain(*src._brain);
}

Cat& Cat::operator=( Cat const & rhs ) {
	if (this == &rhs)
		return *this;
	if (DEBUG)
		std::cout << _ORANGE << "Cat assignement operator called" << _END << std::endl;
	this->_type = rhs._type;
	Animal::operator=(rhs);
	if (this->_brain)
		delete this->_brain;
	this->_brain = new Brain(*rhs._brain);
	return *this;
}

Cat::~Cat( void ) {
	delete this->_brain;
	if (DEBUG)
		std::cout << _ORANGE << "Cat default destructor called" << _END << std::endl;
}

void Cat::makeSound( void ) const {
	std::cout << _ORANGE << "Cat meow" << _END << std::endl;
}

std::string Cat::getType( void ) const {
	return this->_type;
}

void Cat::setIdea(std::string idea, int index) {
	if (this->_brain)
		this->_brain->setIdea(idea, index);
}

std::string Cat::getIdea(int index) const {
	if (this->_brain)
		return this->_brain->getIdea(index);
	return "No brain";
}
