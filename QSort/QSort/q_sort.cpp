#include "quick_sort.h"
#include <ctime>
#include  <iostream>



void q_sort::quick_sort_middle(int * arr, int n)
{
	quick_sort(arr, 0, n, get_middle_pivot);
}

void q_sort::quick_sort_last(int * arr, int n)
{
	quick_sort(arr, 0, n, get_last_pivot);
}

void q_sort::quick_sort_rand(int * arr, int n)
{
	quick_sort(arr, 0, n, get_rand_pivot);
}

int q_sort::get_middle_pivot(int from, int to)
{
	int middle_pivot;
	middle_pivot = (from+to) / 2;

	return middle_pivot;
}

int q_sort::get_last_pivot(int from, int to)
{
	int last_pivot = to - 1;
	return last_pivot;
}

int q_sort::get_rand_pivot(int from, int to)
{
	
	int rand_pivot = from + rand() % to-from;
	return rand_pivot;
}

void q_sort::quick_sort(int * arr, int from, int to, pivot_chooser pivot_chooser)
{
	if (from < to) {
		int p = rearrange_array_with_pivot(arr, from, to-1, pivot_chooser(from, to));
		quick_sort(arr, from, p, pivot_chooser);
		quick_sort(arr, p + 1, to, pivot_chooser);
	}
}

int q_sort::rearrange_array_with_pivot(int * arr, int from, int to, int pivot_index)
{
	int i = from-1;
	int j = to;
	int temp;
	while (true) {
		while (arr[i] < arr[pivot_index])  i++; 
		while (arr[j] > arr[pivot_index])  j--; 

		if(i >= j)
		{
			return i;
		}
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		
			i++;
			
	}
	return i;

}




