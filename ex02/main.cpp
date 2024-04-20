#include "Array.hpp"
#include <cstdlib>
#include <iostream>

#define MAX_VAL 750
#define ARRAY_SIZE 100
#define INDEX_OUT_OF_RANGE 103

int main() {
	Array<int> numbers(MAX_VAL);
	for (int i = 0; i < ARRAY_SIZE; i++) {
		numbers[i] = rand();
		std::cout << "numbers: " << numbers[i] << std::endl;
	}
	std::cout << "------ Out of Range Test ------\n"
			  << std::endl;
	numbers[INDEX_OUT_OF_RANGE];
	return 0;
}