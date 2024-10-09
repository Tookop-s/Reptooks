/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:57:44 by anferre           #+#    #+#             */
/*   Updated: 2024/10/09 13:34:56 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include "Format.hpp"

class ScavTrap : public ClapTrap
{
	public :
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const & src );
		~ScavTrap( void );

		ScavTrap & operator=( ScavTrap const & rhs );

		void	attack( std::string const & target );
		void	guardGate();
};

#endif