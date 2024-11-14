/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookops <tookops@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:20:02 by tookops           #+#    #+#             */
/*   Updated: 2024/11/14 17:53:00 by tookops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>

template <typename T>
void print(const T& element) {
    std::cout  << _BLUE << element << _END << " ";
}

template <typename T>
void increment(T& element) {
    ++element;
}

template <typename T>
void appendExclamation(T& element) {
    element += " !";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    std::string strArray[] = {"Hello", "world", "from", "iter"};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};

    std::cout << "Printing int array: ";
    iter(intArray, 5, print<int>);
    std::cout << "\nPrinting string array: ";
    iter(strArray, 4, print<std::string>);
    std::cout << "\nPrinting double array: ";
    iter(doubleArray, 4, print<double>);

	std::cout << "\n\nAppending exclamation mark to string array: ";
	iter(strArray, 4, appendExclamation<std::string>);
	iter(strArray, 4, print<std::string>);
    
    std::cout << "\n\nIncrementing int array: ";
    iter(intArray, 5, increment<int>);
    iter(intArray, 5, print<int>);

    std::cout << "\n\nIncrementing double array: ";
    iter(doubleArray, 4, increment<double>);
    iter(doubleArray, 4, print<double>);

    std::cout << std::endl;
    return 0;
}
