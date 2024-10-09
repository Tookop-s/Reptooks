/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:22:05 by anferre           #+#    #+#             */
/*   Updated: 2024/10/03 14:59:01 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	
	Fixed const x = point.getX();
	Fixed const y = point.getY();
	Fixed const xa = a.getX();
	Fixed const ya = a.getY();
	Fixed const xb = b.getX();
	Fixed const yb = b.getY();
	Fixed const xc = c.getX();
	Fixed const yc = c.getY();

	//cross product (point, a, b) : 
	Fixed const a1 = (x - xa) * (yb - ya) - (xb - xa) * (y - ya);
	//cross product (point, b, c)
	Fixed const a2 = (x - xb) * (yc - yb) - (xc - xb) * (y - yb);
	//cross product (point, c, a)
	Fixed const a3 = (x - xc) * (ya - yc) - (xa - xc) * (y - yc);

	if (a1 > 0 && a2 > 0 && a3 > 0)
		return true;
	if (a1 < 0 && a2 < 0 && a3 < 0)
		return true;
	return false;
}

//https://www.notion.so/C-1049a7fe5c91804fa04fe409dd69a3cb?pvs=4#10d9a7fe5c91805bb736d67f735abafc
