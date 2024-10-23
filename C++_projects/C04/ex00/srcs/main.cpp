/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:26:11 by anferre           #+#    #+#             */
/*   Updated: 2024/10/23 11:32:09 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Format.hpp"


int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	
	std::cout << _BOLD << "Animal virtual : " << _END << std::endl;
	std::cout << _GOLD << j->getType() << " " << _END << std::endl;
	std::cout << _ORANGE << i->getType() << " " << _END << std::endl;
	
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	
	delete meta;
	delete j;
	delete i;
	
	std::cout << std::endl;
	std::cout << _BOLD << "Wrong Animal no virtual : " << _END << std::endl;
	
	const WrongAnimal *wrongmeta = new WrongAnimal();
	const WrongAnimal *wrongi = new WrongCat();
	
	std::cout << _BORDEAUX << wrongmeta->getType() << " " << _END << std::endl;
	wrongmeta->makeSound();
	std::cout << _KAKI << wrongi->getType() << " " << _END << std::endl;
	wrongi->makeSound();
	
	delete wrongmeta;
	delete wrongi;
	
	return 0;
}
