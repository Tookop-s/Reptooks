#include "Array.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#define MAX_VAL 10

void testIntArray(Array<int> &intArray)
{
	srand(static_cast<unsigned int>(time(0)));
	for (unsigned int i = 0; i < intArray.size(); ++i)
	{
		intArray[i] = rand() % 100;
		std::cout << "intArray[" << i << "] = " << _BLUE << intArray[i] << _END << std::endl;
	}
	std::cout << std::endl;
}

void testCopyConstructorAssignementOperator(Array<int> &intArray)
{
	Array<int> assignArray(MAX_VAL); 
	Array<int> copyArray = intArray;
	assignArray = intArray;

	for (unsigned int i = 0; i < intArray.size(); ++i)
	{
		if (intArray[i] != copyArray[i] || intArray[i] != assignArray[i])
		{
			std::cerr << _RED << "Copy failed at index " << i << _END << std::endl;
			return;
		}
	}
	std::cout << _GREEN << "Copy constructor and assignment operator work as expected." << _END << std::endl;
	std::cout << std::endl;

	std::cout << _GOLD << "Testing that modifying a copy does not affect the original array" << _END << std::endl;
	copyArray[0] = 9999;
	std::cout << "Modified copyArray[0] to " << _BLUE << copyArray[0] << _END << std::endl;
	std::cout << "Original intArray[0] remains " << _BLUE << intArray[0] << _END << std::endl;

	if (intArray[0] == copyArray[0])
	{
		std::cerr << _RED << "Error: Modifying copy affected the original array!" << _END << std::endl;
		return;
	}
	else
	{
		std::cout << _GREEN << "Test passed: Modifying copy does not affect the original array." << _END << std::endl;
	}
	std::cout << std::endl;
}

void testExceptionHandling(Array<int> &intArray)
{
	try
	{
		intArray[-1] = MAX_VAL;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught for negative index: " << _RED << e.what() << _END << std::endl;
	}
	try
	{
		intArray[MAX_VAL] = MAX_VAL;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught for oversized index: " << _RED << e.what() << _END << std::endl;
	}
	std::cout << std::endl;
}

void testFloatArray()
{
	Array<float> floatArray(5);
	for (unsigned int i = 0; i < floatArray.size(); ++i)
	{
		floatArray[i] = i * 1.5f;
		std::cout << "floatArray[" << i << "] = " << _BLUE << floatArray[i] << _END << std::endl;
	}
	std::cout << std::endl;
}

void testStringArray()
{
	Array<std::string> strArray(3);
	strArray[0] = "Hello";
	strArray[1] = "World";
	strArray[2] = "Array";
	for (unsigned int i = 0; i < strArray.size(); ++i)
	{
		std::cout << "strArray[" << i << "] = " << _BLUE << strArray[i] << _END << std::endl;
	}
}

int main()
{
	std::cout << _GOLD << "Testing default constructor (empty array)" << _END << std::endl;
	Array<int> emptyArray;
	std::cout << "Empty array size: " << _BLUE << emptyArray.size() << _END << std::endl << std::endl;

	Array<int> intArray(MAX_VAL);

	std::cout << _GOLD << "Testing Array<int>" << _END << std::endl;
	testIntArray(intArray);

	std::cout << _GOLD << "Testing copy constructor and assignment operator" << _END << std::endl;
	testCopyConstructorAssignementOperator(intArray);

	std::cout << _GOLD << "Testing out-of-bounds exception handling" << _END << std::endl;
	testExceptionHandling(intArray);

	std::cout << _GOLD << "Testing Array<float>" << _END << std::endl;
	testFloatArray();

	std::cout << _GOLD << "Testing Array<std::string>" << _END << std::endl;
	testStringArray();

	return 0;
}
