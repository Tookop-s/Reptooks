/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:32:20 by anferre           #+#    #+#             */
/*   Updated: 2024/10/18 14:52:07 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	
	public : 
	
		WrongCat( void );
		~WrongCat( void );
		WrongCat( WrongCat const & src );
		WrongCat & operator=( WrongCat const & rhs );

		void makeSound( void ) const;
		std::string getType( void ) const;

	protected : 

		std::string _type;
};

#endif