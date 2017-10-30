////////////////////////////////////////////////////////////////////////////////
// Module Name:  main.cpp
// Authors:      Sergey Shershakov
// Version:      0.1.0
// Date:         01.05.2017
//
// This is a part of the course "Algorithms and Data Structures" 
// provided by  the School of Software Engineering of the Faculty 
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "rbtree.h"


using namespace std;


void simplestTest()
{
	using namespace xi;

	// просто создаем объект дерева 
	RBTree<int> tree1;
	tree1.insert(4);
	tree1.insert(50);
	tree1.insert(10);
	tree1.insert(40);
	tree1.insert(17);
	tree1.insert(35);
	tree1.insert(20);
}


int main()
{
    cout << "Hello, World!" << endl;

    simplestTest();

    return 0;
}