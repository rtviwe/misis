// Copyright 2018 by Igor Spiridonov under Free Public License 1.0.0

#include <iostream>
#include <sstream>
#include "../complex.hpp"

using namespace std;

bool testParse(const std::string &str) {
    istringstream istrm(str);
    Complex z;
    istrm >> z;

    if (istrm.good()) {
        cout << "Read success: " << str << " -> " << z << endl;
    } else {
        cout << "Read error: " << str << " -> " << z << endl;
    }

    return istrm.good();
}

int main() {
    Complex z(0.0, 0);
    cout << z << endl;

    z += Complex(8.0, 1);
    cout << "z + (8.0 +i) = " << z << endl;

    z -= Complex(5.0, 2);
    cout << "z - (5.0 + 2*i) = " << z << endl;

    z *= 7.0;
    cout << "z * 7.0 = " << z << endl;

    z *= Complex(2.0, 2);
    cout << "z * (2.0 + 2*i) = " << z << endl;

    z /= 2.0;
    cout << "z / 2.0 = " << z << endl;

    z /= Complex(4.0, 3);
    cout << "z / (4.0 + 3*i) = " << z << endl;

    z += 2.0;
    cout << "z + 2.0 = " << z << endl;

    z -= 3.1;
    cout << "z - 3.1 = " << z << endl;

    z += 1;
    cout << "z + 1 = " << z << endl;

    z -= 4;
    cout << "z - 4 = " << z << endl;

    z *= 3;
    cout << "z * 3 = " << z << endl;

    z /= 2;
    cout << "z / 2 = " << z << endl;

    z += Complex(2);
    cout << "z + 2 = " << z << endl;

    z += Complex(3.4);
    cout << "3.4 + z = " << z << endl;

    z += Complex(-1);
    cout << "(-1) + z = " << z << endl;

    z += Complex(-2.8);
    cout << "(-2.8) + z = " << z << endl;

    Complex sum(z + Complex(1.0, 2));
    cout << "z + (1.0, 2) = " << sum << endl;

    Complex minus(z - Complex(2.0, 2));
    cout << "z - (2.0, 2) = " << minus << endl;

    Complex u(z * Complex(1.0, 2));
    cout << "z * (1.0, 2) = " << u << endl;

    Complex del(z / Complex(1.0, 2));
    cout << "z / (1.0, 2) = " << del << endl;

    Complex l(7, 5);
    bool w = z == l;
    cout << "z == (7 + 5*i) = " << w << endl;

    Complex h(2, 8);
    bool s = z != h;
    cout << "z != (2 + 8*i) = " << s << endl;

    testParse("{8.9,9}");
    testParse("{8.9, 9}");
    testParse("{8.9, 9");
    return 0;
}
