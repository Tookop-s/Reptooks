/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:25:13 by anferre           #+#    #+#             */
/*   Updated: 2024/09/19 13:08:30 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <iostream>
#include <cstring>
#include <string.h>
#include <limits>


char *capitalize(char *str){
	for(int i = 0; str[i] != '\0'; i++)
		str[i] = toupper(str[i]);
	return str;
}

int main(){
	PhoneBook rep;
	char command[11];
	
	std::cout << "Welcome to the phonebook enter a command" << std::endl;
	for(;std::cin.getline(command, 11) && strcmp(capitalize(command), "EXIT") != 0;)
	{
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			if (strcmp(capitalize(command), "ADD") == 0)
				rep.add_contact();
			else if (strcmp(capitalize(command), "SEARCH") == 0)
				std::cout << "search" << std::endl;
			else
				std::cout << "Invalid command" << std::endl;
		}
		std::cout << "Enter a command" << std::endl;
	}
	return 0;	
}