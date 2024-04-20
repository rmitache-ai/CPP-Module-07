#pragma once

#define ARRAY_HPP

#include <iostream>

template <typename T> class Array {
private:
	T*           array;
	unsigned int size;

public:
	Array(void)
		: size(0) {
		this->array = new T;
		std::cout << "Default constructor called" << std::endl;
	}

	Array(unsigned int n)
		: size(n) {
		this->array = new T[n];
		std::cout << "Costructor with a size of " << n
				  << " called" << std::endl;
	}
	~Array() { std::cout << "Destructor called" << std::endl; }
};