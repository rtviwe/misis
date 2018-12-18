// Copyright 2018 by Igor Spiridonov under Free Public License 1.0.0

#pragma once
#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrix {
public:
    Matrix() = default;

    Matrix(int rowSize, int columnSize);

    Matrix(const Matrix &obj);

    ~Matrix();

    int getRowSize();

    int getRowSize() const;

    int getColumnSize();

    int getColumnSize() const;

    int &getElementAt(int rowSize, int columnSize);

    std::ostream &writeTo(std::ostream &ostrm) const;

    Matrix &operator=(const Matrix &rhs);

private:
    int rowSize_{0};
    int columnSize_{0};
    int **data_{nullptr};
};

std::ostream &operator<<(std::ostream &ostrm, const Matrix &matrix);

#endif
