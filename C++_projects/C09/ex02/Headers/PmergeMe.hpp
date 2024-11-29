/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:39:38 by anferre           #+#    #+#             */
/*   Updated: 2024/11/29 16:18:22 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

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
	void merge(std::vector<int> &vec, std::vector<int> &left, std::vector<int> &right);
	void merge(std::deque<int> &deq, std::deque<int> &left, std::deque<int> &right);
};

#endif