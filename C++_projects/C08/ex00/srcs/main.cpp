/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookops <tookops@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:26:08 by tookops           #+#    #+#             */
/*   Updated: 2024/11/15 18:50:50 by tookops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	try
	{
		std::cout << _GOLD << "Testing with std::vector<int>" << _END;
		std::vector<int> vec;
		for (int i = 0; i < 5; i++)
		{
			vec.push_back(i + 1);
			std::cout << _BLUE << " " << vec[i] << _END;
		}
		std::cout << std::endl;
		std::cout << "Found value "<< _BLUE << 3 << _END <<" at position: " << _BLUE << std::distance(vec.begin(), easyfind(vec, 3)) << _END << std::endl;

		std::cout << _GOLD << "\nTesting with std::list<int>" << _END;
		std::list<int> lst;
		for (int i = 0; i < 5; i++)
		{
			lst.push_back((i + 1) * 10);
			std::cout << _BLUE << " " << lst.back() << _END;
		}
		std::cout << std::endl;
		std::cout << "Found value "<< _BLUE << 40 << _END <<" at position: " << _BLUE << std::distance(lst.begin(), easyfind(lst, 40)) << _END << std::endl;

		std::cout << _GOLD << "\nTesting with std::deque<int>" << _END;
		std::deque<int> deq;
		for (int i = 0; i < 5; i++)
		{
			deq.push_back((i + 1) * 100);
			std::cout << _BLUE << " " << deq[i] << _END;
		}
		std::cout << std::endl;
		std::cout << "Found value "<< _BLUE << 300 << _END <<" at position: " << _BLUE << std::distance(deq.begin(), easyfind(deq, 300)) << _END << std::endl;

		std::cout << _GOLD << "\nTesting with a value not present" << _END << std::endl;
		std::cout << "Trying to find 99 in vector..." << std::endl;
		easyfind(vec, 99);
	}
	catch (const std::exception &e)
	{
		std::cerr << _RED << e.what() << _END << std::endl;
	}

	try
	{
		std::cout << _GOLD << "\nTesting with an empty container" << _END << std::endl;
		std::vector<int> emptyVec;
		easyfind(emptyVec, 1);
	}
	catch (const std::exception &e)
	{
		std::cerr << _RED << e.what() << _END << std::endl;
	}

	return 0;
}
