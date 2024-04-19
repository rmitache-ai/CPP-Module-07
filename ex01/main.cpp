#include "iter.hpp"
#include <cctype>
#include <iostream>

void ft_tolower(char& str) {
	str = static_cast<char>(
		std::tolower(static_cast<unsigned char>(str)));
}

int main() {
	char a[] = {'A', 'B', 'C'};
	std::cout << "Original: " << a[0] << " " << a[1] << " "
			  << a[2] << std::endl;

	::iter(a, sizeof(a) / sizeof(a[0]), ft_tolower);
	std::cout << "Changed: " << a[0] << " " << a[1] << " "
			  << a[2] << std::endl;
	return 0;
}