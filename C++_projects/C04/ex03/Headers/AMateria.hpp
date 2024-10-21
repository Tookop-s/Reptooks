/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:51:35 by anferre           #+#    #+#             */
/*   Updated: 2024/10/21 17:16:09 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>
#include "Format.hpp"

#ifndef DEBUG
# define DEBUG true
#endif

class ICharacter;

class AMateria
{
	protected :
		std::string _type;

	public :
		AMateria();
		AMateria(AMateria const & src);
		AMateria & operator=(AMateria const & rhs);
		virtual ~AMateria();
		
		AMateria(std::string const & type);

		std::string const & getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif