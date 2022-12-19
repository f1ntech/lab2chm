#include <Windows.h>
#include <string>
#include <fstream>
#include "methods.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<vector<double>> matrixA = {
		{ 5.93, 1.12, 0.95, 1.32, 0.83 },
		{ 1.12, 3.53, 2.12, 0.57, 0.91 },
		{ 0.95, 2.12, 6.88, 1.29, 1.57 },
		{ 1.32, 0.57, 1.29, 3.82, 1.25 },
		{ 0.83, 0.91, 1.57, 1.25, 5.96}
	};
	vector<double> matrixB = { 7.24, 3.21, 3.23, 6.25, 6 };
	cout << "Matrix A|B:" << endl;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout.setf(ios::right, ios::adjustfield);
			cout.width(3);
			cout << matrixA[i][j] << " ";
		}
		cout.setf(ios::right, ios::adjustfield);
		cout.width(3);
		cout << " | " << matrixB[i] << endl;
	}

	methodIteration(matrixA, matrixB);
	return 0;
}
