/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:29:00 by anferre           #+#    #+#             */
/*   Updated: 2024/09/19 12:11:20 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.class.hpp"

class PhoneBook {
	public : 
	
	Contact contacts[8];
	PhoneBook(void);
	PhoneBook(const PhoneBook&);
	PhoneBook& operator=(const PhoneBook& other);
	~PhoneBook(void);
	void add_contact(void);
	
};

#endif


/* 2 class phonebook and contact 
phone book = repertory with a tab of contact -> 8 contact max replace oldest one if above 
no dynamique allocation 
contact is a contact in the repertory

the repertory is an instance of the phonebook class 
same for the object contact that must be an instance of the contact class 

empty repertory at launch 
commands : ADD SEARCH EXIT

ADD : fill one by one the info of the new contact it is then added to the repertory
following infos : first name, last name, nickname, phone number, darkest secret
cannot be empty 


SEARCH : print the required contact
print the contacts under a list of 4 columns index | fisrt name | last name  | nickname
each column must be 10 char wide separated by a | , text aligned to the right, 
if too big truncate it and replace the last char by a dot . 
then ask for the index, handle incorrect formats, otherwise print each info on a single line

functions -> setw next value printed occupies at least nb char but still need to truncate if longer than the specified nb
			std::rigth (alignement)

EXIT : leave the program

anything else is ignored 
*/