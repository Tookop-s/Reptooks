/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:22:25 by anferre           #+#    #+#             */
/*   Updated: 2024/10/10 14:10:52 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include "Format.hpp"

#ifndef DEBUG
# define DEBUG true
# define INFO true
#endif

class ClapTrap {
	
	public:
	
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const & src );
		~ClapTrap( void );

		ClapTrap & operator=( ClapTrap const & rhs );

		void        attack( std::string const & target );
		void        takeDamage( unsigned int amount );
		void        beRepaired( unsigned int amount );

	private:
	
		std::string 	_name;
		unsigned int 	_hitPoints;
		unsigned int 	_energyPoints;
		unsigned int 	_attackDamage;

};


#endif