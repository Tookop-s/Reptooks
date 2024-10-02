	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:33:59 by anferre           #+#    #+#             */
/*   Updated: 2024/09/26 11:27:25 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include "Format.hpp"

#ifndef DEBUG
# define DEBUG false
#endif

class Fixed {
	
	public:

		Fixed( void );
		Fixed( int const value );
		Fixed( float const value );
		Fixed( Fixed const & rhs );
		Fixed & operator=( Fixed const & rhs );
		~Fixed( void );

		bool operator>( Fixed const & rhs ) const;
		bool operator<( Fixed const & rhs ) const;
		bool operator>=( Fixed const & rhs ) const;
		bool operator<=( Fixed const & rhs ) const;
		bool operator==( Fixed const & rhs ) const;
		bool operator!=( Fixed const & rhs ) const;
		Fixed operator+( Fixed const & rhs) const;
		Fixed operator-( Fixed const & rhs) const;
		Fixed operator*( Fixed const & rhs) const;
		Fixed operator/( Fixed const & rhs) const;

		Fixed & operator++( void );
		Fixed operator++( int );
		Fixed & operator--( void );
		Fixed operator--( int );

		float toFloat( void ) const;
		int toInt( void ) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		
		static Fixed & max( Fixed & a, Fixed & b );
		static Fixed const & max( Fixed const & a, Fixed const & b );
		static Fixed & min( Fixed & a, Fixed & b );
		static Fixed const & min( Fixed const & a, Fixed const & b );
		
	private:
	
		int _value;
		static const int _bits = 8;
};

std::ostream & operator<<( std::ostream & o, Fixed const & src );


#endif