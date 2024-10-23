/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:00:20 by anferre           #+#    #+#             */
/*   Updated: 2024/10/23 11:32:54 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal 
{
	public :
		Dog( void );
		~Dog( void );
		Dog( Dog const & src );
		Dog & operator=( Dog const & rhs );

		void makeSound( void ) const;
		std::string getType( void ) const;

	protected :
		std::string _type;
};

#endif
