#include "methods.h"
using namespace std;

vector<double> methodIteration(vector<vector<double>> matrixA, vector<double> matrixB)
{
	vector<vector<double>> matrixAlpha;
	vector<double> matrixBeta;

	for (int i = 0; i < SIZE; i++)
	{
		vector<double> temp;
		for (int k = 0; k < SIZE; k++)
		{
			if (k == i)
			{
				temp.push_back(0);
			}
			else
			{
				temp.push_back(-matrixA[i][k] / matrixA[i][i]);
			}
		}
		matrixBeta.push_back(matrixB[i] / matrixA[i][i]);
		matrixAlpha.push_back(temp);
	}
	cout << endl << "Matrix C|d" << endl;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout.setf(ios::right, ios::adjustfield);
			cout.width(5);
			cout << fixed;
			cout.precision(4);
			cout << matrixAlpha[i][j] << " ";
		}
		cout << "\t|";
		cout.setf(ios::right, ios::adjustfield);
		cout.width(5);
		cout << fixed;
		cout.precision(4);
		cout << matrixBeta[i] << endl;
	}
	if (!checkÑonvergence(matrixAlpha)) wcout << "Â³äñóòíÿ ä³àãîíàëüíà ïåðåâàãà" << endl;
	else wcout << "Ïðèñóòíÿ ä³àãîíàëüíà ïåðåâàãà" << endl;

	vector<double> result = matrixBeta;
	vector<double> temp;
	int iteration = 0;
	cout << endl;
	cout << "Method Iteration\t\t\t\tâåêòîð íåâ'ÿçêè" << endl;
	do
	{
		temp = result;
		for (int i = 0; i < SIZE; i++)
		{
			double sum = matrixBeta[i];
			for (int k = 0; k < SIZE; k++)
			{
				if (abs(matrixAlpha[i][k]) > EPS)
				{
					sum += matrixAlpha[i][k] * temp[k];
				}
			}
			result[i] = sum;
		}
		iteration++;
		for (int i = 0; i < SIZE; i++) {
			cout.setf(ios::right, ios::adjustfield);
			cout.width(5);
			cout << fixed;
			cout.precision(4);
			cout << result[i] << "\t";
		}
	} while (checkEPS(result, temp));
	cout << endl << "Result:" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout.setf(ios::right, ios::adjustfield);
		cout.width(5);
		cout << fixed;
		cout.precision(4);
		cout << result[i] << endl;
	}

	cout << "Iteration: " << iteration << endl;


	return result;
}

bool checkEPS(vector<double> result, vector<double> temp)
{
	vector<double> delta;
	double max = abs(result[0] - temp[0]);
	delta.push_back(max);
	for (int i = 1; i < SIZE; i++)
	{
		double num = abs(result[i] - temp[i]);
		delta.push_back(num);
		if (max < num)
			max = num;
	}
	cout << "(";
	for (int i = 0; i < SIZE - 1; i++) {
		cout << fixed;
		cout.precision(5);
		cout << delta[i] << ", ";
	}
	cout << delta[SIZE - 1];
	cout << ")" << endl;
	if (max < EPS) return false;
	return true;
}

bool checkÑonvergence(vector<vector<double>> matrixAlpha)
{
	for (int i = 0; i < SIZE; i++)
	{
		double temp = 0;
		for (int k = 0; k < SIZE; k++)
		{
			temp += matrixAlpha[i][k];
		}
		if (temp > 1)	return false;
	}
	return true;
}

