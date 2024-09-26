/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:21:43 by anferre           #+#    #+#             */
/*   Updated: 2024/09/26 17:08:40 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
	public:
		Point( void );
		Point( float const x, float const y );
		Point( Point const & src );
		~Point( void );

		Fixed const getX( void ) const;
		Fixed const getY( void ) const;

		Point & operator=( Point const & rhs );

	private:
		Fixed const x;
		Fixed const y;
};

#endif