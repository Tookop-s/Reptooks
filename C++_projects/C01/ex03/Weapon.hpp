/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:52:41 by anferre           #+#    #+#             */
/*   Updated: 2024/09/27 11:31:47 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {

	public:

		Weapon( void );
		Weapon( std::string type );
		~Weapon( void );
		
		void setType( std::string type );
		const std::string& getType( void ) const;
	
	private :
	
		std::string _type;
};

#endif