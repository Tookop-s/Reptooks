/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:40:09 by anferre           #+#    #+#             */
/*   Updated: 2024/11/05 12:08:04 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	if (DEBUG)
		std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (DEBUG)
		std::cout << "Parametric constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	if (DEBUG)
		std::cout << "Copy constructor called" << std::endl;
}

AForm::~AForm()
{
	if (DEBUG)
		std::cout << "Destructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &copy)
{
	if (DEBUG)
		std::cout << "Assignation operator called" << std::endl;
	if (this != &copy)
	{
		this->_signed = copy._signed;
	}
	return *this;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::AFormAlreadySignedException::what() const throw()
{
	return "Form is already signed";
}

const char *AForm::AFormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getSigned() const
{
	return this->_signed;
}


int AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (this->_signed)
		throw AForm::AFormAlreadySignedException();
	if (bureaucrat.getGrade() <= _gradeToSign)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, AForm const &rhs)
{
	o << "Form " << _BLUE << rhs.getName() << _END << " is ";
	if (rhs.getSigned())
		o << _BLUE << "signed" << _END;
	else
		o << _BLUE << "not signed" << _END;
	o << " and requires a grade of " << _BLUE << rhs.getGradeToSign() << _END << " to sign and a grade of " << _BLUE << rhs.getGradeToExecute() << _END << " to execute";
	return o;
}
