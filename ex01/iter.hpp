#pragma once

#define ITER_HPP
#include <cstddef>

template <typename T>
void iter(T* array, std::size_t arrayLenght, void (*func)(T&)) {
	if (!array || arrayLenght <= 0 || !func) {
		return;
	}
	for (std::size_t i = 0; i < arrayLenght; i++) {
		func(array[i]);
	}
}
