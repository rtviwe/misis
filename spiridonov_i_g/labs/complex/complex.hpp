// Copyright 2018 by Igor Spiridonov under Free Public License 1.0.0

#pragma once
#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

struct Complex {
    Complex() = default;

    explicit Complex(double real);

    Complex(double real, double imaginary);

    ~Complex() = default;

    bool operator==(const Complex &rhs) const;

    bool operator!=(const Complex &rhs) const;

    Complex &operator+=(const Complex &rhs);

    Complex &operator+=(double rhs);

    Complex &operator-=(const Complex &rhs);

    Complex &operator-=(double rhs);

    Complex &operator*=(const Complex &rhs);

    Complex &operator*=(double rhs);

    Complex &operator/=(const Complex &rhs);

    Complex &operator/=(double rhs);

    std::ostream &writeTo(std::ostream &ostrm) const;

    std::istream &readFrom(std::istream &istrim);

    double re{0.0};
    double im{0.0};

    static const char leftBrace{'{'};
    static const char separator{','};
    static const char rightBrace{'}'};
};

std::ostream &operator<<(std::ostream &ostrm, const Complex &rhs);

std::istream &operator>>(std::istream &istrm, Complex &rhs);

Complex operator+(const Complex &lhs, const Complex &rhs);

Complex operator-(const Complex &lhs, const Complex &rhs);

Complex operator*(const Complex &lhs, const Complex &rhs);

Complex operator/(const Complex &lhs, const Complex &rhs);

#endif
