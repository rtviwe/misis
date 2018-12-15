// Copyright 2018 by Igor Spiridonov under Free Public License 1.0.0

#include <iostream>
#include <sstream>
#include "../../labs/rational/rational.hpp"

using namespace std;

void testParse(const string &str) {
    istringstream istrm(str);
    Rational number;
    istrm >> number;

    string answer;

    if (istrm.good()) {
        answer = "success";
    } else {
        answer = "error";
    }

    cout << "Read " << answer << " : " << str << " -> " << number << endl;
}

int main() {
    Rational r(1, 2);
    cout << r << endl;

    r += Rational(1, 4);
    cout << "r + 1/4 = " << r << endl;

    r -= Rational(2, 3);
    cout << "r - 2/3 = " << r << endl;

    r *= Rational(3, 5);
    cout << "r * 3/5 = " << r << endl;

    r /= Rational(7, 9);
    cout << "r / 7/9 = " << r << endl;

    bool f = (r == Rational(4, 3));
    cout << "r == 4/3 = " << f << endl;

    bool w = (r != Rational(1, 6));
    cout << "r != 1/6 = " << w << endl;

    r += Rational(1);
    cout << "r + 1 = " << r << endl;

    r -= Rational(2);
    cout << "r - 2 = " << r << endl;

    r += Rational(2.1);
    cout << "r + 2.1 = " << r << endl;

    r *= 2;
    cout << "r * 2 = " << r << endl;

    r /= 7;
    cout << "r / 7 = " << r << endl;

    r += 4.2;
    cout << "r + 4.2 = " << r << endl;

    r -= 3.5;
    cout << "r - 3.5 = " << r << endl;

    r *= 1.2;
    cout << "r * 1.2 = " << r << endl;

    r /= 2.2;
    cout << "r / 2.2 = " << r << endl;

    testParse("{3/7}");
    testParse("{0/ 9}");
    testParse("{3/ 5");

    return 0;
}
