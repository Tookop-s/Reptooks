/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:52:31 by anferre           #+#    #+#             */
/*   Updated: 2024/09/30 14:10:16 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {

	public:

		HumanA( const std::string& name, Weapon& weapon );
		~HumanA( void );

		void attack( void ) const;

	private : 
	
		std::string _name;
		Weapon& _weapon;
};

#endif