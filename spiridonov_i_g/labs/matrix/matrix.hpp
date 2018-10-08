#pragma once
#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "dynamicArray.hpp"

class DynamicArray;

class Matrix
{
public:
	Matrix();
	Matrix(const int size);
	Matrix(DynamicArray* arrays);
	Matrix(const Matrix& copy);

	int getSize();

	DynamicArray& operator[](const int i);

	~Matrix();
private:
	int size_{ 0 };
	DynamicArray* arrays_{ nullptr };
};

#endif
