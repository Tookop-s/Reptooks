/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:00:15 by anferre           #+#    #+#             */
/*   Updated: 2024/10/18 22:19:18 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

#ifndef DEBUG
# define DEBUG true
# define INFO true
#endif

class Animal {

	public : 
	
		Animal( void );
		Animal( Animal const & src );
		Animal & operator=( Animal const & rhs );
		virtual ~Animal( void );

		virtual void makeSound( void ) const;
		virtual std::string getType( void ) const;

	protected : 

		std::string _type;
};



#endif