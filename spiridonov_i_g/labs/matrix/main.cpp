#include <iostream>
#include <sstream>
#include "dynamicArray.hpp"

using namespace std;

int main()
{
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

	return 0;
}