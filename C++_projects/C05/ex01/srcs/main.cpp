/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:16:28 by anferre           #+#    #+#             */
/*   Updated: 2024/11/04 16:08:47 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void testConstructors()
{
	//regular cases
	try
	{
		Form f1("F1", 1, 1);
		std::cout << f1 << std::endl;
		Form f2("F2", 150, 150);
		std::cout << f2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
	//exception cases
	try
	{
		Form f3("F3", 0, 0);
		std::cout << f3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
	try
	{
		Form f4("F4", 151, 151);
		std::cout << f4 << std::endl;
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
		Form f1("F1", 1, 1);
		Form f2("F2", 150, 150);
		
		std::cout << _BLUE << f1.getName() << _END << " signed is : " << _BLUE << (f1.getSigned() ? "true" : "false") << _END << std::endl;
		std::cout << _BLUE << f1.getName() << _END << " grade to execute is : " << _BLUE << f1.getGradeToExecute() << _END << std::endl;
		std::cout << _BLUE << f1.getName() << _END << " grade to sign is : " << _BLUE << f1.getGradeToSign() << _END << std::endl;
		std::cout << _BLUE << f2.getName() << _END << " signed is : " << _BLUE << (f2.getSigned() ? "true" : "false") << _END << std::endl;
		std::cout << _BLUE << f2.getName() << _END << " grade to sign is : " << _BLUE << f2.getGradeToSign() << _END << std::endl;
		std::cout << _BLUE << f2.getName() << _END << " grade to execute is : " << _BLUE << f2.getGradeToExecute() << _END << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
}

void testBeSigned()
{
	//regular cases + already signed 
	try
	{
		Form f1("F1", 1, 1);
		Bureaucrat b1("B1", 1);
		
		std::cout << f1 << std::endl;
		f1.beSigned(b1);
		std::cout << f1 << std::endl;
		b1.signForm(f1);
		std::cout << _BLUE << f1.getName() << _END << " signed is : " << _BLUE << (f1.getSigned() ? "true" : "false") << _END << std::endl;
		f1.beSigned(b1);
	}
	catch (std::exception &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
	//exception cases (grade too low)
	try
	{
		Form f2("F2", 149, 149);
		Bureaucrat b2("B2", 150);
		
		std::cout << std::endl;
		std::cout << f2 << std::endl;
		std::cout << b2 << std::endl;
		b2.signForm(f2);
		f2.beSigned(b2);
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
	std::cout << _GREEN << std::endl << "Test beSigned and signForm" << _END << std::endl << std::endl;;
	testBeSigned();
	std::cout << std::endl;
	
	return 0;
}
