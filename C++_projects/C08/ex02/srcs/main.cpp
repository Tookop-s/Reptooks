/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookops <tookops@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:53:16 by tookops           #+#    #+#             */
/*   Updated: 2024/11/18 18:15:12 by tookops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

void testStack()
{
	std::cout << _GOLD << "MutantStack:" << _END << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Top : " << _BLUE << mstack.top() << _END << std::endl;
	mstack.pop();
	std::cout << "new Top : " << _BLUE << mstack.top() << _END << std::endl;
	std::cout << "Size : " << _BLUE << mstack.size() << _END << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Stack: ";
	while (it != ite)
	{
		std::cout << _BLUE << *it << _END << " ";
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);
	std::cout << "Size of std::stack s: " << _BLUE << s.size() << _END << std::endl;
	std::cout << "Size of MutantStack mstack: " << _BLUE << mstack.size() << _END << std::endl;
	std::cout << "Popping elements from std::stack s: ";
	while (!s.empty())
	{
		std::cout << _BLUE << s.top() << _END << " ";
		s.pop();
	}
	std::cout << std::endl;
}

void testList()
{
	std::cout << _GOLD << "List:" << _END << std::endl;
	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << "Top : " << _BLUE << mlist.back() << _END << std::endl;
	mlist.pop_back();
	std::cout << "new Top : " << _BLUE << mlist.back() << _END << std::endl;
	std::cout << "Size : " << _BLUE << mlist.size() << _END << std::endl;

	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);

	std::list<int>::iterator it = mlist.begin();
	std::list<int>::iterator ite = mlist.end();

	++it;
	--it;

	std::cout << "List: ";
	while (it != ite)
	{
		std::cout << _BLUE << *it << _END << " ";
		++it;
	}
	std::cout << std::endl;
}

void testLargeData()
{
	std::cout << _GOLD << "Testing with Large Data:" << _END << std::endl;
	MutantStack<int> mstack;

	for (int i = 0; i < 10000; ++i)
	{
		mstack.push(i);
	}

	std::cout << "Size: " << _BLUE << mstack.size() << _END << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "First 10 elements: ";
	for (int i = 0; i < 10 && it != ite; ++i, ++it)
		std::cout << _BLUE << *it << _END << " ";
	std::cout << std::endl;
}

void testConstIterator()
{
	std::cout << _GOLD << "Testing const_iterator:" << _END << std::endl;

	MutantStack<int> mstack;
	for (int i = 1; i <= 5; ++i)
		mstack.push(i * 10);
	const MutantStack<int> constMstack(mstack);
	
	MutantStack<int>::const_iterator it = constMstack.begin();
	MutantStack<int>::const_iterator ite = constMstack.end();

	std::cout << "Stack elements using const_iterator: ";
	while (it != ite)
	{
		std::cout << _BLUE << *it << _END << " ";
		++it;
	}
	std::cout << std::endl;

	// *it = 50;  // compilation error
}

void testReverseIterator()
{
	std::cout << _GOLD << "Testing reverse_iterator:" << _END << std::endl;

	MutantStack<int> mstack;
	for (int i = 1; i <= 5; ++i)
		mstack.push(i * 10);

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();

	std::cout << "Stack elements in reverse order using reverse_iterator: ";
	while (rit != rite)
	{
		std::cout << _BLUE << *rit << _END << " ";
		++rit;
	}
	std::cout << std::endl;
}

void testConstReverseIterator()
{
	std::cout << _GOLD << "Testing const_reverse_iterator:" << _END << std::endl;

	MutantStack<int> mstack;
	for (int i = 1; i <= 5; ++i)
		mstack.push(i * 10);

	const MutantStack<int> constMstack(mstack);

	MutantStack<int>::const_reverse_iterator rit = constMstack.rbegin();
	MutantStack<int>::const_reverse_iterator rite = constMstack.rend();

	std::cout << "Stack elements in reverse order using const_reverse_iterator: ";
	while (rit != rite)
	{
		std::cout << _BLUE << *rit << _END << " ";
		++rit;
	}
	std::cout << std::endl;

	// *rit = 50;  // compilation error
}

int main()
{
	testStack();
	testList();
	testLargeData();
	testConstIterator();
	testReverseIterator();
	testConstReverseIterator();
	return 0;
}