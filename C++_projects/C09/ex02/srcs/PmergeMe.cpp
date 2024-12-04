/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:39:56 by anferre           #+#    #+#             */
/*   Updated: 2024/12/04 14:12:04 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*group elements into pairs
divide in two list of elements
recursive sort  until two element list or one elemen return
merge list one and two*/

/*For std::vector:
Use direct indexing and leverage random access for efficient sorting and merging.

For std::deque:
Still supports random access but may have slightly different behavior. You might want to take into account the different performance trade-offs compared to std::vector.
*/

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	(void)src;
	return *this;
}

void PmergeMe::sort(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return;
	std::vector<int> bigVec;
	std::vector<int> smallVec;
	bigVec.reserve(vec.size() / 2);
	smallVec.reserve(vec.size() / 2);
	std::vector<std::pair<int, int> > pairs;
	if (vec[0] > vec[1])
		pairs.push_back(std::make_pair(vec[0], vec[1]));
	else
		pairs.push_back(std::make_pair(vec[1], vec[0]));
	for (size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		if (i == vec.size() || i + 1 == vec.size())
			break;
		if (vec[i] > vec[i + 1])
		{
			smallVec.push_back(vec[i + 1]);
			bigVec.push_back(vec[i]);
			if (pairs.back().first > vec[i])
				pairs.back() = std::make_pair(vec[i], vec[i + 1]);
		}
		else
		{
			smallVec.push_back(vec[i]);
			bigVec.push_back(vec[i + 1]);
			if (pairs.back().first > vec[i + 1])
				pairs.back() = std::make_pair(vec[i + 1], vec[i]);
		}
	}
	std::vector<int> alone;
	if (vec.size() % 2)
		alone.push_back(vec.back());
	sort(bigVec);
	merge(vec, bigVec, smallVec, alone, pairs.front());
}

// use iterators to avoid reallocation and gain in speed
void PmergeMe::sort(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return;
	std::deque<int> bigDeq;
	std::deque<int> smallDeq;
	std::deque<std::pair<int, int> > pairs; // first element is the big one
	if (deq[0] > deq[1])
		pairs.push_back(std::make_pair(deq[0], deq[1]));
	else
		pairs.push_back(std::make_pair(deq[1], deq[0]));
	for (std::deque<int>::iterator it = deq.begin(); it + 1 != deq.end(); it += 2)
	{
		if (it == deq.end() || it + 1 == deq.end())
			break;
		if (*it > *(it + 1))
		{
			smallDeq.push_back(*(it + 1));
			bigDeq.push_back(*it);
			if (pairs.back().first > *it)
				pairs.back() = std::make_pair(*(it), *(it + 1));
		}
		else
		{
			smallDeq.push_back(*it);
			bigDeq.push_back(*(it + 1));
			if (pairs.back().first > *(it + 1))
				pairs.back() = std::make_pair(*(it + 1), *it);
		}
	}
	std::deque<int> alone;
	if (deq.size() % 2)
		alone.push_back(deq.back());
	sort(bigDeq);
	merge(deq, bigDeq, smallDeq, alone, pairs.front());
}

void PmergeMe::merge(std::vector<int> &vec, std::vector<int> &bigVec, std::vector<int> &smallVec, std::vector<int> &alone, std::pair<int, int> &smallestPair)
{
	vec = bigVec;
	std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), smallestPair.second);
	vec.insert(it, smallestPair.second);
	for (size_t i = 0; i < smallVec.size(); i++)
	{
		if (smallVec[i] == smallestPair.second)
			continue;
		std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), smallVec[i]);
		vec.insert(it, smallVec[i]);
	}
	if (!alone.empty())
	{
		std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), alone[0]);
		vec.insert(it, alone[0]);
	}
}

// binary search : lower_bound
void PmergeMe::merge(std::deque<int> &deq, std::deque<int> &bigDeq, std::deque<int> &smallDeq, std::deque<int> &alone, std::pair<int, int> &smallestPair)
{
	deq = bigDeq;
	std::deque<int>::iterator it = std::lower_bound(deq.begin(), deq.end(), smallestPair.second);
	deq.insert(it, smallestPair.second);
	for (std::deque<int>::iterator it = smallDeq.begin(); it != smallDeq.end(); it++)
	{
		if (*it == smallestPair.second)
			continue;
		std::deque<int>::iterator it2 = std::lower_bound(deq.begin(), deq.end(), *it);
		deq.insert(it2, *it);
	}
	if (!alone.empty())
	{
		std::deque<int>::iterator it = std::lower_bound(deq.begin(), deq.end(), alone.front());
		deq.insert(it, alone.front());
	}
}

/*
pair elements compare and split into large ans small keep track of the pairs
recursivey sort the large elements with pairs inside the large and merge with binary search
insert at the beginning the paired smallest element of the smaller large elements keep tack of the pairs with std::vector<std::pair<int, int>>,
add the unpaired element last */