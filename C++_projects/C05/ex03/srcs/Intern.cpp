/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:19:27 by anferre           #+#    #+#             */
/*   Updated: 2024/11/06 14:23:46 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern()
{
	if (DEBUG)
		std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern( Intern const & src )
{
	if (DEBUG)
		std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern::~Intern()
{
	if (DEBUG)
		std::cout << "Intern destructor called" << std::endl;
}

Intern & Intern::operator=( Intern const & rhs )
{
	if (DEBUG)
		std::cout << "Intern assignation operator called" << std::endl;
	if (this != &rhs)
	{
	}
	return *this;
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return "Form not found";
}

AForm *createShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *createRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *createPresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	struct FormType
	{
		std::string formName;
		AForm *(*create)(std::string target);
	};
	//anonymous functions struct / lambda functions
	static const FormType forms[] = {
		{"shrubbery creation", createShrubberyCreationForm},
		{"robotomy request", createRobotomyRequestForm},
		{"presidential pardon", createPresidentialPardonForm},
	};
	for (int i = 0; i < 3; i++)
	{
		if (forms[i].formName == name)
		{
			std::cout << "Intern creates " << _BLUE << name << _END << std::endl;
			return forms[i].create(target);
		}
	}
	throw FormNotFoundException();
}
