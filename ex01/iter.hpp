#pragma once

#include <cstddef>
#define ITER_HPP
#include <iostream>

template <typename T>
/**
 * Applies a given function to each element in an array.
 *
 * @param array The array to iterate over.
 * @param arrayLength The length of the array.
 * @param func A function pointer to the function to be applied to each element.
 */
void iter(T* array, size_t arrayLenght, void (*func)(T&)) {
	if (!array || arrayLenght <= 0 || !func) {
		return;
	}
	for (size_t i = 0; i < arrayLenght; i++) {
		func(array[i]);
	}
}
