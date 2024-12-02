/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:39:33 by anferre           #+#    #+#             */
/*   Updated: 2024/12/02 16:22:34 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc <= 2)
	{
		std::cout << "Please provide a list of numbers to sort" << std::endl;
		return 1;
	}

	std::vector<int> vec;
	int tmp;
	for (int i = 1; i < argc; i++)
	{
		tmp = atoi(argv[i]);
		if (tmp > 0)
			vec.push_back(tmp);
		else
		{
			std::cout << "Please provide only positive numbers" << std::endl;
			return 1;
		}
	}
	std::deque<int> deq(vec.begin(), vec.end());
	PmergeMe pmm;
	std::cout << "Before : ";
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec.size() <= 5 || (vec.size() > 5 && i < 4))
			std::cout << vec[i] << " ";
	}
	if (vec.size() > 5)
		std::cout << "[...]";
	std::cout << std::endl;
	std::clock_t startVec = std::clock();
	pmm.sort(vec);
	std::clock_t endVec = std::clock();
	std::clock_t startDeq = std::clock();
	pmm.sort(deq);
	std::clock_t endDeq = std::clock();
	std::cout << "After : ";
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec.size() <= 5 || (vec.size() > 5 && i < 4))
			std::cout << vec[i] << " ";
	}
	if (vec.size() > 5)
		std::cout << "[...]";
	std::cout << std::endl;
	std::cout << "Time to process a range of 5 elements with std::[vector] : " << 1000.0 * (endVec - startVec) / CLOCKS_PER_SEC << " ms" << std::endl;
	std::cout << "Time to process a range of 5 elements with std::[deque] : " << 1000.0 * (endDeq - startDeq) / CLOCKS_PER_SEC << " ms" << std::endl;
	return 0;
}
