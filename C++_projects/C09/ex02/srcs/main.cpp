/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:39:33 by anferre           #+#    #+#             */
/*   Updated: 2024/12/04 14:26:29 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>


void testSort(std::vector<int> &vec)
{
	std::deque<int> deq(vec.begin(), vec.end());
	PmergeMe pmm;

	printContainer(vec, "Before");

	std::clock_t startVec = std::clock();
	pmm.sort(vec);
	std::clock_t endVec = std::clock();

	std::clock_t startDeq = std::clock();
	pmm.sort(deq);
	std::clock_t endDeq = std::clock();

	printContainer(deq, "After");

	std::cout << "Time to process a range of " << vec.size() << " elements with std::[vector] : " << 1000.0 * (endVec - startVec) / CLOCKS_PER_SEC << " ms" << std::endl;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::[deque] : " << 1000.0 * (endDeq - startDeq) / CLOCKS_PER_SEC << " ms" << std::endl;

	// if (isSorted(vec.begin(), vec.end()) && isSorted(deq.begin(), deq.end()))
	// 	std::cout << "Sorting is correct." << std::endl;
	// else
	// 	std::cout << "Sorting is incorrect." << std::endl;
}

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
	testSort(vec);
	return 0;
}
