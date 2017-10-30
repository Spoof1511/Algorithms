#include "SCCSolver.h"

#include <iostream>
#include <map>

const int verticesCount = 12;
std::vector<int> edges[verticesCount];

static void edge(char from, char to)
{
	edges[from - 'A'].push_back(to - 'A');
}

static void buildEdges()
{
	edge('A', 'B');
	edge('B', 'D');
	edge('B', 'C');
	edge('B', 'E');
	edge('E', 'B');
	edge('C', 'F');
	edge('F', 'C');
	edge('E', 'F');
	edge('E', 'G');
	edge('F', 'H');
	edge('I', 'G');
	edge('G', 'H');
	edge('G', 'J');
	edge('H', 'K');
	edge('K', 'L');
	edge('L', 'J');
	edge('J', 'I');
}

//const int verticesCount = 7;
//std::vector<int> edges[verticesCount];
//
//static void edge(int from, int to)
//{
//  edges[from - 1].push_back(to - 1);
//}
//
//static void buildEdges()
//{
//  edge(1, 2);
//  edge(2, 3);
//  edge(3, 1);
//  edge(4, 1);
//  edge(4, 5);
//  edge(5, 6);
//  edge(6, 4);
//  edge(6, 7);
//}

int main()
{
	buildEdges();

	auto solver = SCCSolver();

	solver.initialize(edges, verticesCount);
	solver.solve();
	for (auto component : solver.getResult())
	{
		for (int id : component)
		{
			//std::cout << id << ' ';
			std::cout << static_cast<char>(id + 'A') << ' ';
		}
		std::cout << std::endl;
	}

	system("pause");
}