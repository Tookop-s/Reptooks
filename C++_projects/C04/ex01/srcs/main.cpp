/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:26:11 by anferre           #+#    #+#             */
/*   Updated: 2024/10/18 23:09:01 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Format.hpp"


int main()
{
	Animal *animals[4];
	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
		{
			animals[i] = new Dog();
			std::cout << std::endl;
		}
		else
		{
			animals[i] = new Cat();
			std::cout << std::endl;
		}
	}
	
	*animals[0] = *animals[2];
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete animals[i];
		std::cout << std::endl;
	}
	return 0;
}
