/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:43:53 by anferre           #+#    #+#             */
/*   Updated: 2024/09/23 16:49:15 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main( void ) {
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Address of the string variable :" << &str << std::endl;
	std::cout << "Address of stringPTR :" << stringPTR << std::endl;
	std::cout << "Address of stringREF :" << &stringREF << std::endl;

	std::cout << "Value of the string variable :" << str << std::endl;
	std::cout << "stringPTR pointing to :" << *stringPTR << std::endl;
	std::cout << "stringREF pointing to :" << stringREF << std::endl;
	return 0;
}