/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:26:11 by anferre           #+#    #+#             */
/*   Updated: 2024/10/18 22:51:12 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Format.hpp"


int main()
{
	Animal *animals[4];
	for (int i = 0; i < 2; i++)
	{
		animals[i] = new Dog();
		animals[i + 2] = new Cat();
	}
	Animal *copy = animals[0];
	delete copy;
	for (int i = 0; i < 4; i++)
	{
		delete animals[i];
	}
	return 0;
}
