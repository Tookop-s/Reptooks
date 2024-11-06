/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:16:28 by anferre           #+#    #+#             */
/*   Updated: 2024/11/06 14:02:32 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

void testIntern(){
	AForm *f[4];

	for (int i = 0; i < 4; i++)
		f[i] = 0;
	try
	{
		Intern intern;

		f[0] = intern.makeForm("shrubbery creation", "target1");
		f[1] = intern.makeForm("robotomy request", "target2");
		f[2] = intern.makeForm("presidential pardon", "target3");
		f[3] = intern.makeForm("unknown", "target4");
		for (int i = 0; i < 4; i++)
		{
			if (f[i])
				delete f[i];
		}
	}
	catch (std::exception &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
		for (int i = 0; i < 4; i++)
		{
			if (f[i])
				delete f[i];
		}
	}
}

int main()
{
	std::cout << _GREEN <<"Test Intern" << _END << std::endl << std::endl;;
	testIntern();
	std::cout << std::endl;
	
	return 0;
}
