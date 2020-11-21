#include "Matrix.h"
#include <iostream>
#include <cassert>

Matrix::Matrix(const Matrix& copy) : m_colLength{ copy.m_colLength }, 
	m_rowLength{ copy.m_rowLength }, m_entry{ copy.m_entry }
{
	// big problem
	std::cout << "Copy Constructor Called\n"; // for debug
}

Matrix::Matrix(int colLength, int rowLength, const vector<vector<data_t>>& entry) :
	m_colLength{ colLength }, m_rowLength{rowLength}, m_entry{entry}
{
	std::cout << "Standard Constructor Called\n"; // for debug
}

Matrix::Matrix(int colLength, int rowLength) : m_colLength{ colLength }, m_rowLength{ rowLength },
	m_entry{colLength, vector<Matrix::data_t>(rowLength)}
{
}

Matrix::Matrix(vector<vector<data_t>>& entry) : m_colLength{ static_cast<int>(entry.size()) }, 
	m_rowLength{ static_cast<int>(entry[0].size()) }, m_entry{ entry }
{
}

Matrix& Matrix::operator=(const Matrix& M)
{
	m_colLength = M.m_colLength;
	m_rowLength = M.m_rowLength;
	m_entry = M.m_entry;

	return *this;
}

int Matrix::getM() const
{
	return m_colLength;
}

int Matrix::getN() const
{
	return m_rowLength;
}

vector<Matrix::data_t>& Matrix::operator[](int index)
{
	return m_entry[index];
}

const vector<Matrix::data_t>& Matrix::operator[](int index) const
{
	return m_entry[index];
}

Matrix operator*(const Matrix& left, const Matrix& right)
{
	assert(left.m_rowLength == right.m_colLength && "Unallowed Matrix sizes for multiplication");

	int vectorLength = left.m_rowLength;

	Matrix result(left.getM(), right.getN());

	for (int i = 0; i < result.getM(); i++) {
		for (int j = 0; j < result.getN(); j++) {
			for (int k = 0; k < vectorLength; k++) {
				result[i][j] += left[i][k] * right[k][j];
			}
		}
	}

	return result;
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix)
{
	for (int i = 0; i < matrix.getM(); i++) {
		for (int j = 0; j < matrix.getN(); j++) {

			out << matrix[i][j] << '\t';
		}
		out << '\n';
	}
	out << '\n';

	return out;
}
