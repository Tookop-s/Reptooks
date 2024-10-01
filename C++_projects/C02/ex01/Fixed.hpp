/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:33:59 by anferre           #+#    #+#             */
/*   Updated: 2024/10/01 12:06:19 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	
	public:

		Fixed( void );
		Fixed( int const value );
		Fixed( float const value );
		Fixed( Fixed const & src );
		~Fixed( void );
		Fixed & operator=( Fixed const & src );
		
		float toFloat( void ) const;
		int toInt( void ) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		
	private:
	
		int _value;
		static const int _bits = 8;
};

std::ostream & operator<<( std::ostream & o, Fixed const & src );


#endif