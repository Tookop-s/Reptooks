/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:26:11 by anferre           #+#    #+#             */
/*   Updated: 2024/10/21 14:00:02 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Format.hpp"


// used the dog and cat because copy constructor and assignment operator cannot be virtual
void testcopyassign() {
	
	std::cout << "\nDeep copy tests\n";
	Dog dog;
	Cat cat;
	Cat cat2;

	dog.setIdea("chase the ball", 0);
	cat.setIdea("chase the mouse", 0);

	std::cout << _BOLD << _RED << "Dog idea: " << dog.getIdea(0) << _END << std::endl;
	std::cout << _BOLD << _RED << "Cat idea: " << cat.getIdea(0) << _END << std::endl;

	std::cout << "\nCopy constructor test\n";
	Dog dog2(dog);
	std::cout << _BOLD << _RED << "Dog2 copied idea: " << dog2.getIdea(0) << _END << std::endl;

	dog.setIdea("chase the cat", 0);
	std::cout << _BOLD << _RED << "Dog modified idea: " << dog.getIdea(0) << _END << std::endl;
	std::cout << _BOLD << _RED << "Dog2 idea (should be chase the ball) :  " << dog2.getIdea(0) << _END << std::endl;

	std::cout << "\nAssignment operator test\n";
	cat2 = cat;
	std::cout << _BOLD << _RED << "Cat2 copied idea: " << cat2.getIdea(0) << _END << std::endl;

	cat.setIdea("chase the dog", 0);
	std::cout << _BOLD << _RED << "Cat modified idea: " << cat.getIdea(0) << _END << std::endl;
	std::cout << _BOLD << _RED << "Cat2 idea (should be chase the mouse) :  " << cat2.getIdea(0) << _END << std::endl
			  << std::endl;
}

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
	for (int i = 0; i < 4; i++)
	{
		delete animals[i];
		std::cout << std::endl;
	}
	testcopyassign();
	return 0;
}
