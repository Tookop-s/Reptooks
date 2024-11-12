/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:24:55 by anferre           #+#    #+#             */
/*   Updated: 2024/11/12 14:13:39 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Format.hpp"

class Base
{
	public:
		virtual ~Base() {};
};


class A : public Base {};

class B : public Base {};

class C : public Base {};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif