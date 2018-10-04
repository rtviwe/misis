#pragma once

#include "dynamicArray.hpp"

class DynamicArray;

class Matrix
{
public:
	Matrix();
	Matrix(const int size);
	Matrix(DynamicArray& obj);

	int& operator[](const int i);

	~Matrix();
private:
	int size_{ 0 };
	DynamicArray* arrays_{ nullptr };
};
