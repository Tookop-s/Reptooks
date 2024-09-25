/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:33:59 by anferre           #+#    #+#             */
/*   Updated: 2024/09/25 13:47:08 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	
	public:

		Fixed( void );
		Fixed( Fixed const & src );
		~Fixed( void );
		Fixed & operator=( Fixed const & src );
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		
	private:
	
		int _value;
		static const int _bits = 8;
};


#endif