/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:00:18 by anferre           #+#    #+#             */
/*   Updated: 2024/10/21 14:12:20 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
	
	public : 
		Cat( void );
		~Cat( void );
		Cat( Cat const & src );
		Cat & operator=( Cat const & rhs );

		void makeSound( void ) const;
		std::string getType( void ) const;
		void setIdea(std::string idea, int index);
		std::string getIdea(int index) const;
	protected :
		std::string _type;
	private : 
		Brain* _brain;
};

#endif