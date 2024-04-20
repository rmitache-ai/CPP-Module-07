#pragma once

#include <exception>
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array {
private:
	T*           _array;
	unsigned int _size;

public:
	Array(void)
		: _size(0) {
		this->_array = new T;
		std::cout << "Default constructor called" << std::endl;
	}

	Array(unsigned int n)
		: _size(n) {
		this->_array = new T[n];
		for (unsigned int i = 0; i < n; i++) {
			this->_array[i] = n;
		}
		std::cout << "Costructor with a size of " << n
				  << " called" << std::endl;
	}

	Array(Array& copy)
		: _array(copy._array), _size(copy._size) {
		std::cout << "Copy constructor called" << std::endl;
	}

	Array& operator=(Array const& other) {
		this->_array = other._array;
		this->_size  = other._size;
		std::cout << "Assign operator called" << std::endl;
		return *this;
	}

	T& operator[](unsigned int index) {
		if (index < 0 || index >= _size) {
			throw outOfRangeException();
		}
		return (this->_array[index]);
	}

	class outOfRangeException : public std::exception {
		const char* what() const throw() {
			return "Out of Range of Array!\n";
		}
	};

	unsigned int size() {
		std::cout << "The size of the array is " << _size
				  << std::endl;
		return _size;
	}

	~Array() { std::cout << "Destructor called" << std::endl; }
};