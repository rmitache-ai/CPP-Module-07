#include "Array.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>

#define ARRAY_SIZE 10
#define INDEX_OUT_OF_RANGE 15

class ComplexType {
private:
    std::string name;
    int value;

public:
    ComplexType() : name("default"), value(0) {}
    ComplexType(std::string n, int v) : name(n), value(v) {}

    void display() const {
        std::cout << "Name: " << name << ", Value: " << value << std::endl;
    }
};

std::string toString(int value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

int main() {
    try {
        int* a = new int();
        std::cout << "a: " << *a << std::endl;
		Array<int> numbers(ARRAY_SIZE);
        for (int i = 0; i < ARRAY_SIZE; i++) {
            numbers[i] = rand();
            std::cout << "numbers[" << i << "]: " << numbers[i] << std::endl;
        }

        // std::cout << "------ Out of Range Test ------\n";
        // try {
        //     numbers[INDEX_OUT_OF_RANGE];
        // } catch (const std::out_of_range& e) {
        //     std::cout << e.what() << std::endl;
        // }

        delete a;

        // Test with ComplexType
        Array<ComplexType> complexArray(ARRAY_SIZE);
        for (int i = 0; i < ARRAY_SIZE; i++) {
            complexArray[i] = ComplexType("Name " + toString(i), i);
            complexArray[i].display();
        }

        std::cout << "------ Out of Range Test for ComplexType ------\n";
        try {
            complexArray[INDEX_OUT_OF_RANGE].display();
        } catch (const std::out_of_range& e) {
            std::cout << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}