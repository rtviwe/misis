#include <iostream>
#include "matrix.hpp"

Matrix::Matrix()
{
	size_ = 0;
	arrays_ = new DynamicArray[size_];
}

Matrix::Matrix(const int size)
{
	if (size_ < 0)
		throw std::exception("Size should not be negative");

	size_ = size;
	arrays_ = new DynamicArray[size_];
}

Matrix::Matrix(DynamicArray* arrays)
{
	size_ = arrays->getSize();
	arrays_ = new DynamicArray[size_];

	for (int i(0); i < size_; i++)
	{
		DynamicArray* temp = new DynamicArray(arrays[i]);
		arrays_[i] = *temp;
	}
}

Matrix::Matrix(const Matrix& obj)
{
	size_ = obj.size_;
	arrays_ = new DynamicArray[size_];

	for (int i(0); i < size_; i++)
	{
		DynamicArray* temp = new DynamicArray(obj.arrays_[i]);
		arrays_[i] = *temp;
	}
}

int Matrix::getSize()
{
	return size_;
}

DynamicArray& Matrix::operator[](const int i)
{
	return arrays_[i];
}

Matrix::~Matrix()
{
	delete[] arrays_;
}
