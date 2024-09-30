/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:10:17 by anferre           #+#    #+#             */
/*   Updated: 2024/09/30 14:01:31 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(){
	Harl harl;

	try
	{
		std::cout << "DEBUG" << std::endl;
		harl.complain("DEBUG");
		std::cout << std::endl;
		std::cout << "INFO" << std::endl;
		harl.complain("INFO");
		std::cout << std::endl;
		std::cout << "WARNING" << std::endl;
		harl.complain("WARNING");
		std::cout << std::endl;
		std::cout << "ERROR" << std::endl;
		harl.complain("ERROR");
		std::cout << std::endl;
		std::cout << "INVALID" << std::endl;
		harl.complain("INVALID");
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}