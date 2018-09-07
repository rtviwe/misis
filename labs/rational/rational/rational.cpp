#include <iostream>
#include <sstream>

using namespace std;

struct Rational
{
	Rational() = default;
	explicit Rational(const int numerator);
	Rational(const int numerator, const int denominator);

	bool operator==(const Rational& rhs) const
	{
		return (num == rhs.num) && (den == rhs.den);
	}

	bool operator!=(const Rational& rhs) const
	{
		return !operator==(rhs);
	}
	
	Rational& operator+=(const Rational& rhs);
	Rational& operator+=(const int rhs)
	{
		return operator+=(Rational(rhs));
	}
	
	Rational& operator-=(const Rational& rhs);
	Rational& operator-=(const int rhs)
	{
		return operator-=(Rational(rhs));
	}

	Rational& operator*=(const Rational& rhs);
	Rational& operator*=(const int rhs)
	{
		return operator*=(Rational(rhs));
	}

	Rational& operator/=(const Rational& rhs);
	Rational& operator/=(const int rhs)
	{
		return operator/=(Rational(rhs));
	}

	void normalize();

	ostream& writeTo(ostream& ostrm) const;
	istream& readFrom(istream& istrim);

	int num{ 0 };
	int den{ 1 };

	static const char leftBrace{ '{' };
	static const char separator{ '/' };
	static const char rightBrace{ '}' };
};

using namespace std;

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);

inline ostream& operator<<(ostream& ostrm, const Rational& rhs)
{
	return rhs.writeTo(ostrm);
}

inline istream& operator>>(istream& istrm, Rational& rhs)
{
	return rhs.readFrom(istrm);
}

bool testParse(const string& str)
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
	return istrm.good();
}

bool testSum()
{
	Rational number1{ 10, 2 };
	Rational number2{ 15, 6 };
	Rational answer{ 15, 2 };

	bool result = (answer == (number1 + number2));
	if (result)
		cout << "Test 1 passed" << endl;
	else 
		cout << "Test 1 failed" << endl;

	return result;
}

bool testSub()
{
	Rational number1{ 3, 4 };
	Rational number2{ 1, 2 };
	Rational answer{ 1, 4 };

	bool result = (answer == (number1 - number2));
	if (result)
		cout << "Test 2 passed" << endl;
	else
		cout << "Test 2 failed" << endl;

	return result;
}

bool testMul()
{
	Rational number1{ 3, -4 };
	Rational number2{ 1, 2 };
	Rational answer{ -3, 8 };

	bool result = (answer == (number1 * number2));
	if (result)
		cout << "Test 3 passed" << endl;
	else
		cout << "Test 3 failed" << endl;

	return result;
}

bool testDiv()
{
	Rational number1{ 5, 4 };
	Rational number2{ 3, 2 };
	Rational answer{ 5, 6 };

	bool result = (answer == (number1 / number2));
	if (result)
		cout << "Test 4 passed" << endl;
	else
		cout << "Test 4 failed" << endl;

	return result;
}

bool testSumEq()
{
	
	Rational number1{ 10, 2 };
	Rational number2{ 15, 6 };
	Rational answer{ 15, 2 };

	number1 += number2;
	bool result = (answer == number1);
	if (result)
		cout << "Test 5 passed" << endl;
	else
		cout << "Test 5 failed" << endl;

	return result;
}

bool testSubEq()
{
	Rational number1{ 1, 2 };
	Rational number2{ 3, 4 };
	Rational answer{ -1, 4 };

	number1 -= number2;
	bool result = (answer == number1);
	if (result)
		cout << "Test 6 passed" << endl;
	else
		cout << "Test 6 failed" << endl;

	return result;
}

bool testMulEq()
{
	Rational number1{ 1, 2 };
	Rational number2{ 3, 4 };
	Rational answer{ 3, 8 };

	number1 *= number2;
	bool result = (answer == number1);
	if (result)
		cout << "Test 7 passed" << endl;
	else
		cout << "Test 7 failed" << endl;

	return result;
}

bool testDivEq()
{
	Rational number1{ 5, 4 };
	Rational number2{ 3, 2 };
	Rational answer{ 5, 6 };

	number1 /= number2;
	bool result = (answer == number1);
	if (result)
		cout << "Test 8 passed" << endl;
	else
		cout << "Test 8 failed" << endl;

	return result;
}

int main()
{
	testSum();
	testSub();
	testMul();
	testDiv();
	testSumEq();
	testSubEq();
	testMulEq();
	testDivEq();
	testParse("{2/4}");
	testParse("{ \n2/   4}");
	testParse("{s/4}");
}

Rational::Rational(const int numerator) : Rational(numerator, 0)
{

}

Rational::Rational(const int numerator, const int denominator) : num(numerator), den(denominator)
{

}

Rational operator+(const Rational& lhs, const Rational& rhs)
{
	Rational sum(lhs);
	sum += rhs;
	return sum;
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
	Rational sub(lhs);
	sub -= rhs;
	return sub;
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
	Rational mul(lhs);
	mul *= rhs;
	return mul;
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
	Rational div(lhs);
	div /= rhs;
	return div;
}

Rational& Rational::operator+=(const Rational& rhs)
{
	num = num * rhs.den + rhs.num * den;
	den *= rhs.den;
	normalize();
	return *this;
}

Rational& Rational::operator-=(const Rational& rhs)
{
	num = num * rhs.den - rhs.num * den;
	den *= rhs.den;
	normalize();
	return *this;
}

Rational& Rational::operator*=(const Rational& rhs)
{
	num *= rhs.num;
	den *= rhs.den;
	normalize();
	return *this;
}

Rational& Rational::operator/=(const Rational& rhs)
{
	num *= rhs.den;
	den *= rhs.num;
	normalize();
	return *this;
}

ostream& Rational::writeTo(ostream& ostrm) const
{
	ostrm << leftBrace << num << separator << den << rightBrace;
	return ostrm;
}

istream& Rational::readFrom(istream& istrm)
{
	char leftBrace = 0;
	int numerator = 0;
	char separator = 0;
	int denominator = 0;
	char rightBrace = 0;

	istrm >> leftBrace >> numerator >> separator >> denominator >> rightBrace;

	if (istrm.good())
	{
		if ((Rational::leftBrace == leftBrace) && (Rational::separator == separator)
			&& (Rational::rightBrace == rightBrace))
		{
			num = numerator;
			den = denominator;
		}
		else
		{
			istrm.setstate(ios_base::failbit);
		}
	}
	return istrm;
}

int gcd(int a, int b) 
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

void Rational::normalize()
{
	if (num != 0 && den != 0)
	{
		int div = gcd(num, den);
		num /= div;
		den /= div;
	}

	if (den < 0)
	{
		num *= -1;
		den *= -1;
	}
}
