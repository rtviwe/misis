// Copyright 2018 by Igor Spiridonov under Free Public License 1.0.0

#include <iostream>
#include "../dynamic_array.hpp"

using namespace std;

int main() {
    DynamicArray dynamicArray1(10);

    for (int i(0); i < 10; i++) {
        dynamicArray1[i] = (i * i) / 2.0;
    }
    cout << dynamicArray1 << endl << endl;
    double a = dynamicArray1[3];

    try {
        dynamicArray1[11];
    } catch (out_of_range) {
        cout << "Out of range!" << endl;
    }

    cout << endl;

    DynamicArray dynamicArray2;
    dynamicArray2 = dynamicArray1;
    cout << dynamicArray2 << endl;

    cout << "Resize to 7" << endl;
    dynamicArray2.setSize(7);
    cout << dynamicArray2 << endl;

    cout << "Resize to 70" << endl;
    dynamicArray2.setSize(70);
    cout << dynamicArray2 << endl;

    return 0;
}
