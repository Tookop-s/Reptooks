/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:17:14 by anferre           #+#    #+#             */
/*   Updated: 2024/10/18 23:02:22 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include "Format.hpp"

#ifndef DEBUG
# define DEBUG true
# define INFO true
#endif

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