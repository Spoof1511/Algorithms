// Учебная практика 2016
// Исаков Алан 154 группа


#include <iostream>
#include <fstream>
#include <ctime>
#include <Windows.h>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <chrono>
using namespace std;
enum Arraytype { Random7, RandomMaxint, AlmostSort, ReverseArr };
void bubble1(int n, int*  copy);
void bubble2(int n, int*  copy);
void bubble3(int n, int*  copy);
void insert(int n, int*  copy);
void bin_insert(int n, int* copy);
void copy_arr(int n, int*  arr, int* p);
void Sort(int* arraytype, void(*functype)(int, int*));
int search_index(int right, int value, int* arr);
typedef long long ll;
typedef unsigned long long ull;

void GenerateArray(int * arr, Arraytype type);
ofstream str("res.csv");
int main() {
	int* random7array = new int[9000];
	GenerateArray(random7array, Random7);
	int* randomMaxint = new int[9000];
	GenerateArray(randomMaxint, RandomMaxint);
	int* sortedarray = new int[9000];
	GenerateArray(sortedarray, AlmostSort);
	int* reversearray = new int[9000];
	GenerateArray(reversearray, ReverseArr);
	string func_name[5] = { "bubble1","bubble2","bubble3","insert","bin_insert" };
	string array_name[4] = { "random7array","randomMaxint","sortedarray","reversearray" };
	void(*functionTypes[5])(int, int*) = { bubble1,bubble2,bubble3,insert,bin_insert };
	int *arrayTypes[4] = { random7array,randomMaxint,sortedarray,reversearray };
	for (int i = 0; i < 5; i++) {
		str << "FuncType: " << func_name[i] << endl;
		for (int j = 0; j <  4; j++) {
			str << "ArrType: "  << array_name[j] << endl;;
			Sort(arrayTypes[j], functionTypes[i]);
			cout << "LOADING 100% " << endl;
		}
		cout << "\n";
	}
	str.close();
	system("pause");
}

void GenerateArray(int * arr, Arraytype type) {
	for (int i = 0; i < 9000; i++) {
		cout << i << endl;
		if (type == Random7) arr[i] = rand() % 7;
		if (type == RandomMaxint) arr[i] = rand();
		if (type == AlmostSort) {
			arr[i] = rand(); bubble1(9000, arr);
			for (int m = 0; m < 10; m++)
			{
			
				int k = rand() % 9000;
				int j = rand() % 9000;
				swap(arr[k], arr[j]);
			}
		}
		if (type == ReverseArr) {
			arr[i] = -(rand() % 9000);
			bubble1(9000, arr);
			for (int h = 0; h < 9000; h++) {
				arr[h] = -arr[h];
			}
		}

	}
}

void Sort(int* arraytype, void(*functype)(int, int*)) {
	ll sum = 0;
	ll current;
	ll maxim = 0;
	const int n = 9000, step = 1000;
	int *p = new int[n], count = 0;

	for (int i = 0; i < n / step; ++i)
	{
		count += step;
		cout << " LOAGING " << i * 10 << "%" << endl;
		for (int t = 0; t < 100; ++t)
		{
			copy_arr(count, arraytype, p);

			auto first = chrono::high_resolution_clock::now();
			functype(count, p);
			auto second =chrono::high_resolution_clock::now();
			current =chrono::duration_cast<chrono::nanoseconds> (second - first).count();

			sum += current;
			maxim = max(maxim, current);
		}
		ll average = sum / 100.0;
		str << average << ';' << maxim << endl;
		cout << average << "--" << maxim << endl;
	}
	delete[]p;
}
void copy_arr(int n, int*  arr, int* p)
{
	for (int i = 0; i < n; ++i)
		p[i] = arr[i];
}

void bubble1(int n, int*  copy)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (copy[j] > copy[j + 1])
			{
				swap(copy[j], copy[j + 1]);
			}
		}
	}
}
void bubble2(int n, int*  copy)
{
	int i = 0;
	bool t = true;
	while (t)
	{
		t = false;
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (copy[j] > copy[j + 1])
			{
				swap(copy[j], copy[j + 1]);
				t = true;
			}
		}
		i = i + 1;
	}

}
void bubble3(int n, int*  copy)
{
	int a = n - 1;
	int b = n - 1;
	for (int i = 0; i < n - 1; ++i)
	{
		bool fl = false;
		for (int j = 0; j < b; ++j)
			if (copy[j] > copy[j + 1])
			{
				fl = true;
				swap(copy[j], copy[j + 1]);
				a = j;
			}
		--b;
		if (b > a)
			b = a;

		if (!fl)
			break;
	}
	return;
}
void insert(int n, int*  copy)
{
	for (int i = 1, j; i < n; ++i)
	{
		j = i;
		while (j >= 1 && copy[j] < copy[j - 1])
		{
			swap(copy[j], copy[j - 1]);
			--j;
		}
	}

}

void bin_insert(int n, int*  copy)
{
	for (int i = 1, j; i < n; ++i)
	{
		j = i;
		int index = search_index(i, copy[i], copy);
		while (j != index)
		{
			swap(copy[j], copy[j - 1]);
			--j;
		}
	}
}

int search_index(int right, int value, int* arr)
{
	int l = 0, r = right, m;
	do
	{
		m = (r - l) / 2 + l;
		if (arr[m] > value)
			r = m;
		else
			l = m;
	} while (r - l > 1);
	if (arr[l] <= value)
		return r;
	else
		return l;

}