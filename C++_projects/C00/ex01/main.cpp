/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:25:13 by anferre           #+#    #+#             */
/*   Updated: 2024/09/20 15:38:34 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <iostream>
#include <string.h>
#include <limits>
#include <cstdlib>


std::string capitalize(std::string& str){
	for(std::string::size_type i = 0; i < str.size(); ++i)
		str[i] = std::toupper(static_cast<unsigned char>(str[i]));
	return str;
}

int main(){
	PhoneBook rep;
	std::string command;
	
	std::cout << "Welcome to the phonebook enter a command : " ;
	
	while(std::getline(std::cin, command) && !(capitalize(command) == "EXIT"))
	{
		command = capitalize(command);
		if (command == "ADD")
			rep.add_contact();
		else if (command == "SEARCH")
			rep.search_contact();
		else
			std::cout << "Invalid command" << std::endl;
		std::cout << "Enter a command : ";
	}
	return 0;	
}

