#pragma once

#include <exception>
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array {
private:
	T*           _array;
	unsigned int _sizeOfArray;

public:
	Array(void)
		: _sizeOfArray(0) {
		this->_array = new T;
		std::cout << "Default constructor called" << std::endl;
	}

	Array(unsigned int n)
		: _sizeOfArray(n) {
		this->_array = new T[_sizeOfArray];
		std::cout << "Costructor with a size of " << n
				  << " called" << std::endl;
	}

	Array(Array& copy)
		: _array(copy._array), _sizeOfArray(copy._sizeOfArray) {
		std::cout << "Copy constructor called" << std::endl;
	}

	Array& operator=(Array const& other) {
		this->_array       = other._array;
		this->_sizeOfArray = other._sizeOfArray;
		std::cout << "Assign operator called" << std::endl;
		return *this;
	}

	T& operator[](unsigned int index) {
		if (index > _sizeOfArray) {
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
		std::cout << "The size of the array is " << _sizeOfArray
				  << std::endl;
		return _sizeOfArray;
	}

	~Array() { std::cout << "Destructor called" << std::endl; }
};