#include <iostream>
#include <sstream>
#include "dynamicArray.hpp"
#include "matrix.hpp"

using namespace std;

void testDynamicArray()
{
	cout << "Test Dynamic Array" << endl;
	DynamicArray da1;
	DynamicArray da2(5);
	DynamicArray da3(da2);

	for (int i = 0; i < 5; i++)
	{
		da2[i] = i;
	}

	for (int i = 0; i < 5; i++)
	{
		cout << da2[i] << endl;
	}
	cout << endl;

	da3[1] = 10;
	for (int i = 0; i < 5; i++)
	{
		cout << da3[i] << endl;
	}
	cout << endl;

	cout << da2[1] << endl;
}

void testMatrix()
{
	cout << "Test Matrix" << endl;

	Matrix m1;
	Matrix m2(5);
	DynamicArray da1(5);
	DynamicArray da2(5);
	DynamicArray da3(5);
	DynamicArray da4(5);
	DynamicArray da5(5);
	DynamicArray dar[5] { da1, da2, da3, da4, da5 };
	Matrix m3(dar);
	Matrix m4(m2);

	for (int i = 0; i < m2.getSize(); i++)
	{
		for (int j = 0; j < m2.getSize(); j++)
		{
			m2[i][j] = i + j;
		}
	}
	m2[2][3] = 0;

	for (int i = 0; i < m4.getSize(); i++)
	{
		for (int j = 0; j < m4.getSize(); j++)
		{
			cout << m4[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < m4.getSize(); i++)
	{
		for (int j = 0; j < m4.getSize(); j++)
		{
			cout << m3[i][j] << " ";
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
