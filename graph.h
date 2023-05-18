#ifndef graph_h
#define graph_h

#include <iostream>
#include <vector>
#include <Vertex.h>
#include <LinkedList.h>

namespace NS_BFS_ALGO {

	class Graph {

	private:
		std::vector<LinkedList<Vertex> adj;
		int treeSize = 0;

	public:

		//big 3: deconstructor, constructor, copy constructor
		~Graph();
		Graph();
		Graph(const Graph& copy);

		//mutators
		void addVertex(Vertex vertex);
		void addEdge(Edge edge);

		//main BFS method
		void BFS(Vertex sourceVertex);

		//print path on tree structure
		void printPath(Graph graph, Vertex sourceVertex, Vertex destinationVertex);


	};
}

#endif
