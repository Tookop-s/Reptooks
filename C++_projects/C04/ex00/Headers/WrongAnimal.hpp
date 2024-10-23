/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:31:01 by anferre           #+#    #+#             */
/*   Updated: 2024/10/23 11:32:44 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

#ifndef DEBUG
# define DEBUG true
# define INFO true
#endif

class WrongAnimal {
	
	public : 
		WrongAnimal( void );
		virtual ~WrongAnimal( void );
		WrongAnimal( WrongAnimal const & src );
		WrongAnimal & operator=( WrongAnimal const & rhs );

		void makeSound( void ) const;
		std::string getType( void ) const;

	protected : 
		std::string _type;
};

#endif