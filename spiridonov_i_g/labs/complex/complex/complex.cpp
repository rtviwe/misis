#include <iostream>
#include <sstream>

using namespace std;

struct Complex
{
	Complex() = default;
	explicit Complex(const double real);
	Complex(const double real, const double imaginary);

	bool operator==(const Complex& rhs) const 
	{
		return (re == rhs.re) && (im == rhs.im); 
	}

	bool operator!=(const Complex& rhs) const
	{
		return !operator==(rhs);
	}

	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double rhs)
	{ 
		return operator+=(Complex(rhs)); 
	}

	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double rhs)
	{
		return operator-=(Complex(rhs));
	}

	Complex& operator*=(const Complex& rhs);
	Complex& operator*=(const double rhs)
	{
		return operator*=(Complex(rhs));
	}

	Complex& operator/=(const Complex& rhs);
	Complex& operator/=(const double rhs)
	{
		return operator/=(Complex(rhs));
	}

	ostream& writeTo(ostream& ostrm) const;
	istream& readFrom(istream& istrim);

	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftBrace{'{'};
	static const char separator{','};
	static const char rightBrace{'}'};
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);

inline ostream& operator<<(ostream& ostrm, const Complex& rhs)
{
	return rhs.writeTo(ostrm);
}

inline istream& operator>>(istream& istrm, Complex& rhs)
{
	return rhs.readFrom(istrm);
}

bool testEq()
{
	Complex number1(10, 20);
	Complex number2(10, 20);

	return number1 == number2;
}

bool testNotEq()
{
	Complex number1(10, 20);
	Complex number2(-5, 0);

	return number1 != number2;
}

bool testSum()
{
	Complex answer(11.5, 8);
	Complex number1(5, 5);
	Complex number2(6.5, 3);
	Complex result = number1 + number2;

	return result == answer;
}

bool testSub()
{
	Complex answer(39.5, 1.4);
	Complex number1(55, 3.3);
	Complex number2(15.5, 1.9);
	Complex result = number1 - number2;

	return result == answer;
}

bool testSumEq()
{
	Complex answer(11.5, 8);
	Complex number1(5, 5);
	Complex number2(6.5, 3);
	number1 += number2;

	return number1 == answer;
}

bool testSubEq()
{
	Complex answer(-1.5, 2);
	Complex number1(5, 5);
	Complex number2(6.5, 3);
	number1 -= number2;

	return number1 == answer;
}

bool testMulEq()
{
	Complex answer(-1, 47);
	Complex number1(5, 3);
	Complex number2(4, 7);
	number1 *= number2;

	return number1 == answer;
}

bool testDivEq()
{
	Complex answer(-1.5, -0.5);
	Complex number1(-2, 1);
	Complex number2(1, -1);
	number1 /= number2;

	return number1 == answer;
}

bool testParse(const string& str)
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
	return istrm.good();
}

int main() 
{
	cout << "test1: " << (testEq() ? "passed" : "not passed") << endl;
	cout << "test2: " << (testSum() ? "passed" : "not passed") << endl;
	cout << "test3: " << (testSub() ? "passed" : "not passed") << endl;
	cout << "test4: " << (testSumEq() ? "passed" : "not passed") << endl;
	cout << "test5: " << (testSubEq() ? "passed" : "not passed") << endl;
	cout << "test6: " << (testMulEq() ? "passed" : "not passed") << endl;
	cout << "test7: " << (testDivEq() ? "passed" : "not passed") << endl;

	testParse("{8.9,9}");
	testParse("{\t\t\t8.9, \n9}");
	testParse("   {8.9,9");

}

Complex::Complex(const double real) : Complex(real, 0.0)
{

}

Complex::Complex(const double real, const double imaginary) : re(real), im(imaginary)
{
	re = real;
	im = imaginary;
}

Complex& Complex::operator+=(const Complex& rhs)
{
	re += rhs.re;
	im += rhs.im;
	return *this;
}

Complex& Complex::operator-=(const Complex& rhs)
{
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}

Complex& Complex::operator*=(const Complex& rhs)
{
	int tempRe = re;
	re = (re * rhs.re) - (im * rhs.im);
	im = (tempRe * rhs.im) + (im * rhs.re);
	return *this;
}

Complex& Complex::operator/=(const Complex& rhs)
{
	int tempRe = re;
	re = ((re * rhs.re) + (im * rhs.im)) / ((rhs.re * rhs.re) + (rhs.im * rhs.im));
	im = ((im * rhs.re) - (tempRe * rhs.im)) / ((rhs.re * rhs.re) + (rhs.im * rhs.im));
	return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
	Complex sum(lhs);
	sum += rhs;
	return sum;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
	Complex sub(lhs);
	sub -= rhs;
	return sub;
}

ostream& Complex::writeTo(ostream& ostrm) const
{
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}

istream& Complex::readFrom(istream& istrm)
{
	char leftBrace = 0;
	double real = 0.0;
	char comma = 0;
	double imaganary = 0.0;
	char rightBrace = 0;
	istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
	if (istrm.good()) {
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
			&& (Complex::rightBrace == rightBrace)) {
			re = real;
			im = imaganary;
		}
		else {
			istrm.setstate(ios_base::failbit);
		}
	}
	return istrm;
}
