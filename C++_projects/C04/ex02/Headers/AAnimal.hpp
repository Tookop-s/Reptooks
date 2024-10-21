/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:00:15 by anferre           #+#    #+#             */
/*   Updated: 2024/10/21 14:22:17 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

#ifndef DEBUG
# define DEBUG true
# define INFO true
#endif

class AAnimal {

	public : 
	
		AAnimal( void );
		AAnimal( AAnimal const & src );
		AAnimal & operator=( AAnimal const & rhs );
		virtual ~AAnimal( void );

		virtual void makeSound( void ) const = 0;
		virtual std::string getType( void ) const = 0;

	protected : 

		std::string _type;
};



#endif