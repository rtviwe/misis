#include <iostream>
#include "dynamicArray.hpp"

using namespace std;

void testConstructor(DynamicArray& dynamicArray, int size, int* data)
{
	bool result = dynamicArray.getSize() == size;

	if (result)
		cout << "Test constructor size with size " << size << " passed" << endl;
	else
		cout << "Test constructor size with size " << size << " failed" << endl;

	bool result2 = true;
	for (int i(0); i < dynamicArray.getSize(); i++)
	{
		if (dynamicArray[i] != data[i])
		{
			result2 = false;
		}
	}

	cout << "Test constructor data with data: ";
	for (int i(0); i < size; i++)
	{
		cout << dynamicArray[i] << " ";
	}
	if (result2)
		cout << "passed" << endl;
	else
		cout << "failed" << endl;
}

void testIndexer()
{
	int answer = 10;
	DynamicArray dynamicArray(5);
	dynamicArray[0] = answer;

	bool result = dynamicArray[0] == 10;
	if (result)
		cout << "Test indexer dynamicArray[0] == " << answer << " passed" << endl;
	else
		cout << "Test indexer dynamicArray[0] == " << answer << " failed" << endl;
}

void testIndexerOutOfRange()
{
	DynamicArray dynamicArray(5);

	bool hasException = false;
	try
	{
		dynamicArray[10] = 10;
	}
	catch (exception)
	{
		hasException = true;
	}

	if (hasException)
		cout << "Test indexer out of range dynamicArray[10] == 10 passed" << endl;
	else
		cout << "Test indexer out of range dynamicArray[10] == 10 failed" << endl;
}

void testResize()
{
	int oldSize = 5;
	int newSize = 3;
	DynamicArray dynamicArray(oldSize);

	dynamicArray.setSize(newSize);

	bool result = dynamicArray.getSize() == newSize;
	if (result)
		cout << "Test resize from " << oldSize << " to " << newSize << " passed" << endl;
	else
		cout << "Test resize from " << oldSize << " to " << newSize << " failed" << endl;
	
	bool result2 = true;
	for (int i(0); i < newSize; i++)
	{
		if (dynamicArray[i] != 0)
		{
			result2 = false;
		}
	}

	if (result2)
		cout << "Test resize data safety passed" << endl;
	else
		cout << "Test resize data safety failed" << endl;
}

int main()
{
	DynamicArray dynamicArray1;
	testConstructor(dynamicArray1, 0, new int[0]);
	DynamicArray dynamicArray2(5);
	testConstructor(dynamicArray2, 5, new int[5]{ 0, 0, 0, 0, 0 });
	DynamicArray dynamicArray3(dynamicArray2);
	testConstructor(dynamicArray2, 5, new int[5]{ 0, 0, 0, 0, 0 });

	testIndexer();
	testIndexerOutOfRange();
	testResize();

	return 0;
}
