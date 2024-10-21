/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:11:59 by anferre           #+#    #+#             */
/*   Updated: 2024/10/21 15:58:24 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const & src);
		Ice & operator=(Ice const & rhs);
		virtual ~Ice();

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif