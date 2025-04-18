/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:52:33 by anferre           #+#    #+#             */
/*   Updated: 2024/09/30 13:42:25 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {

	public:

		HumanB(const std::string& name );
		~HumanB( void );

		void setWeapon( Weapon& weapon);
		void attack( void ) const;

	private : 
	
		std::string _name;
		Weapon* _weapon;
};

#endif