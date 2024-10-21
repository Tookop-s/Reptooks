/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:26:11 by anferre           #+#    #+#             */
/*   Updated: 2024/10/21 14:40:15 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Format.hpp"


int main()
{
	AAnimal *animals[4];
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
	animals[0]->makeSound();
	animals[1]->makeSound();
	std::cout << _GOLD << animals[2]->getType() << _END << std::endl;
	std::cout << _ORANGE << animals[3]->getType() << _END << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete animals[i];
		std::cout << std::endl;
	}
	// AAnimal* test = new AAnimal(); // compile error
	return 0;
}
