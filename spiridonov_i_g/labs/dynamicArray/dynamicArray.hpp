#pragma once
#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

class DynamicArray
{
public:
	DynamicArray();
	DynamicArray(const int size);
	DynamicArray(const DynamicArray& obj);

	int getSize();
	void setSize(int size);

	int& operator[](const int i);

	~DynamicArray();
private:
	int size_{ 0 };
	int* data_{ nullptr };
};

#endif
