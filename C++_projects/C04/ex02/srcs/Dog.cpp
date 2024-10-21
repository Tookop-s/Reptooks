/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:00:06 by anferre           #+#    #+#             */
/*   Updated: 2024/10/21 14:25:09 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Format.hpp"
#include "Brain.hpp"

Dog::Dog( void ) : AAnimal() {
	if (DEBUG)
		std::cout << _GOLD << "Dog default constructor called" << _END << std::endl;
	this->_brain = new Brain();
	this->_type = "Dog";
}

Dog::Dog( Dog const & src ) : AAnimal(src) {
	if (DEBUG)
		std::cout << _GOLD << "Dog copy constructor called" << _END << std::endl;
	this->_type = src._type;
	this->_brain = new Brain(*src._brain);
}

Dog& Dog::operator=( Dog const & rhs ) {
	if (this == &rhs)
		return *this;
	if (DEBUG)
		std::cout << _GOLD << "Dog assignement operator called" << _END << std::endl;
	AAnimal::operator=(rhs);
	this->_type = rhs._type;
	if (this->_brain)
		delete this->_brain;
	this->_brain = new Brain(*rhs._brain);
	return *this;
}

Dog::~Dog( void ) {
	delete this->_brain;
	if (DEBUG)
		std::cout << _GOLD << "Dog default destructor called" << _END << std::endl;
}

void Dog::makeSound( void ) const {
	std::cout << _GOLD << "Dog waf" << _END << std::endl;
}


std::string Dog::getType( void ) const {
	return this->_type;
}

void Dog::setIdea(std::string idea, int index) {
	if (this->_brain)
		return this->_brain->setIdea(idea, index);
	std::cout << "Brain is null" << std::endl;
}

std::string Dog::getIdea(int index) const {
	if (this->_brain)
		return this->_brain->getIdea(index);
	return "No brain";
}
