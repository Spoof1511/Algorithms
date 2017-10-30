#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int* sortByInsert(int* kek, int N);
void shift_right(int arr[], int i, int index, int& swaps);
int binary_search(int kek[], int left, int right, int i, int& k);

int swa;
int main() {
		int N;

			bool fail = true;
			do
			{
				cout << "Enter N:\n ";
				cin >> N;
				if (cin.fail()||N<=0)
					cout << "Retype N: (N-int >0)!!!" << endl;
				else
					fail = false;

				cin.clear();
			
				cin.ignore(cin.rdbuf()->in_avail());
			} while (fail);
				
int *kek = new int[N];
		cout << "\nEnter 1 or 2:\n"; 
		int num;
		cin >> num;
		
		while (num != 1&&num!=2)
		{
			cout<< "Retype num(1 or 2): "<< endl;
			cin >>num;
		}
	
		switch (num) {
		case 1: {
			srand(time(0));
	
	
			for (int i = 0; i < N; i++) {
				kek[i] = rand() % 100;
	
			}
			break;
		}
		case 2: {
			cout << "\nEnter Array:\n";
			for (int i = 0; i < N; ++i)
			{
				cout << "Enter " << i << " element of array: ";
				cin >> kek[i];
				cin.sync();
	
			}
			break;
		}
		}
		cout << "\nFirst Array:\n";
		for (int i = 0; i < N; i++) {
			cout << " " << kek[i];
		}
		int* kek2 = new int[N];
		for (int i = 0; i < N; i++) {
			kek2[i]=kek[i];
		}

			int k = 0, num_swap = 0;
			int index = 0;
			int ku=0;
			for (int i = 1; i < N; i++) {
				if (kek[i] < kek[i - 1]) {
					ku++;
					shift_right(kek, i, binary_search(kek, 0, i - 1, i, k), num_swap);
				}
			}
			kek2 = sortByInsert(kek2, N); 
		cout << "\nSortedArray1:\n";
		for (int i = 0; i < N; i++) {
			cout << " " << kek[i];
		}
			cout <<"\n2)Swaps in outside cycle:"<< ku;
			cout << "\nIn inside cycle:" << swa;
		cout << "\nSortedArray2:\n";
		for (int i = 0; i < N; i++) {
			cout << " " << kek2[i];
		}
		delete[]kek;
		delete[]kek2;
		cout<<"\n";
		system("pause");

}
int* sortByInsert(int *kek, int N) {
	int temp;
	int last;
	int p=0;
	int swaps = 0;
	for (int k = 1; k < N; k++) {
		p++;
		temp = kek[k];
		last = k - 1;
		while (last >= 0 && kek[last]>temp) {
			swaps++;
			kek[last + 1] = kek[last];
			kek[last] = temp;
			last--;
		}
	}
	cout << "\n1)Swaps in outside cycle:" << p << "\nIn inside cycle:" << swaps;
	return kek;
}
void shift_right(int arr[], int i, int index, int& swaps)
{
	{int var_to_swap = arr[i];
	for (int k = i; k > index; k--) {

		arr[k] = arr[k - 1];
		swaps++;
	}
	arr[index] = var_to_swap;
	swaps++; }
	swa = swaps;
}
int binary_search(int kek[], int left, int right, int i, int& k)
{
	if (left > right)
		return left;

	int mid = (left + right) / 2;

	if (kek[i] > kek[mid]) {
		k++;
		binary_search(kek, mid + 1, right, i, k);
	}

	else {
		k++;
		binary_search(kek, left, mid - 1, i, k);
	}
}