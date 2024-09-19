/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:11:59 by anferre           #+#    #+#             */
/*   Updated: 2024/09/19 13:04:34 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <iostream>
#include <cstring>

PhoneBook::PhoneBook(void) {
	Contact contacts[8];
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
	// new_contact.set_first_name(&new_contact);
	// new_contact.set_last_name(&new_contact);
	// new_contact.set_phone_number(&new_contact);
	// new_contact.set_darkest_secret(&new_contact);
	
	return;
}