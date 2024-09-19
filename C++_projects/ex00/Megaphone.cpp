/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:39:24 by anferre           #+#    #+#             */
/*   Updated: 2024/09/18 13:26:46 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char *argv[]){

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int j = 1; j < argc; j++)
		{
			std::string args = argv[j];
			for (size_t i = 0; i < args.length(); i++)
			{
				if (std::islower(args[i]))
					args[i] = std::toupper(args[i]);
			}
			std::cout << args;
		}
	std::cout << std::endl;
	}
	return 0;
}