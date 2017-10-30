#include "SCCSolver.h"
#include <stdexcept>
#include <algorithm>

Vertice::Vertice(int id)
{
	this->id = id;
}

void Vertice::refresh()
{
	discovered_step = -1;
	finished_step = -1;
	passed = false;
}

bool Vertice::compare(Vertice * v1, Vertice * v2)
{
	return (v1->finished_step) > (v2->finished_step);
}

void SCCSolver::initialize(std::vector<int>* adjList, int n)
{
	nVertices = n;
	adjacencyList = new std::vector<int>[nVertices];

	for (int i = 0; i < nVertices; i++) {
		adjacencyList[i]=adjList[i];
	}
	buildPool();
	initialized = true;
	solved = false;
}

void SCCSolver::solve()
{
	if (initialized == false) throw std::logic_error("Method called before initializing!");
	runDFS();
	sortPool();

	auto temp = adjacencyList;
	adjacencyList = reverseAdjacencyList(adjacencyList, nVertices);

	result = runDFS();

	solved = true;
}

std::vector<int>* SCCSolver::reverseAdjacencyList(std::vector<int>* adjList, int n)
{
	auto reversedAdj = new std::vector<int>[n];
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < adjList[i].size(); j++) {

			reversedAdj[adjList[i][j]].push_back(i);

		}
	}
	return reversedAdj;
}

std::vector<std::vector<int>> SCCSolver::getResult()
{
	if (solved == false) throw std::logic_error("Method called before solving!");
	return result;
}

bool SCCSolver::isSolved()
{
	return solved;
}

bool SCCSolver::isInitialized()
{
	return initialized;
}

void SCCSolver::buildPool()
{
	vertPool.resize(nVertices);

	for (int i = 0; i < nVertices; i++) {

		vertPool[i] = new Vertice(i);

	}

}

std::vector<std::vector<int>> SCCSolver::runDFS()
{
	refreshPool();

	int step = 0;
	std::vector<std::vector<int>> components;
	for (int i = 0; i < nVertices; i++) {
		if (vertPool[i]->passed==false) {
			components.push_back(std::vector<int>());
			DFSVisit(vertPool[i], step, components[components.size() - 1]);
		}
	}

	return components;
}

void SCCSolver::DFSVisit(Vertice * v, int & step, std::vector<int>& tree)
{
	v->discovered_step = step;
	v->passed = true;

	for (int i = 0; i < adjacencyList[v->id].size(); i++) {
		Vertice* temp = getVertice(adjacencyList[v->id][i]);
		if (temp->passed == false) {
			DFSVisit(temp, step, tree);
		}
	}
	step = step + 1;
	tree.push_back(v->id);
	v->finished_step = step;
}

void SCCSolver::sortPool()
{
	std::sort(vertPool.begin(), vertPool.end(), Vertice::compare);
}

void SCCSolver::refreshPool()
{
	for (int i = 0; i < nVertices; i++) {

		vertPool[i]->refresh();

	}
}

Vertice * SCCSolver::getVertice(int id)
{
	for (int i = 0; i < nVertices; i++) {

		if (vertPool[i]->id == id) {
			return vertPool[i];
		}

	}
	throw std::logic_error("Not correct id!");
}
