// Copyright 2018 by Igor Spiridonov under Free Public License 1.0.0

#include "complex.hpp"
#include <iostream>

Complex::Complex(const double real) : Complex(real, 0.0) {}

Complex::Complex(const double real,
    const double imaginary) : re(real), im(imaginary) {}

bool Complex::operator==(const Complex& rhs) const {
    return (re == rhs.re) && (im == rhs.im);
}

bool Complex::operator!=(const Complex& rhs) const {
    return !operator==(rhs);
}

Complex& Complex::operator+=(const double rhs) {
    return operator+=(Complex(rhs));
}

Complex& Complex::operator-=(const double rhs) {
    return operator-=(Complex(rhs));
}

Complex& Complex::operator*=(const double rhs) {
    return operator*=(Complex(rhs));
}

Complex& Complex::operator/=(const double rhs) {
    return operator/=(Complex(rhs));
}

Complex& Complex::operator+=(const Complex& rhs) {
    re += rhs.re;
    im += rhs.im;
    return *this;
}

Complex& Complex::operator-=(const Complex& rhs) {
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}

Complex& Complex::operator*=(const Complex& rhs) {
    int tempRe = re;
    re = (re * rhs.re) - (im * rhs.im);
    im = (tempRe * rhs.im) + (im * rhs.re);
    return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
    if (((rhs.re * rhs.re) + (rhs.im * rhs.im)) == 0) {
        throw std::exception("Divide by zero exception");
    }

    int tempRe = re;
    re = ((re * rhs.re) + (im * rhs.im))
        / ((rhs.re * rhs.re) + (rhs.im * rhs.im));
    im = ((im * rhs.re) - (tempRe * rhs.im))
        / ((rhs.re * rhs.re) + (rhs.im * rhs.im));
    return *this;
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const {
    ostrm << leftBrace << re << separator << im << rightBrace;
    return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm) {
    char leftBrace(0);
    double real(0.0);
    char comma(0);
    double imaganary(0.0);
    char rightBrace(0);
    istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
    if (istrm.good()) {
        if ((Complex::leftBrace == leftBrace)
            && (Complex::separator == comma) &&
            (Complex::rightBrace == rightBrace)) {
            re = real;
            im = imaganary;
        } else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}

std::ostream& operator<<(std::ostream& ostrm, const Complex & rhs) {
    return rhs.writeTo(ostrm);
}

std::istream& operator>>(std::istream& istrm, Complex& rhs) {
    return rhs.readFrom(istrm);
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
    Complex sum(lhs);
    sum += rhs;
    return sum;
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
    Complex sub(lhs);
    sub -= rhs;
    return sub;
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
    Complex mul(lhs);
    mul *= rhs;
    return mul;
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
    Complex div(lhs);
    div /= rhs;
    return div;
}
