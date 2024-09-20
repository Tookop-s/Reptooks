/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:29:00 by anferre           #+#    #+#             */
/*   Updated: 2024/09/20 15:35:26 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.class.hpp"
#include <iomanip>
#include <cstring>
#include <sstream>

class PhoneBook {
	
	public : 
	
	PhoneBook(void);
	PhoneBook(const PhoneBook&);
	PhoneBook& operator=(const PhoneBook& other);
	~PhoneBook(void);
	void add_contact(void);
	void search_contact(void);

	private:

	Contact contacts[8];
	int		cur_index;
	
};

#endif
