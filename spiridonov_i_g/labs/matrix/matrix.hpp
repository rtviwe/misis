#pragma once
#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrix
{
public:
	Matrix() = default;
	Matrix(const int rowSize, const int columnSize);
	Matrix(const Matrix& obj);

	~Matrix();

	int getRowSize() const;
	int getColumnSize() const;

	int& getElementAt(const int rowSize, const int columnSize);

	Matrix& operator=(const Matrix& rhs);
private:
	int rowSize_{ 0 };
	int columnSize_{ 0 };
	int** data_{ nullptr };
};

#endif
