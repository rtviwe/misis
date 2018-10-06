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

	for (int i = 0; i < size_; i++)
	{
		DynamicArray da(size_);
		arrays_[i] = da;
	}
}

Matrix::Matrix(const DynamicArray& obj)
{
	//size_ = obj.getSize();
	// arrays_ = &obj;
}

Matrix::Matrix(const Matrix& obj)
{
	size_ = obj.size_;
	arrays_ = new DynamicArray[size_];

	for (int i = 0; i < size_; i++)
		arrays_[i] = obj.arrays_[i];
}

/*DynamicArray& Matrix::operator[](const int i)
{

}*/

Matrix::~Matrix()
{

}
