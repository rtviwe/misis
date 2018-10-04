#include "matrix.hpp"

Matrix::Matrix()
{
	size_ = 0;
	arrays_ = nullptr;
}

Matrix::Matrix(const int size)
{
	size_ = size;
}