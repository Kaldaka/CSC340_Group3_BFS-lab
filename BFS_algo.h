#ifndef BFS_algo_h
#define BFS_algo_h

#include <iostream>
#include <vector>

namespace NS_BFS_ALGO {

	class Graph {

	private:
		int* graph;
		int vertex;
		int edge;

	public:
		//big 3: deconstructor, constructor, copy constructor
		~Graph();
		Graph();
		Graph(const Graph& copy);

		//mutators
		void addVertex(int vertex);
		void addEdge(int vertex1, int vertex2);

		//main BFS method
		void BFS(Graph graph, int sourceVertex);

		//print path on tree structure
		void printPath(Graph graph, int sourceVertex, int destinationVertex);

	};
}

#endif
