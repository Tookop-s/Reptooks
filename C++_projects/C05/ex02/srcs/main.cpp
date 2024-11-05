/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:16:28 by anferre           #+#    #+#             */
/*   Updated: 2024/11/05 13:45:02 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void testConstructors()
{
	//regular cases
	try
	{
		ShrubberyCreationForm S1("F1");
		std::cout << S1 << std::endl;
		PresidentialPardonForm P1("F2");
		std::cout << P1 << std::endl;
		RobotomyRequestForm R1("F3");
		std::cout << R1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
}

void testGetters()
{
	try
	{
		ShrubberyCreationForm f1("F1");
		PresidentialPardonForm f2("F2");
		RobotomyRequestForm f3("F3");
		
		std::cout << _BLUE << f1.getName() << _END << " signed is : " << _BLUE << (f1.getSigned() ? "true" : "false") << _END << std::endl;
		std::cout << _BLUE << f1.getName() << _END << " grade to execute is : " << _BLUE << f1.getGradeToExecute() << _END << std::endl;
		std::cout << _BLUE << f1.getName() << _END << " grade to sign is : " << _BLUE << f1.getGradeToSign() << _END << std::endl;
		std::cout << _BLUE << f1.getName() << _END << " target is : " << _BLUE << f1.getTarget() << _END << std::endl;
		std::cout << _BLUE << f2.getName() << _END << " signed is : " << _BLUE << (f2.getSigned() ? "true" : "false") << _END << std::endl;
		std::cout << _BLUE << f2.getName() << _END << " grade to sign is : " << _BLUE << f2.getGradeToSign() << _END << std::endl;
		std::cout << _BLUE << f2.getName() << _END << " grade to execute is : " << _BLUE << f2.getGradeToExecute() << _END << std::endl;
		std::cout << _BLUE << f2.getName() << _END << " target is : " << _BLUE << f2.getTarget() << _END << std::endl;
		std::cout << _BLUE << f3.getName() << _END << " signed is : " << _BLUE << (f3.getSigned() ? "true" : "false") << _END << std::endl;
		std::cout << _BLUE << f3.getName() << _END << " grade to sign is : " << _BLUE << f3.getGradeToSign() << _END << std::endl;
		std::cout << _BLUE << f3.getName() << _END << " grade to execute is : " << _BLUE << f3.getGradeToExecute() << _END << std::endl;
		std::cout << _BLUE << f3.getName() << _END << " target is : " << _BLUE << f3.getTarget() << _END << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
}

void testSignedGradeShrubberyCreationForm()
{
	//testing beSigned, execute and executeForm + beSigned grade too low exception
	try
	{
		std::cout << _GREEN << "ShrubberyCreationForm" << _END << std::endl;
		ShrubberyCreationForm f1("F1");
		Bureaucrat b1("B1", 1);
		Bureaucrat b2("B2", 146);
		
		std::cout << _BLUE << f1.getName() << _END << " signed is : " << _BLUE << (f1.getSigned() ? "true" : "false") << _END << std::endl;
		
		f1.beSigned(b1);
		f1.execute(b1);
		b1.executeForm(f1);
		
		std::cout << _BLUE << f1.getName() << _END << " signed is : " << _BLUE << (f1.getSigned() ? "true" : "false") << _END << std::endl;
		
		f1.beSigned(b2);
	}
	catch (std::exception &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
	// testing execute grade too low exception
	try
	{
		ShrubberyCreationForm f1("F1");
		Bureaucrat b1("B1", 138);
		
		std::cout << _BLUE << f1.getName() << _END << " signed is : " << _BLUE << (f1.getSigned() ? "true" : "false") << _END << std::endl;

		f1.beSigned(b1);
		f1.execute(b1);
	}
	catch (std::exception &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
	//testing file already exists exception
	try
	{
		ShrubberyCreationForm f1;
		Bureaucrat b1("B1", 1);
		
		std::cout << _BLUE << f1.getName() << _END << " signed is : " << _BLUE << (f1.getSigned() ? "true" : "false") << _END << std::endl;

		f1.beSigned(b1);
		f1.execute(b1);
	}
	catch (std::exception &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
}

void testSignedGradeRobotomyRequestForm()
{
	//testing beSigned, execute and executeForm + beSigned grade too low exception
	try 
	{
		std::cout << _GREEN << "RobotomyRequestForm" << _END << std::endl;
		RobotomyRequestForm f2("F2");
		Bureaucrat b1("B1", 1);
		Bureaucrat b2("B2", 73);
		
		std::cout << _BLUE << f2.getName() << _END << " signed is : " << _BLUE << (f2.getSigned() ? "true" : "false") << _END << std::endl;
		
		f2.beSigned(b1);
		f2.execute(b1);
		b1.executeForm(f2);
		f2.execute(b1);

		std::cout << _BLUE << f2.getName() << _END << " signed is : " << _BLUE << (f2.getSigned() ? "true" : "false") << _END << std::endl;

		f2.beSigned(b2);
	}
	catch (std::exception &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
	//execute no sign exception and Bureaucrat executeForm exception
	try
	{
		RobotomyRequestForm f2("F2");
		Bureaucrat b1("B1", 45);

		std::cout << _BLUE << f2.getName() << _END << " signed is : " << _BLUE << (f2.getSigned() ? "true" : "false") << _END << std::endl;
		
		b1.executeForm(f2);
	}
	catch (std::exception &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
}

void testSignedGradePresidentialPardonForm()
{
		//regular cases PresidentialPardonForm beSigned, executeForm + beSigned exception
	try
	{
		std::cout << _GREEN << "PresidentialPardonForm" << _END << std::endl;
		PresidentialPardonForm f3("F3");
		Bureaucrat b1("B1", 1);
		Bureaucrat b2("B2", 26);
		
		std::cout << _BLUE << f3.getName() << _END << " signed is : " << _BLUE << (f3.getSigned() ? "true" : "false") << _END << std::endl;

		f3.beSigned(b1);
		b1.executeForm(f3);
		
		
		std::cout << _BLUE << f3.getName() << _END << " signed is : " << _BLUE << (f3.getSigned() ? "true" : "false") << _END << std::endl;

		f3.beSigned(b2);
	}
	catch (std::exception &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
}

int main()
{
	std::cout << _GREEN <<"Test constructors" << _END << std::endl << std::endl;;
	testConstructors();
	std::cout << _GREEN << std::endl << "Test getters" << _END << std::endl << std::endl;;
	testGetters();
	std::cout << _GREEN << std::endl << "Test sign and grade ShrubberyCreationForm " << _END << std::endl << std::endl;;
	testSignedGradeShrubberyCreationForm();
	std::cout << _GREEN << std::endl << "Test sign and grade RobotomyRequestForm " << _END << std::endl << std::endl;;
	testSignedGradeRobotomyRequestForm();
	std::cout << _GREEN << std::endl << "Test sign and grade PresidentialPardonForm " << _END << std::endl << std::endl;;
	testSignedGradePresidentialPardonForm();
	std::cout << std::endl;
	
	return 0;
}
