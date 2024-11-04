/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:16:28 by anferre           #+#    #+#             */
/*   Updated: 2024/11/04 14:27:31 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void testConstructors()
{
	//regular cases
	try
	{
		Bureaucrat b1("B1", 1);
		std::cout << b1 << std::endl;
		Bureaucrat b2("B2", 150);
		std::cout << b2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
	//exception cases
	try
	{
		Bureaucrat b3("B3", 0);
		std::cout << b3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
	try
	{
		Bureaucrat b4("B4", 151);
		std::cout << b4 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
}

void testIncrement()
{
	try
	{
		Bureaucrat b1("B1", 1);
		Bureaucrat b2("B2", 150);
		
		std::cout << b2 << std::endl;
		b2.incrementGrade();
		std::cout << b2 << std::endl;
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
}

void testDecrement()
{
	try
	{
		Bureaucrat b1("B1", 1);
		Bureaucrat b2("B2", 150);
		
		std::cout << b1 << std::endl;
		b1.decrementGrade();
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		b2.decrementGrade();
		std::cout << b2 << std::endl;
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
		Bureaucrat b1("B1", 1);
		Bureaucrat b2("B2", 150);
		
		std::cout << "b1 name is : " << _BLUE << b1.getName() << _END << std::endl;
		std::cout << "b1 grade is : " << _BLUE << b1.getGrade() << _END << std::endl;
		std::cout << "b2 name is : " << _BLUE << b2.getName() << _END << std::endl;
		std::cout << "b2 grade is : " << _BLUE << b2.getGrade() << _END << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	std::cout << _GREEN <<"Test constructors" << _END << std::endl << std::endl;;
	testConstructors();
	std::cout << _GREEN << std::endl << "Test increment" << _END << std::endl << std::endl;;
	testIncrement();
	std::cout << _GREEN << std::endl << "Test decrement" << _END << std::endl << std::endl;;
	testDecrement();
	std::cout << _GREEN << std::endl << "Test getters" << _END << std::endl << std::endl;;
	testGetters();
	std::cout << std::endl;
	
	return 0;
}
