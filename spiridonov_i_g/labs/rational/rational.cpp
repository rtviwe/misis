#include <iostream>
#include <sstream>
#include "rational.hpp"

Rational::Rational(const int numerator)
    : num_(numerator), den_(1) {
}

Rational::Rational(const int numerator, const int denominator)
    : num_(numerator), den_(denominator) {
    normalize();
}

int Rational::getNumerator() const {
    return num_;
}

void Rational::setNumerator(const int numerator) {
    num_ = numerator;
}

int Rational::getDenominator() const {
    return den_;
}

void Rational::setDenominator(const int denominator) {
    if (den_ != 0) {
        den_ = denominator;
    } else {
        throw std::exception("Divide by zero exception");
    }
}

bool Rational::operator==(const Rational& rhs) const {
    return (num_ == rhs.num_) && (den_ == rhs.den_);
}

bool Rational::operator!=(const Rational& rhs) const {
    return !operator==(rhs);
}

Rational& Rational::operator+=(const int rhs) {
    return operator+=(Rational(rhs));
}

Rational& Rational::operator-=(const int rhs) {
    return operator-=(Rational(rhs));
}

Rational& Rational::operator*=(const int rhs) {
    return operator*=(Rational(rhs));
}

Rational& Rational::operator/=(const int rhs) {
    return operator/=(Rational(rhs));
}

Rational& Rational::operator+=(const Rational& rhs) {
    num_ = num_ * rhs.den_ + rhs.num_ * den_;
    den_ *= rhs.den_;
    normalize();
    return *this;
}

Rational& Rational::operator-=(const Rational& rhs) {
    num_ = num_ * rhs.den_ - rhs.num_ * den_;
    den_ *= rhs.den_;
    normalize();
    return *this;
}

Rational& Rational::operator*=(const Rational& rhs) {
    num_ *= rhs.num_;
    den_ *= rhs.den_;
    normalize();
    return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
    num_ *= rhs.den_;
    den_ *= rhs.num_;
    normalize();
    return *this;
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const {
    ostrm << leftBrace << num_ << separator << den_ << rightBrace;
    return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm) {
    char leftBrace(0);
    int numerator(0);
    char separator(0);
    int denominator(0);
    char rightBrace(0);

    istrm >> leftBrace >> numerator >> separator >> denominator >> rightBrace;

    if (istrm.good()) {
        if ((Rational::leftBrace == leftBrace)
            && (Rational::separator == separator)
            && (Rational::rightBrace == rightBrace)) {
            num_ = numerator;
            den_ = denominator;
        } else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

void Rational::normalize() {
    if (num_ != 0 && den_ != 0) {
        int div = gcd(num_, den_);
        num_ /= div;
        den_ /= div;
    }

    if (den_ < 0) {
        num_ = -num_;
        den_ = -den_;
    }
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
    return rhs.writeTo(ostrm);
}

std::istream& operator>>(std::istream& istrm, Rational& rhs) {
    return rhs.readFrom(istrm);
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    Rational sum(lhs);
    sum += rhs;
    return sum;
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    Rational sub(lhs);
    sub -= rhs;
    return sub;
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    Rational mul(lhs);
    mul *= rhs;
    return mul;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    Rational div(lhs);
    div /= rhs;
    return div;
}
