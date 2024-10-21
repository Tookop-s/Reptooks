/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:11:56 by anferre           #+#    #+#             */
/*   Updated: 2024/10/21 15:58:18 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const & src);
		Cure & operator=(Cure const & rhs);
		virtual ~Cure();

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif