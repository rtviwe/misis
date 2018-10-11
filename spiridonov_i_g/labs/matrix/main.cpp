#include <iostream>
#include <sstream>
#include "dynamicArray.hpp"
#include "matrix.hpp"

using namespace std;

void testDynamicArray()
{
	DynamicArray dynamicArray1;
	DynamicArray dynamicArray2(5);
	DynamicArray dynamicArray3(dynamicArray2);

	for (int i(0); i < 5; i++)
	{
		dynamicArray2[i] = i;
	}

	for (int i(0); i < 5; i++)
	{
		cout << dynamicArray2[i] << endl;
	}
	cout << endl;

	dynamicArray3[1] = 10;
	for (int i(0); i < 5; i++)
	{
		cout << dynamicArray3[i] << endl;
	}
	cout << endl;

	cout << dynamicArray2[1] << endl;
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
	testDynamicArray();
	testMatrix();

	return 0;
}
