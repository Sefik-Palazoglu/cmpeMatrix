#include <iostream>
#include <fstream>
#include <vector>

#include "Matrix.h"

using namespace std;

int main(int argc, char* argv[])
{
	ifstream inf{ argv[1] };
	ofstream outf{ argv[2] };

	int numofMatricesToMult;
	inf >> numofMatricesToMult;

	vector<Matrix> A;

	for (int i = 0; i < numofMatricesToMult; i++) {
		int m, n;
		inf >> m >> n;

		vector<vector<int>> entry(m, vector<int>(n));

		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				inf >> entry[j][k];
			}
		}

		A.push_back(Matrix(m, n, entry));
		cout << A[i]; // for debug
	}

	for (int i = A.size() - 1; i > 0; i--) {
		A[i - 1] = A[i] * A[i - 1];
	}

	cout << A[0];
	
}