/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:17:14 by anferre           #+#    #+#             */
/*   Updated: 2024/10/18 22:48:21 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include "Format.hpp"

#define DEBUG true

class Brain
{
	public:
	
		Brain( void );
		Brain(const Brain &src);
		Brain &operator=(const Brain &rhs);
		~Brain( void );
	
		std::string ideas[100];
};

#endif