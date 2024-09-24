/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:11:54 by anferre           #+#    #+#             */
/*   Updated: 2024/09/24 12:44:26 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <istream>
#include <string>
#include <cctype>
#include <limits>
#include <cstdlib>

class Contact {
	
	public : 

	Contact(void);
	Contact(const Contact& other);
	~Contact(void);
	void set_nickname(Contact *contact);
	void set_first_name(Contact *contact);
	void set_last_name(Contact *contact);
	void set_phone_number(Contact *contact);
	void set_darkest_secret(Contact *contact);
	std::string get_nickname() const;
	std::string get_first_name() const;
	std::string get_last_name() const;
	std::string get_phone_number() const;
	std::string get_darkest_secret() const;

	private:

	std::string _first_name;
	std::string _nickname;
	std::string _last_name;
	std::string _phone_number;
	std::string _darkest_secret;
};




#endif