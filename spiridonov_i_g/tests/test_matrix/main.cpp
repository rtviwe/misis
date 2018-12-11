// Copyright 2018 by Igor Spiridonov under Free Public License 1.0.0

#include <iostream>
#include <vector>
#include "../../labs/matrix/matrix.hpp"

using namespace std;

int main() {
    Matrix matrix1(3, 2);
    matrix1.getElementAt(0, 0) = 0;
    matrix1.getElementAt(0, 1) = 1;
    matrix1.getElementAt(1, 0) = 4;
    matrix1.getElementAt(1, 1) = 5;
    matrix1.getElementAt(2, 0) = 8;
    matrix1.getElementAt(2, 1) = 9;
    cout << "matrix1 = " << "\n" << matrix1 << endl;

    Matrix matrix2 = matrix1;
    matrix2.getElementAt(0, 0) = 1;
    matrix2.getElementAt(0, 1) = 3;
    matrix2.getElementAt(1, 0) = 1;
    matrix2.getElementAt(1, 1) = 1;
    matrix2.getElementAt(2, 0) = 8;
    matrix2.getElementAt(2, 1) = 5;
    cout << "matrix2 = " << "\n" << matrix2 << endl;

    Matrix matrix3;
    cout << "matrix3 = " << "\n" << matrix3 << endl;

    return 0;
}
