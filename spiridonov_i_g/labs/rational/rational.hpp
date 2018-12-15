// Copyright 2018 by Igor Spiridonov under Free Public License 1.0.0

#pragma once
#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>

class Rational {
public:
    Rational() = default;

    explicit Rational(int numerator);

    Rational(int numerator, int denominator);

    ~Rational() = default;

    int getNumerator() const;

    void setNumerator(int num);

    int getDenominator() const;

    void setDenominator(int den);

    bool operator==(const Rational &rhs) const;

    bool operator!=(const Rational &rhs) const;

    Rational &operator+=(const Rational &rhs);

    Rational &operator+=(int rhs);

    Rational &operator-=(const Rational &rhs);

    Rational &operator-=(int rhs);

    Rational &operator*=(const Rational &rhs);

    Rational &operator*=(int rhs);

    Rational &operator/=(const Rational &rhs);

    Rational &operator/=(int rhs);

    void normalize();

    std::ostream &writeTo(std::ostream &ostrm) const;

    std::istream &readFrom(std::istream &istrim);

    static const char leftBrace{'{'};
    static const char separator{'/'};
    static const char rightBrace{'}'};

private:
    int num_{0};
    int den_{1};
};

std::ostream &operator<<(std::ostream &ostrm, const Rational &rhs);

std::istream &operator>>(std::istream &istrm, Rational &rhs);

Rational operator+(const Rational &lhs, const Rational &rhs);

Rational operator-(const Rational &lhs, const Rational &rhs);

Rational operator*(const Rational &lhs, const Rational &rhs);

Rational operator/(const Rational &lhs, const Rational &rhs);

#endif
