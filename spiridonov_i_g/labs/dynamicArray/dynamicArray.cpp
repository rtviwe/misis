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
	{
		throw std::out_of_range("Size should not be negative");
	}

	size_ = size;
	data_ = new int[size_];

	for (int i(0); i < size_; i++)
	{
		data_[i] = 0;
	}
}

DynamicArray::DynamicArray(const DynamicArray& obj)
{
	size_ = obj.size_;
	data_ = new int[size_];

	for (int i(0); i < size_; i++)
	{
		data_[i] = obj.data_[i];
	}
}

int DynamicArray::getSize()
{
	return size_;
}

void DynamicArray::setSize(int size)
{
	size_ = size;
	int* newData = new int[size];

	for (int i(0); i < size_; i++)
	{
		newData[i] = data_[i];
	}

	data_ = newData;
}

int& DynamicArray::operator[](const int i)
{
	if (i < 0)
	{
		throw std::out_of_range("Index should not be negative");
	}

	if (i > size_)
	{
		throw std::out_of_range("Index should be less than size of array");
	}

	return data_[i];
}

DynamicArray& DynamicArray::operator=(const DynamicArray& rhs)
{
	if (this != &rhs)
	{
		size_ = rhs.size_;

		delete[] data_;
		data_ = new int[size_];

		for (int i(0); i < size_; i++)
		{
			data_[i] = rhs.data_[i];
		}
	}

	return *this;
}

DynamicArray::~DynamicArray()
{
	delete[] data_;
}
