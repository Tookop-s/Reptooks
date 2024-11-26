/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookops <tookops@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:07:29 by tookops           #+#    #+#             */
/*   Updated: 2024/11/26 15:59:46 by tookops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


// check file, dates, value and transfert data in the map
// use the value to calculate the total value of the bitcoin on the according date

int main(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
	{
		std::cerr << "Usage: ./bitcoinExchange [filename]" << std::endl;
		return 1;
	}
	
	BitcoinExchange exchange;
	
	// try
	// {
	// 	exchange.processData(argv[1]);
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << "Error: " << e.what() << std::endl;
	// 	return 1;
	// }
}