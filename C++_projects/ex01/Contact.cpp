/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:29:04 by anferre           #+#    #+#             */
/*   Updated: 2024/09/19 20:27:45 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <iostream>
#include <istream>
#include <string>
#include <limits>


Contact::Contact (void) {  //need to init the 8 to 0 and then modify in a member function 
	return;
}

Contact::Contact (const Contact& other) { 
	this->nickname = other.nickname;
	this->first_name = other.first_name;
	this->last_name = other.last_name;
	this->phone_number = other.phone_number;
	this->darkest_secret = other.darkest_secret;
}

Contact& Contact::operator=(const Contact& other){
	if (this == &other)
		return *this;
	this->nickname = other.nickname;
	this->first_name = other.first_name;
	this->last_name = other.last_name;
	this->phone_number = other.phone_number;
	this->darkest_secret = other.darkest_secret;
	return *this;
}

Contact::~Contact (void) { 
	return;
}

bool onlySpaces(std::string& str) {
	for (std::string::size_type i = 0; i < str.length(); i++)
	{
		if (!std::isspace(static_cast<unsigned char>(str[i])))
			return false;
	}
	return true;
}

bool isValidString(std::string& str) {
	return str.length() > 0 && str.length() <= 10 && !onlySpaces(str);
}

void Contact::set_nickname(Contact *contact) {
	std::string nickname;
		std::cout << "what is your Nickname ? (max 10 characters):" << std::endl;
	std::getline(std::cin, nickname);
	for(; isValidString(nickname) || std::cin.fail();)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid Nickname try again :" << std::endl;
		std::getline(std::cin, nickname);
	}
	contact->nickname = nickname;
	return;
}

void Contact::set_first_name(Contact *contact) {
	std::string first_name;
		std::cout << "what is your first_name ? (max 10 characters):" << std::endl;
	std::getline(std::cin, first_name);
	for(; first_name[0] == '\0' || std::cin.fail();)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid first_name try again :" << std::endl;
		std::getline(std::cin, first_name);
	}
	contact->first_name = first_name;
	return;
}

void Contact::set_last_name(Contact *contact) {
	std::string last_name;
		std::cout << "what is your last_name ? (max 10 characters):" << std::endl;
	std::getline(std::cin, last_name);
	for(; last_name[0] == '\0' || std::cin.fail();)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid last_name try again :" << std::endl;
		std::getline(std::cin, last_name);
	}
	contact->last_name = last_name;
	return;
}

void Contact::set_phone_number(Contact *contact) {
	std::string phone_number;
		std::cout << "what is your phone_number ? (max 10 characters):" << std::endl;
	std::getline(std::cin, phone_number);
	for(; phone_number[0] == '\0' || std::cin.fail();)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid phone_number try again :" << std::endl;
		std::getline(std::cin, phone_number);
	}
	contact->phone_number = phone_number;
	return;
}

void Contact::set_darkest_secret(Contact *contact) {
	std::string darkest_secret;
		std::cout << "what is your darkest_secret ? (max 10 characters):" << std::endl;
	std::getline(std::cin, darkest_secret);
	for(; darkest_secret[0] == '\0' || std::cin.fail();)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid darkest_secret try again :" << std::endl;
		std::getline(std::cin, darkest_secret);
	}
	contact->darkest_secret = darkest_secret;
	return;
}
