/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:11:59 by anferre           #+#    #+#             */
/*   Updated: 2024/09/20 15:36:12 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) {
	cur_index = 0;
	return;
}

PhoneBook::PhoneBook (const PhoneBook& other) {
	for (int i = 0; i <= 8; i++)
		contacts[i] = other.contacts[i];
}

PhoneBook& PhoneBook::operator=(const PhoneBook& other) { 
	if (this == &other)
		return *this;
	for (int i = 0; i < 8; i++)
		contacts[i] = other.contacts[i];
	return *this;
}

PhoneBook::~PhoneBook(void) {
	return;
}

void PhoneBook::add_contact(void){
	Contact new_contact;
	
	new_contact.set_nickname(&new_contact);
	new_contact.set_first_name(&new_contact);
	new_contact.set_last_name(&new_contact);
	new_contact.set_phone_number(&new_contact);
	new_contact.set_darkest_secret(&new_contact);
	
	this->contacts[cur_index] = new_contact;
	this->cur_index = (this->cur_index + 1) % 8;
	
	return;
}

void printTab(const Contact *contacts) {

	std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "│     Index│ FirstName│  LastName|  Nickname|" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (!contacts[i].get_first_name().empty())
		{
			std::cout << "|" << std::setw(10) << i << "|";
			if (contacts[i].get_first_name().length() > 10)
				std::cout << std::setw(9) << contacts[i].get_first_name().substr(0, 9) << ".|";
			else
				std::cout << std::setw(10) << contacts[i].get_first_name() << "|";
			if (contacts[i].get_last_name().length() > 10)
				std::cout << std::setw(9) << contacts[i].get_last_name().substr(0, 9) << ".|";
			else
				std::cout << std::setw(10) << contacts[i].get_last_name() << "|";
			if (contacts[i].get_nickname().length() > 10)
				std::cout << std::setw(9) << contacts[i].get_nickname().substr(0, 9) << ".|" << std::endl;
			else
				std::cout << std::setw(10) << contacts[i].get_nickname() << "|" << std::endl;
		}
		if (i <= 6 && !contacts[i + 1].get_first_name().empty())
			std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	}
	 std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
}

void	printContact(const Contact *contacts) {
	int index;
	std::string input;
	std::cout << "Enter the index of the contact you want to see : ";
	while (1)
	{
		if (!std::getline(std::cin, input))
			exit(1);
		std::stringstream ss(input);
		if (!(ss >> index) || (index < 0 || index > 7))
			std::cout << "Invalid index, try again" << std::endl;
		else
			break;
	}
	if (contacts[index].get_first_name().empty())
	{
		std::cout << "No contact at this index" << std::endl;
		return;
	}
	else
	{
		std::cout << "First Name : " << contacts[index].get_first_name() << std::endl;
		std::cout << "Last Name : " << contacts[index].get_last_name() << std::endl;
		std::cout << "Nickname : " << contacts[index].get_nickname() << std::endl;
		std::cout << "Phone Number : " << contacts[index].get_phone_number() << std::endl;
		std::cout << "Darkest Secret : " << contacts[index].get_darkest_secret() << std::endl;
	}
}

void PhoneBook::search_contact(void) {

	if (contacts[0].get_first_name().empty())
	{
		std::cout << "No contacts available" << std::endl;
		return;
	}
	printTab(contacts);
	printContact(contacts);
}
