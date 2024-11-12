/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:53:53 by anferre           #+#    #+#             */
/*   Updated: 2024/11/12 13:56:55 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <stdint.h>

void testRegular(Data data)
{
	std::cout << "Orginal Data Address: " << &data << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	Data *ptr = Serializer::deserialize(raw);

	std::cout << "Deserialized Data Address: " << ptr << std::endl;

	std::cout << "Data: " << ptr->s1 << " " << ptr->n << std::endl;

	if (ptr == &data)
		std::cout << "Address Match !" << std::endl;
	else
		std::cout << "Address do not match... " << std::endl;
}

void testNullptr()
{
	uintptr_t raw = Serializer::serialize(0);
	Data *ptr = Serializer::deserialize(raw);

	if (ptr == 0)
		std::cout << "Nullptr test passed !" << std::endl;
	else
		std::cout << "Nullptr test failed..." << std::endl;
}

void testUninitialized()
{
	Data data;
	uintptr_t raw = Serializer::serialize(&data);
	Data *ptr = Serializer::deserialize(raw);

	if (ptr == &data)
		std::cout << "Uninitialized test passed !" << std::endl;
	else
		std::cout << "Uninitialized test failed..." << std::endl;
}

void testConstData()
{
	const Data data = {"Hello", 42};
	uintptr_t raw = Serializer::serialize(const_cast<Data *>(&data));
	Data *ptr = Serializer::deserialize(raw);

	if (ptr == &data)
		std::cout << "Const Data test passed !" << std::endl;
	else
		std::cout << "Const Data test failed..." << std::endl;
}

int main()
{
	Data data;
	data.s1 = "Hello";
	data.n = 42;

	testRegular(data);
	testNullptr();
	testUninitialized();
	testConstData();

	return 0;
}
