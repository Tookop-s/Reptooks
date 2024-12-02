/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:39:56 by anferre           #+#    #+#             */
/*   Updated: 2024/12/02 16:38:59 by anferre          ###   ########.fr       */
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

// reserve to avoid reallocation and gain in speed
void PmergeMe::sort(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return;
	std::vector<int> left;
	std::vector<int> right;
	int mid = vec.size() / 2;
	left.reserve(mid);
	right.reserve(vec.size() - mid);
	for (int i = 0; i < mid; i++)
		left.push_back(vec[i]);
	for (size_t i = mid; i < vec.size(); i++)
		right.push_back(vec[i]);
	sort(left);
	merge(vec, left, right);
}

// use iterators to avoid reallocation and gain in speed
void PmergeMe::sort(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return;
	std::deque<int> left(deq.begin(), deq.begin() + deq.size() / 2);
	std::deque<int> right(deq.begin() + deq.size() / 2, deq.end());
	sort(left);
	merge(deq, left, right);
}

void PmergeMe::merge(std::vector<int> &vec, std::vector<int> &left, std::vector<int> &right)
{
	vec = left;
	for (size_t i = 0; i < right.size(); i++)
	{
		std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), right[i]);
		vec.insert(it, right[i]);
	}
}

// use iterators to gain in speed
void PmergeMe::merge(std::deque<int> &deq, std::deque<int> &left, std::deque<int> &right)
{
	deq = left;
	for (std::deque<int>::iterator rightIt = right.begin(); rightIt != right.end(); ++rightIt)
	{
		std::deque<int>::iterator it = std::lower_bound(deq.begin(), deq.end(), *rightIt);
		deq.insert(it, *rightIt);
	}	
}
