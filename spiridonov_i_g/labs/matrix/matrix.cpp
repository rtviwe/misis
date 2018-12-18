// Copyright 2018 by Igor Spiridonov under Free Public License 1.0.0

#include <iostream>
#include "matrix.hpp"

Matrix::Matrix(const int rowSize, const int columnSize)
        : rowSize_(rowSize), columnSize_(columnSize) {
    data_ = new int *[rowSize_];

    for (int i(0); i < rowSize_; i++) {
        data_[i] = new int[columnSize_];

        for (int j(0); j < columnSize_; j++) {
            data_[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix &obj)
        : rowSize_(obj.rowSize_), columnSize_(obj.columnSize_) {
    data_ = new int *[rowSize_];

    for (int i(0); i < rowSize_; i++) {
        data_[i] = new int[columnSize_];

        for (int j(0); j < columnSize_; j++) {
            data_[i][j] = obj.data_[i][j];
        }
    }
}

Matrix::~Matrix() {
    delete[] data_;
}

int &Matrix::getElementAt(const int rowSize, const int columnSize) {
    if (rowSize < 0) {
        throw std::exception("Size of row should not be negative");
    }

    if (columnSize < 0) {
        throw std::exception("Size of column should not be negative");
    }

    if (rowSize > rowSize_) {
        throw std::exception("Row size should be less than row size of matrix");
    }

    if (columnSize > columnSize_) {
        throw std::exception(
                "Column size should be less than column size of matrix");
    }

    return data_[rowSize][columnSize];
}

int Matrix::getRowSize() {
    return rowSize_;
}

int Matrix::getRowSize() const {
    return rowSize_;
}


int Matrix::getColumnSize() {
    return columnSize_;
}

int Matrix::getColumnSize() const {
    return columnSize_;
}

Matrix &Matrix::operator=(const Matrix &rhs) {
    columnSize_ = rhs.columnSize_;
    rowSize_ = rhs.rowSize_;

    for (int i(0); i < rowSize_; i++) {
        data_[i] = new int[columnSize_];

        for (int j(0); j < columnSize_; j++) {
            data_[i][j] = rhs.data_[i][j];
        }
    }

    return *this;
}

std::ostream &operator<<(std::ostream &ostrm, const Matrix &matrix) {
    return matrix.writeTo(ostrm);
}

std::ostream &Matrix::writeTo(std::ostream &ostrm) const {
    for (int i = 0; i < rowSize_; i += 1) {
        for (int j = 0; j < columnSize_; j += 1) {
            ostrm << data_[i][j] << " ";
        }
        ostrm << std::endl;
    }
    return ostrm;
}
