/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:28:40 by anferre           #+#    #+#             */
/*   Updated: 2024/11/12 14:15:22 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate(void)
{
	int random = rand() % 3;

	if (random == 0)
	{
		std::cout << _LAGOON "A" << _END << " has been created" << std::endl;
		return new A();
	}
	else if (random == 1)
	{
		std::cout << _PURPLE "B" << _END << " has been created" << std::endl;
		return new B();
	}
	else
	{
		std::cout << _CYAN "C" << _END << " has been created" << std::endl;
		return new C();
	}
}

void identify(Base *p)
{
	std::cout << "Identifying pointer : ";
	if (dynamic_cast<A *>(p))
		std::cout << _LAGOON << "A" << _END << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << _PURPLE << "B" << _END << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << _CYAN << "C" << _END << std::endl;
	else
		std::cout << _RED << "Unknown type " << _END << std::endl;
}

void identify(Base &p)
{
	std::cout << "Identifying reference : ";
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << _LAGOON << "A" << _END << std::endl;
		return;
	}
	catch (...)
	{
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << _PURPLE << "B" << _END << std::endl;
		return;
	}
	catch (...)
	{
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << _CYAN << "C" << _END << std::endl;
		return;
	}
	catch (...)
	{
	}
	std::cout << _RED << "Unknown type " << _END << std::endl;
}
