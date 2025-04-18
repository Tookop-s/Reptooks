/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:07:29 by tookops           #+#    #+#             */
/*   Updated: 2024/12/04 14:58:32 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


// check file, dates, value and transfert data in the map
// use the value to calculate the total value of the bitcoin on the according date

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./bitcoinExchange [filename]" << std::endl;
		return 1;
	}
	
	BitcoinExchange exchange;
	
	exchange.processData(argv[1]);
	
	return 0;
}