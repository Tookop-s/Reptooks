/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:00:18 by anferre           #+#    #+#             */
/*   Updated: 2024/10/23 11:32:48 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {
	
	public : 
		Cat( void );
		~Cat( void );
		Cat( Cat const & src );
		Cat & operator=( Cat const & rhs );

		void makeSound( void ) const;
		std::string getType( void ) const;

	protected :
		std::string _type;
};

#endif