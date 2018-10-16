#include <iostream>
#include <sstream>
#include "dynamicArray.hpp"
#include "matrix.hpp"

using namespace std;

void testDynamicArrayConstructor(DynamicArray& dynamicArray, int size, int* data)
{
	bool result = (dynamicArray.getSize() == size) && (*dynamicArray.getData() == *data);

	if (result)
		cout << "Test constructor " /*<< dynamicArray*/ << " passed" << endl;
	else
		cout << "Test constructor " /*<< dynamicArray*/ << " failed" << endl;
}

void testIndexer()
{
	/*
	T& operator=(const T& o)
	{
	    if (this != &o)
		{
			
		}
		return *this;
	}

	// должна работать такая конструкция
	x = y = z;
	*/
	DynamicArray dynamicArray(5);

	for (int i(0); i < 5; i++)
	{
		dynamicArray[i] = i;
	}

	for (int i(0); i < 5; i++)
	{
		cout << dynamicArray[i] << endl;
	}
	cout << endl;

	dynamicArray[1] = 10;
	for (int i(0); i < 5; i++)
	{
		cout << dynamicArray[i] << endl;
	}
	cout << endl;

	cout << dynamicArray[1] << endl;
}

void testResize()
{

}

void testMatrix()
{
	cout << "Test Matrix" << endl;

	Matrix matrix1;
	Matrix matrix2(5);
	DynamicArray dynamicArray1(5);
	DynamicArray dynamicArray2(5);
	DynamicArray dynamicArray3(5);
	DynamicArray dynamicArray4(5);
	DynamicArray dynamicArray5(5);
	DynamicArray arrayOfDynamicArrays[5] { dynamicArray1, dynamicArray2, dynamicArray3, dynamicArray4, dynamicArray5 };
	Matrix matrix3(arrayOfDynamicArrays);
	Matrix matrix4(matrix2);

	for (int i(0); i < matrix2.getSize(); i++)
	{
		for (int j = 0; j < matrix2.getSize(); j++)
		{
			matrix2[i][j] = i + j;
		}
	}
	matrix2[2][3] = 0;

	for (int i(0); i < matrix4.getSize(); i++)
	{
		for (int j(0); j < matrix4.getSize(); j++)
		{
			cout << matrix4[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i(0); i < matrix4.getSize(); i++)
	{
		for (int j(0); j < matrix4.getSize(); j++)
		{
			cout << matrix3[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	DynamicArray dynamicArray1;
	testDynamicArrayConstructor(dynamicArray1, 0, new int[0]);
	DynamicArray dynamicArray2(5);
	testDynamicArrayConstructor(dynamicArray2, 5, new int[5]{ 0, 0, 0, 0, 0 });
	DynamicArray dynamicArray3(dynamicArray2);
	testDynamicArrayConstructor(dynamicArray3, 5, new int[5]{ 0, 0, 0, 0, 0 });

	return 0;
}

// сделать стек на списке
