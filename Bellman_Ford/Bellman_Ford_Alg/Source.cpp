#include "bellman_ford.h"
#include <iostream>
#include "bellman_ford.cpp"

using namespace std;
int main() {
	BellmanFord task;
	int n, m;

	int** array = new int*[4];
	array[0] = new int[3];
	array[1] = new int[3];
	array[2] = new int[3];
	array[3] = new int[3];
	array[0][0] = 1;
	array[0][1] = 2;
	array[0][2] = 1;

	array[1][0] = 2;
	array[1][1] = 3;
	array[1][2] = 2;

	array[2][0] = 3;
	array[2][1] = 4;
	array[2][2] = 3;

	array[3][0] = 1;
	array[3][1] = 3;
	array[3][2] = 2;

	task.initialize(array, 4, 4, 1);
	task.solvePositive();

	system("pause");
}