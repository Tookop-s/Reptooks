/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:00:20 by anferre           #+#    #+#             */
/*   Updated: 2024/10/21 14:12:24 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {

	public:
		Dog(void);
		~Dog(void);
		Dog(Dog const &src);
		Dog &operator=(Dog const &rhs);

		void makeSound(void) const;
		std::string getType(void) const;
		void setIdea(std::string idea, int index);
		std::string getIdea(int index) const;

	protected:
		std::string _type;

	private:
		Brain *_brain;
};

#endif
