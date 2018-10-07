#include <iostream>
#include "DynamicArray.hpp"

DynamicArray::DynamicArray()
{
	size_ = 0;
	data_ = new int[size_];
}

DynamicArray::DynamicArray(const int size)
{
	if (size_ < 0)
		throw std::exception("Size should not be negative");

	size_ = size;
	data_ = new int[size_];
}

DynamicArray::DynamicArray(const DynamicArray& obj)
	: size_(obj.size_), data_(obj.data_)
{

}

int DynamicArray::getSize()
{
	return size_;
}

void DynamicArray::setSize(int size)
{
	int* newData = new int[size];

	for (int i = 0; i < size_; i++)
		newData[i] = data_[i];

	data_ = newData;
	size_ = size;
}

int* DynamicArray::getData()
{
	return data_;
}

void DynamicArray::setData(int* data)
{
	data_ = data;
}

int& DynamicArray::operator[](const int i)
{
	return data_[i];
}

DynamicArray::~DynamicArray()
{

}
