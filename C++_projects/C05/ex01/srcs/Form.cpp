/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:40:09 by anferre           #+#    #+#             */
/*   Updated: 2024/11/04 16:02:52 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	if (DEBUG)
		std::cout << "Default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (DEBUG)
		std::cout << "Parametric constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	if (DEBUG)
		std::cout << "Copy constructor called" << std::endl;
}

Form::~Form()
{
	if (DEBUG)
		std::cout << "Destructor called" << std::endl;
}

Form &Form::operator=(Form const &copy)
{
	if (DEBUG)
		std::cout << "Assignation operator called" << std::endl;
	if (this != &copy)
	{
		this->_signed = copy._signed;
	}
	return *this;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *Form::FormAlreadySignedException::what() const throw()
{
	return "Form is already signed";
}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getSigned() const
{
	return this->_signed;
}


int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (this->_signed)
		throw Form::FormAlreadySignedException();
	if (bureaucrat.getGrade() <= _gradeToSign)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
	o << "Form " << _BLUE << rhs.getName() << _END << " is ";
	if (rhs.getSigned())
		o << _BLUE << "signed" << _END;
	else
		o << _BLUE << "not signed" << _END;
	o << " and requires a grade of " << _BLUE << rhs.getGradeToSign() << _END << " to sign and a grade of " << _BLUE << rhs.getGradeToExecute() << _END << " to execute";
	return o;
}
