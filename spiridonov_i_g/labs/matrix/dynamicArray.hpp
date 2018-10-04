#pragma once

class DynamicArray
{
public:
	DynamicArray();
	DynamicArray(const int size);
	DynamicArray(const DynamicArray& obj);

	int& operator[](const int i);

	~DynamicArray();
private:
	int size_{ 0 };
	int* data_{ nullptr };
};
