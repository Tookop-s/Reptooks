/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:27:49 by anferre           #+#    #+#             */
/*   Updated: 2024/09/26 15:03:03 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <climits>


int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}

// int main( void ) {
// Fixed a;
// Fixed const b( Fixed( 42.05f ) * Fixed( 2 ) );
// Fixed c( Fixed( 42.05f ) / Fixed( 2 ) );
// Fixed d( Fixed( 42.05f ) + Fixed( 2 ) );
// Fixed e( Fixed( 42.05f ) - Fixed( 2 ) );
// // Fixed f( Fixed( 5.05f ) / Fixed( 0 ) ); //core dumped allowed by the subject
// std::cout << "b -> " << b << std::endl;
// std::cout << "c -> " << c << std::endl;
// std::cout << "d -> " << d << std::endl;
// std::cout << "e -> " << e << std::endl;
// std::cout << "a -> " << a << std::endl;
// std::cout << "a -> " << ++a << std::endl;
// std::cout << "a -> " << a << std::endl;
// std::cout << "a -> " << a++ << std::endl;
// std::cout << "a -> " << a << std::endl;
// std::cout << "c -> " << c << std::endl;
// std::cout << "c -> " << c-- << std::endl;
// std::cout << "c -> " << c << std::endl;
// std::cout << "c -> " << --c << std::endl;
// std::cout << "c -> " << c << std::endl;
// std::cout << "max a " << a << " b -> " << b << " res -> " << Fixed::max( a, b ) << std::endl;
// std::cout << "min a " << a << " b -> " << b << " res -> " << Fixed::min( a, b ) << std::endl;
// std::cout << "max c " << c << " d -> " << d << " res -> " << Fixed::max( c, d ) << std::endl;
// return 0;
// }

//smallest representable number is epsilon = 0.00390625 in Q24.8 format
