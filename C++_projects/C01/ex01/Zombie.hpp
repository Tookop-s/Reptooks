/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:12:05 by anferre           #+#    #+#             */
/*   Updated: 2024/09/23 16:34:31 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
	
	public :
	

	Zombie( void);
	Zombie( std::string name);
	~Zombie( void);
	void announce( void);
	void setName(std::string name);
	
	private:
		std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif