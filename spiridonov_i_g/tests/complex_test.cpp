#include <iostream>
#include <sstream>
#include "complex.hpp"

using namespace std;

void testEquals()
{
    Complex number1{ 10, 20 };
    Complex number2{ 10, 20 };

    bool result = number1 == number2;
    if (result)
        cout << "Test equals " << number1 << " == " << number2 << " passed" << endl;
    else
        cout << "Test equals " << number1 << " == " << number2 << " failed" << endl;
}

void testNotEquals()
{
    Complex number1{ 10, 20 };
    Complex number2{ -5, 2 };

    bool result = number1 != number2;
    if (result)
        cout << "Test equals " << number1 << " != " << number2 << " passed" << endl;
    else
        cout << "Test equals " << number1 << " != " << number2 << " failed" << endl;
}

void testSum()
{
    Complex answer{ 11.5, 8 };
    Complex number1{ 5, 5 };
    Complex number2{ 6.5, 3 };
    Complex sum = number1 + number2;

    bool result = sum == answer;
    if (result)
        cout << "Test sum " << number1 << " + " << number2 << " = " << answer << " passed" << endl;
    else
        cout << "Test sum " << number1 << " + " << number2 << " = " << answer << " failed" << endl;
}

void testSubstract()
{
    Complex answer{ 39.5, 1.4 };
    Complex number1{ 55, 3.3 };
    Complex number2{ 15.5, 1.9 };
    Complex substract = number1 - number2;

    bool result = substract == answer;
    if (result)
        cout << "Test substract " << number1 << " - " << number2 << " = " << answer << " passed" << endl;
    else
        cout << "Test substract " << number1 << " - " << number2 << " = " << answer << " failed" << endl;
}

void testMultiply()
{
    Complex numberBuffer{ 5, 3 };
    Complex answer{ -1, 47 };
    Complex number1{ 5, 3 };
    Complex number2{ 4, 7 };
    Complex multiply = number1 * number2;

    bool result = multiply == answer;
    if (result)
        cout << "Test multiply " << number1 << " * " << number2 << " = " << answer << " passed" << endl;
    else
        cout << "Test multiply " << number1 << " * " << number2 << " = " << answer << " failed" << endl;
}

void testDivide()
{
    Complex numberBuffer{ -2, 1 };
    Complex answer{ -1.5, -0.5 };
    Complex number1{ -2, 1 };
    Complex number2{ 1, -1 };
    Complex divide = number1 / number2;

    bool result = divide == answer;
    if (result)
        cout << "Test divide " << number1 << " / " << number2 << " = " << answer << " passed" << endl;
    else
        cout << "Test divide " << number1 << " / " << number2 << " = " << answer << " failed" << endl;
}

void testSumEqual()
{
    Complex numberBuffer{ 5, 5 };
    Complex answer{ 11.5, 8 };
    Complex number1{ 5, 5 };
    Complex number2{ 6.5, 3 };
    number1 += number2;

    bool result = number1 == answer;
    if (result)
        cout << "Test " << numberBuffer << " += " << number2 << " " << number1 << " = " << answer << " passed" << endl;
    else
        cout << "Test " << numberBuffer << " += " << number2 << " " << number1 << " = " << answer << " failed" << endl;
}

void testSubstractEqual()
{
    Complex numberBuffer{ 5, 5 };
    Complex answer{ -1.5, 2 };
    Complex number1{ 5, 5 };
    Complex number2{ 6.5, 3 };
    number1 -= number2;

    bool result = number1 == answer;
    if (result)
        cout << "Test " << numberBuffer << " -= " << number2 << " " << number1 << " = " << answer << " passed" << endl;
    else
        cout << "Test " << numberBuffer << " -= " << number2 << " " << number1 << " = " << answer << " failed" << endl;
}

void testMultiplyEqual()
{
    Complex numberBuffer{ 5, 3 };
    Complex answer{ -1, 47 };
    Complex number1{ 5, 3 };
    Complex number2{ 4, 7 };
    number1 *= number2;

    bool result = number1 == answer;
    if (result)
        cout << "Test " << numberBuffer << " *= " << number2 << " " << number1 << " = " << answer << " passed" << endl;
    else
        cout << "Test " << numberBuffer << " *= " << number2 << " " << number1 << " = " << answer << " failed" << endl;
}

void testDivideEqual()
{
    Complex numberBuffer{ -2, 1 };
    Complex answer{ -1.5, -0.5 };
    Complex number1{ -2, 1 };
    Complex number2{ 1, -1 };
    number1 /= number2;

    bool result = number1 == answer;
    if (result)
        cout << "Test " << numberBuffer << " /= " << number2 << " " << number1 << " = " << answer << " passed" << endl;
    else
        cout << "Test " << numberBuffer << " /= " << number2 << " " << number1 << " = " << answer << " failed" << endl;
}

void testParse(const string& str)
{
    istringstream istrm(str);
    Complex z;
    istrm >> z;
    if (istrm.good())
    {
        cout << "Read success: " << str << " -> " << z << endl;
    }
    else
    {
        cout << "Read error: " << str << " -> " << z << endl;
    }
}

int main()
{
    testEquals();
    testNotEquals();
    testSum();
    testSubstract();
    testMultiply();
    testDivide();
    testSumEqual();
    testSubstractEqual();
    testMultiplyEqual();
    testDivideEqual();

    testParse("{8.9,9}");
    testParse("{\t\t\t8.9, \n9}");
    testParse("   {8.9,9");

    return 0;
}
