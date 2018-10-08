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
	arrays_ = arrays;
}

Matrix::Matrix(const Matrix& obj)
	: size_(obj.size_), arrays_(obj.arrays_)
{

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

}
