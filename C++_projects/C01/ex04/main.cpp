/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:50:01 by anferre           #+#    #+#             */
/*   Updated: 2024/09/24 11:06:31 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	ft_extractReplace(std::ofstream& outputfile, const std::string& s1, const std::string& s2, size_t& pos, std::ifstream& file)
{
	std::string temp;
	std::string content;

	while (std::getline(file, temp))
	{
		content += temp + "\n";
	}
	file.close();
	while ((pos = content.find(s1, pos)) != std::string::npos)
	{
		content = content.substr(0, pos) + s2 + content.substr(pos + s1.length());
		pos += s2.length();
	}
	outputfile << content;
	outputfile.close();
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return 1;
	}
	else
	{
		std::string filename = argv[1];
		std::string s1 = argv[2];
		std::string s2 = argv[3];
		std::ifstream file(argv[1]);
		size_t pos = 0;
	
		if (s1.empty())
		{
			std::cout << "Empty string" << std::endl;
			return 1;
		}
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
		ft_extractReplace(outputfile, s1, s2, pos, file);
	}
	return 0;
}