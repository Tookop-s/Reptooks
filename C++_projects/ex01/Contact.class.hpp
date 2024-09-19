/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:11:54 by anferre           #+#    #+#             */
/*   Updated: 2024/09/19 20:09:39 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
	
	public : 
	
	Contact(void);
	Contact(const Contact& other);
	Contact& operator=(const Contact& other);
	~Contact(void);
	void set_nickname(Contact *contact);
	void set_first_name(Contact *contact);
	void set_last_name(Contact *contact);
	void set_phone_number(Contact *contact);
	void set_darkest_secret(Contact *contact);

	private : 
	
	std::string nickname;
	std::string first_name;
	std::string last_name;
	std::string phone_number;
	std::string darkest_secret;
};

#endif