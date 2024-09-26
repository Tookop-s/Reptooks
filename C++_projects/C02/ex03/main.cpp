/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:01:37 by anferre           #+#    #+#             */
/*   Updated: 2024/09/26 17:19:26 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);


int main(){
	Point a(0, 0);
	Point b(0, 1);
	Point c(1, 0);

	std::cout << "inside the triangle" << std::endl;
	std::cout << std::boolalpha << bsp(a, b, c, Point(0.25, 0.25)) << std::endl;
	std::cout << "on the edge the triangle" << std::endl;
	std::cout << std::boolalpha << bsp(a, b, c, Point(0, 0.5)) << std::endl;
	std::cout << "On the vertex of the triangle" << std::endl;
	std::cout << std::boolalpha << bsp(a, b, c, Point(0, 0)) << std::endl;
	std::cout << "outside  the triangle" << std::endl;
	std::cout << std::boolalpha << bsp(a, b, c, Point(1.5, 1.5)) << std::endl;
	return 0;
}

// https://www.notion.so/C-1049a7fe5c91804fa04fe409dd69a3cb?pvs=4#10d9a7fe5c9180b886f4d0f4d56c858a
