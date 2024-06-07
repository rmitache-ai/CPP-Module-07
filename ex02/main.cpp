#include "Array.hpp"
#include <cstdlib>
#include <iostream>

#define ARRAY_SIZE 100
#define INDEX_OUT_OF_RANGE 99

int main() {
	int* a = new int();
	std::cout << "a: " << *a << std::endl;
	Array<int> numbers(ARRAY_SIZE);
	for (int i = 0; i < ARRAY_SIZE; i++) {
		numbers[i] = rand();
		std::cout << "numbers: " << numbers[i] << std::endl;
	}
	std::cout << "------ Out of Range Test ------\n"
			  << std::endl;
	numbers[INDEX_OUT_OF_RANGE];
	delete a;
	return 0;
}
