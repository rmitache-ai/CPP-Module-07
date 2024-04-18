#pragma once

#include <iostream>

template <class T> void swap(T& a, T& b) {
	T temp = a;
	a      = b;
	b      = temp;
}

template <class T> T min(T a, T b) {
	if (a > b) {
		return b;
	}
	if (a == b) {
		return b;
	}
	return a;
}

template <class T> T max(T a, T b) {
	if (a > b) {
		return a;
	}
	if (a == b) {
		return b;
	}
	return a;
}