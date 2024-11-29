/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:39:56 by anferre           #+#    #+#             */
/*   Updated: 2024/11/29 16:29:00 by anferre          ###   ########.fr       */
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
	size_t i = 0;
	size_t j = 0;
	int k = 0;
	while (i < left.size() && j < right.size())
	{
		if (left[i] < right[j])
			vec[k++] = left[i++];
		else
			vec[k++] = right[j++];
	}
	while (i < left.size())
		vec[k++] = left[i++];
	while (j < right.size())
		vec[k++] = right[j++];
}

// use iterators to gain in speed
void PmergeMe::merge(std::deque<int> &deq, std::deque<int> &left, std::deque<int> &right)
{
	std::deque<int>::iterator leftIt = left.begin();
	std::deque<int>::iterator rightIt = right.begin();
	std::deque<int>::iterator deqIt = deq.begin();

	while (leftIt != left.end() && rightIt != right.end())
	{
		if (*leftIt < *rightIt)
			*deqIt++ = *leftIt++;
		else
			*deqIt++ = *rightIt++;
	}
	while (leftIt != left.end())
		*deqIt++ = *leftIt++;
	while (rightIt != right.end())
		*deqIt++ = *rightIt++;
}
