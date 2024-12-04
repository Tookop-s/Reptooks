/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:39:38 by anferre           #+#    #+#             */
/*   Updated: 2024/12/04 14:25:38 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <utility>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &src);
	~PmergeMe();

	PmergeMe &operator=(const PmergeMe &src);

	void sort(std::vector<int> &vec);
	void sort(std::deque<int> &deq);

private:
	void merge(std::vector<int> &vec, std::vector<int> &bigVec, std::vector<int> &smallVec, std::vector<int> &alone, std::pair<int, int> &smallestPair);
	void merge(std::deque<int> &deq, std::deque<int> &bigDeq, std::deque<int> &smallDeq, std::deque<int> &alone, std::pair<int, int> &smallestPair);
};

template <typename C>
void printContainer(C &c, std::string const &str)
{
	std::cout << str << " : ";
	size_t count = 0;
	for (typename C::iterator it = c.begin(); it != c.end(); it++)
	{
		if (c.size() <= 5 || (c.size() > 5 && count < 4))
			std::cout << *it << " ";
		++count;
	}
	if (c.size() > 5)
		std::cout << "[...]";
	std::cout << std::endl;
}

// template <typename It>
// bool isSorted(It begin, It end)
// {
// 	if (begin == end)
// 		return true;
// 	It next = begin;
// 	while (++next != end)
// 	{
// 		if (*next < *begin)
// 			return false;
// 		++begin;
// 	}
// 	return true;
// }

#endif