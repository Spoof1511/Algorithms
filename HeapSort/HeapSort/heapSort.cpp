#include "heapSort.h"
#include <stdexcept>
#include <iostream>

void Heapsort::heapSort(int * arr, int n)
{
	Heap heaparr(arr, n);
	for (int i = 0; i < n; i++) {
		arr[i] = heaparr.extractMin();
	}

}

Heap::Heap(const int * source, const int n) :capacity()
{
	currentSize = 0;
	storage = new int[n];
	for (int i = 0; i < n; i++) {
		insert(source[i]);
	}
}

Heap::~Heap()
{
	delete[]storage;
}

int Heap::getMin()
{
	return storage[0];
}

int Heap::extractMin()
{
	int root = getMin();
		std::swap(storage[0], storage[--currentSize]);
		heapifyDown(0);
	return root;
}

void Heap::insert(const int value)
{
	storage[currentSize++] = value;
	heapifyUp(currentSize - 1);
}

void Heap::heapifyDown(int index)
{
	int lchild = (2 * index)+1;
	int rchild = (2 * index) + 2;
	int curr = currentSize;
	int small = index;
	(lchild < curr) && (storage[lchild] < storage[small]) ? small = lchild : false;
	(rchild < curr) && (storage[rchild] < storage[small]) ? small = rchild : false;
	(small != index) ? std::swap(storage[index], storage[small]), heapifyDown(small) : false;
}

void Heap::heapifyUp(int index)
{
	int root;
	(index % 2 == 0) ? root = (index / 2) - 1 : root = (index / 2);
	(storage[root] > storage[index]) && (root >= 0) ? std::swap(storage[index], storage[root]), heapifyUp(root) : false;
}

