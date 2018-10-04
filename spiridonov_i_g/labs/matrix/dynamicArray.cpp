#include "DynamicArray.hpp"

DynamicArray::DynamicArray()
{
	size_ = 0;
	data_ = new int[size_];
}

DynamicArray::DynamicArray(const int size)
{
	size_ = size;
	data_ = new int[size_];
}

DynamicArray::DynamicArray(const DynamicArray& array) :
	size_(array.size_), data_(array.data_)
{

}

int& DynamicArray::operator[](const int i)
{
	return data_[i];
}

DynamicArray::~DynamicArray()
{
	// delete[] data_;
}
