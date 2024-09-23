/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:50:01 by anferre           #+#    #+#             */
/*   Updated: 2024/09/23 18:22:00 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return 1;
	}
	else { 
		std::string filename = argv[1];
		std::string s1 = argv[2];
		std::string s2 = argv[3];
		std::ifstream file(argv[1]);
		std::string temp;
		std::string content;
		size_t pos = 0;

		if (!file)
		{
			std::cout << "error openning te file" << argv[1] << std::endl;
			return 1;
		}
		std::ofstream outputfile((filename + ".replace").c_str());
		if (!outputfile)
		{
			std::cout << "error creating the output file" << argv[1] << ".replace" << std::endl;
			return 1;
		}
		while(std::getline(file, temp)) {
			content += temp + "\n";
		}
		while ((pos = content.find(s1, pos)) != std::string::npos) {
			content = content.substr(0, pos) + s2 + content.substr(pos + s1.length());
			pos += s2.length();
		}
		outputfile << content;
		file.close();
		outputfile.close();
	}
	return 0;
}