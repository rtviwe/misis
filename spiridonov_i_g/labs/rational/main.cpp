#include <iostream>
#include <sstream>
#include "rational.hpp"

using namespace std;

ostream& operator<<(ostream& ostrm, const Rational& rhs);
istream& operator>>(istream& istrm, Rational& rhs);

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);

void testEquals()
{
	Rational number1{ 10, 20 };
	Rational number2{ 10, 20 };

	bool result = number1 == number2;
	if (result)
		cout << "Test equals " << number1 << " == " << number2 << " passed" << endl;
	else
		cout << "Test equals " << number1 << " == " << number2 << " failed" << endl;
}

void testNotEquals()
{
	Rational number1{ 10, 20 };
	Rational number2{ 50, 8 };

	bool result = number1 != number2;
	if (result)
		cout << "Test not equals " << number1 << " != " << number2 << " passed" << endl;
	else
		cout << "Test not equals " << number1 << " != " << number2 << " failed" << endl;
}

void testSum()
{
	Rational number1{ 10, 2 };
	Rational number2{ 15, 6 };
	Rational answer{ 15, 2 };

	bool result = (answer == (number1 + number2));
	if (result)
		cout << "Test sum " << number1 << " + " << number2 << " = " << answer << " passed" << endl;
	else
		cout << "Test sum " << number1 << " + " << number2 << " = " << answer << " failed" << endl;
}

void testSubstract()
{
	Rational number1{ 3, 4 };
	Rational number2{ 1, 2 };
	Rational answer{ 1, 4 };

	bool result = (answer == (number1 - number2));
	if (result)
		cout << "Test substract " << number1 << " - " << number2 << " = " << answer << " passed" << endl;
	else
		cout << "Test substract " << number1 << " - " << number2 << " = " << answer << " failed" << endl;
}

void testMultiply()
{
	Rational number1{ 3, -4 };
	Rational number2{ 1, 2 };
	Rational answer{ -3, 8 };

	bool result = (answer == (number1 * number2));
	if (result)
		cout << "Test multiply " << number1 << " * " << number2 << " = " << answer << " passed" << endl;
	else
		cout << "Test multiply " << number1 << " * " << number2 << " = " << answer << " failed" << endl;
}

void testDivide()
{
	Rational number1{ 5, 4 };
	Rational number2{ 3, 2 };
	Rational answer{ 5, 6 };

	bool result = (answer == (number1 / number2));
	if (result)
		cout << "Test divide " << number1 << " / " << number2 << " = " << answer << " passed" << endl;
	else
		cout << "Test divide " << number1 << " / " << number2 << " = " << answer << " failed" << endl;
}

void testSumEqual()
{
	Rational numberBuffer{ 10, 2 };
	Rational number1{ 10, 2 };
	Rational number2{ 15, 6 };
	Rational answer{ 15, 2 };

	number1 += number2;
	bool result = (answer == number1);
	if (result)
		cout << "Test " << numberBuffer << " += " << number2 << " " << number1 << " = " << answer << " passed" << endl;
	else
		cout << "Test " << numberBuffer << " += " << number2 << " " << number1 << " = " << answer << " failed" << endl;
}

void testSubstractEqual()
{
	Rational numberBuffer{ 1, 2 };
	Rational number1{ 1, 2 };
	Rational number2{ 3, 4 };
	Rational answer{ -1, 4 };

	number1 -= number2;
	bool result = (answer == number1);
	if (result)
		cout << "Test " << numberBuffer << " -= " << number2 << " " << number1 << " = " << answer << " passed" << endl;
	else
		cout << "Test " << numberBuffer << " -= " << number2 << " " << number1 << " = " << answer << " failed" << endl;
}

void testMultiplyEqual()
{
	Rational numberBuffer{ 1, 2 };
	Rational number1{ 1, 2 };
	Rational number2{ 3, 4 };
	Rational answer{ 3, 8 };

	number1 *= number2;
	bool result = (answer == number1);
	if (result)
		cout << "Test " << numberBuffer << " *= " << number2 << " " << number1 << " = " << answer << " passed" << endl;
	else
		cout << "Test " << numberBuffer << " *= " << number2 << " " << number1 << " = " << answer << " failed" << endl;
}

void testDivideEqual()
{
	Rational numberBuffer{ 5, 4 };
	Rational number1{ 5, 4 };
	Rational number2{ 3, 2 };
	Rational answer{ 5, 6 };

	number1 /= number2;
	bool result = (answer == number1);
	if (result)
		cout << "Test " << numberBuffer << " /= " << number2 << " " << number1 << " = " << answer << " passed" << endl;
	else
		cout << "Test " << numberBuffer << " /= " << number2 << " " << number1 << " = " << answer << " failed" << endl;
}

void testParse(const string& str)
{
	istringstream istrm(str);
	Rational number;
	istrm >> number;

	string answer;

	if (istrm.good())
		answer = "success";
	else
		answer = "error";

	cout << "Read " << answer << " : " << str << " -> " << number << endl;
}

void testConstructor(Rational& number, int num, int den)
{
	bool result = (number.getNumerator() == num) && (number.getDenominator() == den);
	if (result)
		cout << "Test constructor " << number << " passed" << endl;
	else
		cout << "Test constructor " << number << " failed" << endl;
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

	testParse("{2/4}");
	testParse("{ \n2/   4}");
	testParse("{s/4}");

	Rational num1{ 4, 2 };
	Rational num2{ 4, -2 };
	Rational num3{ -4, -2 };
	Rational num4{ -4, 2 };
	testConstructor(num1, 2, 1);
	testConstructor(num2, -2, 1);
	testConstructor(num3, 2, 1);
	testConstructor(num4, -2, 1);
}
