#ifndef METHODS_H
#define METHODS_H
#include <iostream>
#include <vector>
#define EPS 1e-4
using namespace std;
#define PATH "matrix.txt"
#define SIZE 5

vector<double> methodIteration(vector<vector<double>> matrixA, vector<double> matrixB);

bool check—onvergence(vector<vector<double>> matrixAlpha);

bool checkEPS(vector<double> result, vector<double> temp);
#endif
