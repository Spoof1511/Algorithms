#include "bellman_ford.h"
#include <stdexcept>
#include <algorithm>

void BellmanFord::initialize(int ** array, int n, int m, int startV)
{
	numVertexes = m;
	numEdges = n;
	start = --startV;
	graph.resize(numVertexes);


	for (int i = 0; i < numVertexes; i++)
	{
		graph[i].from = array[i][0] - 1;
		graph[i].to = array[i][1] - 1;
		graph[i].cost = array[i][2];
	}

	initialized = true;
}

bool BellmanFord::isInitialized()
{
	return initialized;
}

void BellmanFord::solve()
{
	if (!initialized) throw std::logic_error("Method called before initiliazation!");

	const int INF = INT_MAX;
	auto dist = std::vector<int>(numVertexes, INF);
	auto parrens = std::vector<std::pair<int, int>>(numVertexes, std::make_pair(-1, INF));
	path = new std::vector<int>[numVertexes - 1];
	dist[start] = 0;
	minCost = 0;

	for (int i = 0; i < numVertexes - 1; i++) {
		for (int j = 0; j < graph.size(); j++) {
			int from = graph[j].from;
			int to = graph[j].to;
			int cost = graph[j].cost;

			if (dist[from] != INF && dist[to] > dist[from] + cost) {
				dist[to] = dist[from] + cost;
				parrens[to] = std::make_pair(from, cost);
			}
		}
	}

	for (int k = 0; k < graph.size(); k++) {
		int from = graph[k].from;
		int to = graph[k].to;
		int cost = graph[k].cost;
		if (dist[from] != INF && dist[to] > dist[from] + cost) {
			int temp = to;

			for (int m = 0; m < numVertexes; m++) {
				temp = parrens[temp].first;
			}
			int vert = temp;

			do {
				minCost += parrens[vert].second;
				vert = parrens[vert].first;
				path->push_back(vert + 1);
			} while (vert != temp);
			std::reverse(path->begin(), path->end());
			return;
		}
	}

	std::vector<std::pair<int, std::vector<int>>> nPathes;
    std::pair<int, std::vector<int>> newPath;

	for (int i = 0; i < numVertexes; i++)
	{
		if ((i == start )|| (dist[i] == INF)) {
			continue;
		}

		int newVert = i;
		while (newVert!=start)
		{
			newPath.second.push_back(newVert + 1);
			newPath.first += parrens[newVert].second;
			newVert = parrens[newVert].first;
		}
		newPath.second.push_back(start + 1);

		std::reverse(newPath.second.begin(), newPath.second.end());

		nPathes.push_back(newPath);
	}


	std::sort(nPathes.begin(), nPathes.end());
	for (int i = 0; i < nPathes.size(); i++) {
		path[i] = nPathes[i].second;
	}

}

void BellmanFord::solveNegative()
{
	solve();//))
}

void BellmanFord::solvePositive()
{
	solve();//))
}

int BellmanFord::getCost()
{
	return minCost;
}

std::vector<int>* BellmanFord::getPath()
{
	return path;
}

BellmanFord::~BellmanFord()
{
	delete[]path;
	graph.clear();
}
