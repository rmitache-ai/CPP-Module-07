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
		: _sizeOfArray(0), _array(new T) {
		std::cout << "Default constructor called" << std::endl;
	}

	Array(unsigned int n)
		: _array(new T[n]), _sizeOfArray(n) {
		std::cout << "Costructor with a size of " << _array
				  << " called" << std::endl;
	}
	Array(Array& copy)
		: _array(new T[copy.size()]), _sizeOfArray(copy.size()) {
		for (unsigned int i = 0; i < _sizeOfArray; i++) {
			_array[i] = copy._array[i];
		}
		std::cout << "Copy constructor called" << std::endl;
	};

	Array& operator=(const Array& copy) {
		if (this != &copy) {
			delete[] _array;
				_sizeOfArray = copy._sizeOfArray;
				for (unsigned int i = 0; i < _sizeOfArray; i++) {
					_array[i] = copy._array[i];
			}
		}
		std::cout << "Assignment operator called" << std::endl;
		return *this;
	}

	T& operator[](unsigned int index) {
		if (index >= _sizeOfArray) {
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

	~Array() {
		delete[] _array;
		std::cout << "Destructor called" << std::endl;
	}
};