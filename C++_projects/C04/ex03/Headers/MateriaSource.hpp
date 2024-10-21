/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:06:47 by anferre           #+#    #+#             */
/*   Updated: 2024/10/21 16:55:23 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	protected :
		AMateria*	_inventory[4];
	public : 
		MateriaSource();
		MateriaSource(MateriaSource const & src);
		MateriaSource & operator=(MateriaSource const & rhs);
		~MateriaSource();
		
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif