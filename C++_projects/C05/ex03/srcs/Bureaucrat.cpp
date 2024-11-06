/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:16:54 by anferre           #+#    #+#             */
/*   Updated: 2024/11/05 17:31:07 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	if (DEBUG)
		std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (DEBUG)
		std::cout << "Parametric constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy._name), _grade(copy._grade)
{
	if (DEBUG)
		std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	if (DEBUG)
		std::cout << "Destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy)
{
	if (DEBUG)
		std::cout << "Assignation operator called" << std::endl;
	if (this != &copy)
	{
		this->_grade = copy._grade;
	}
	return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *Bureaucrat::CantExecuteFormException::what() const throw()
{
	return _msg.c_str();
}

Bureaucrat::CantExecuteFormException::CantExecuteFormException(const std::string &msg) : _msg("Bureaucrat can't execute the form : " + msg)
{
}

Bureaucrat::CantExecuteFormException::~CantExecuteFormException() throw()
{
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << _BLUE << rhs.getName() << _END << " bureaucrat grade is " << _BLUE << rhs.getGrade() << _END;
	return o;
}

void Bureaucrat::signForm(AForm &form)
{
	if (form.getSigned())
		std::cout << _BLUE << getName() << _END << " signed " << _BLUE << form.getName() << _END << std::endl;
	else
	{
		std::cout << _BLUE << getName() << _END << " cannot sign " << _BLUE << form.getName() << _END << " because ";
		if (form.getGradeToSign() < getGrade())
			std::cout << _BLUE << getName() <<_END << "'s grade is too low" << std::endl;
		else
			std::cout << _BLUE << getName() <<_END << "'s grade is too high" << std::endl;
	}
		
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		if (form.execute(*this))
			std::cout << _BLUE << getName() << _END << " executed " << _BLUE << form.getName() << _END << std::endl;
	}
	catch (std::exception &e)
	{
		throw Bureaucrat::CantExecuteFormException(e.what());
	}
}
