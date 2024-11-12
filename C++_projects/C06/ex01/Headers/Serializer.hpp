/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:34:50 by anferre           #+#    #+#             */
/*   Updated: 2024/11/12 12:12:07 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"
#include <iostream>
#include <stdint.h>

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const &copy);
		Serializer &operator=(Serializer const &rhs);
		~Serializer();
	
	public:

		static uintptr_t    serialize(Data *ptr);
		static Data    *deserialize(uintptr_t raw);
};

#endif