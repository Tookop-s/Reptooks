/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:29:04 by anferre           #+#    #+#             */
/*   Updated: 2024/09/25 11:51:06 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact (void) {
	return;
}

Contact::Contact (const Contact& other) { 
	this->_nickname = other._nickname;
	this->_first_name = other._first_name;
	this->_last_name = other._last_name;
	this->_phone_number = other._phone_number;
	this->_darkest_secret = other._darkest_secret;
}

Contact::~Contact (void) { 
	return;
}

bool onlySpaces(std::string& str) {
	for (std::string::size_type i = 0; i < str.size(); i++)
	{
		if (!std::isspace(static_cast<unsigned char>(str[i])))
			return false;
	}
	return true;
}

bool isValidString(std::string& str) {
	return !str.empty() && str.length() > 0  && !onlySpaces(str);
}

bool isValidPhoneNumber(std::string& str) {
	if (str.length() != 10)
		return false;
	for (std::string::size_type i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return false;
	}
	return true;
}

void Contact::set_nickname(Contact *contact) {
	std::string nickname;
		std::cout << "what is your Nickname ? : ";
	if (!std::getline(std::cin, nickname))
		exit(1);
	for(; !isValidString(nickname);)
	{
		std::cout << "Invalid Nickname try again : ";
		if (!std::getline(std::cin, nickname))
			exit(1);
	}
	contact->_nickname = nickname;
	return;
}

void Contact::set_first_name(Contact *contact) {
	std::string first_name;
		std::cout << "what is your first_name ? : ";
	if (!std::getline(std::cin, first_name))
		exit(1);
	while(!isValidString(first_name))
	{
		std::cout << "Invalid first_name try again : ";
		if (!std::getline(std::cin, first_name))
			exit(1);
	}
	contact->_first_name = first_name;
	return;
}

void Contact::set_last_name(Contact *contact) {
	std::string last_name;
		std::cout << "what is your last_name ? : ";
	if (!std::getline(std::cin, last_name))
		exit(1);
	while(!isValidString(last_name))
	{
		std::cout << "Invalid last_name try again : ";
		if (!std::getline(std::cin, last_name))
			exit(1);
	}
	contact->_last_name = last_name;
	return;
}

void Contact::set_phone_number(Contact *contact) {
	std::string phone_number;
		std::cout << "what is your phone_number ? : ";
	if (!std::getline(std::cin, phone_number))
		exit(1);
	while(!isValidString(phone_number) || !isValidPhoneNumber(phone_number))
	{
		std::cout << "Invalid phone_number try again : ";
		if (!std::getline(std::cin, phone_number))
			exit(1);
	}
	contact->_phone_number = phone_number;
	return;
}

void Contact::set_darkest_secret(Contact *contact) {
	std::string darkest_secret;
		std::cout << "what is your darkest_secret ? : ";
	if (!std::getline(std::cin, darkest_secret))
		exit(1);
	while(!isValidString(darkest_secret))
	{
		std::cout << "Invalid darkest_secret try again : ";
		if (!std::getline(std::cin, darkest_secret))
			exit(1);
	}
	contact->_darkest_secret = darkest_secret;
	return;
}

std::string Contact::get_nickname() const {
	return this->_nickname;
}

std::string Contact::get_first_name() const {
	return this->_first_name;
}

std::string Contact::get_last_name() const {
	return this->_last_name;
}

std::string Contact::get_phone_number() const {
	return this->_phone_number;
}

std::string Contact::get_darkest_secret() const {
	return this->_darkest_secret;
}
