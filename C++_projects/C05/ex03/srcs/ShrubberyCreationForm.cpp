/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:37:29 by anferre           #+#    #+#             */
/*   Updated: 2024/11/05 13:42:58 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm parameter constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy), _target(copy._target)
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	if (this != &copy)
	{
		this->_target = copy._target;
	}
	return (*this);
}

//store the error message in a string and return it in the what() function
ShrubberyCreationForm::FileNotOpenException::FileNotOpenException(std::string filename) : _msg("Error: Could not open file " + filename)
{
}

//store the error message in a string and return it in the what() function
ShrubberyCreationForm::FileAlreadyExistsException::FileAlreadyExistsException(std::string filename) : _msg("Error: File " + filename + " already exists")
{
}

const char* ShrubberyCreationForm::FileNotOpenException::what() const throw()
{
	return (_msg.c_str());
}

const char* ShrubberyCreationForm::FileAlreadyExistsException::what() const throw()
{
	return (_msg.c_str());
}

ShrubberyCreationForm::FileNotOpenException::~FileNotOpenException() throw()
{
}

ShrubberyCreationForm::FileAlreadyExistsException::~FileAlreadyExistsException() throw()
{
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

bool copyFile(std::string filename)
{
	std::ifstream existingFile(filename.c_str());
	if (existingFile.is_open())
	{
		existingFile.close();
		throw ShrubberyCreationForm::FileAlreadyExistsException(filename);
	}
	std::ofstream file(filename.c_str());
	if (!file.is_open())
		throw ShrubberyCreationForm::FileNotOpenException(filename);
	file << "   *       *       *   " << std::endl;
	file << "  ***     ***     ***  " << std::endl;
	file << " *****   *****   ***** " << std::endl;
    file << "******* ******* *******" << std::endl;
    file << "   |       |       |   " << std::endl;
	file.close();
	return (true);
}

bool ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string filename = this->_target + "_shrubbery";

	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	if (!this->getSigned())
		throw AForm::AFormNotSignedException();
	if (!copyFile(filename))
		return (false);
	return (true);
}
