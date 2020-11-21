#ifndef MATRIX_H
#define MATRIX_H

using namespace std;

#include <vector>
#include <iostream>

class Matrix
{
	using data_t = int;
	int m_colLength{}; // m in math201
	int m_rowLength{}; // n in math201
	vector<vector<data_t>> m_entry;

public:

	Matrix() = default;
	Matrix(const Matrix& copy);
	Matrix(int colLength, int rowLength, const vector<vector<data_t>>& entry);
	Matrix(int colLength, int rowLength);
	Matrix(vector<vector<data_t>>& entry);

	Matrix& operator=(const Matrix& M);

	int getM() const;
	int getN() const;

	vector<data_t>& operator[](int index);
	const vector<data_t>& operator[](int index) const;

	friend Matrix operator*(const Matrix& left, const Matrix& right);

};

std::ostream& operator<< (std::ostream& out, const Matrix& matrix);

#endif // !MATRIX_H
