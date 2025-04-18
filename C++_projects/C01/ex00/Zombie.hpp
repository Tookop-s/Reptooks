/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:23:16 by anferre           #+#    #+#             */
/*   Updated: 2024/09/30 14:09:51 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

#ifndef DEBUG
# define DEBUG true
#endif

class Zombie {
	
	public :
	
		Zombie( void );
		Zombie( std::string name );
		~Zombie( void );

		void announce( void);
	
	private:
		std::string _name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
