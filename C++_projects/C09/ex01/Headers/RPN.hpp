/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:56:02 by anferre           #+#    #+#             */
/*   Updated: 2024/11/28 16:43:54 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
public:
	RPN(std::string const &input);
	RPN(RPN const &src);
	~RPN();
	
	RPN &operator=(RPN const &rhs);

	void add();
	void sub();
	void mul();
	void div();

private:
	RPN();
	std::stack<int> _stack;
};

#endif