#ifndef graph_h
#define graph_h

#include <iostream>
#include <list>
#include "Vertex.h"
#include "LinkedList.h"

namespace NS_BFS_ALGO {

	class Graph {

	private:
		std::list<LinkedList<Vertex>> *graph; 
		int treeSize = 0;

	public:

		//big 3: deconstructor, constructor, copy constructor
		~Graph();
		Graph();
		Graph(const Graph& copy);

		//mutators
		void addVertex(Vertex vertex);
		bool addAdjacentVertex(int id, Vertex adjecentVertex);

		//main BFS method
		void BFS(Vertex *sourceVertex);

		//print path on tree structure
		void printPath(const Graph &graph, const Vertex &sourceVertex, const Vertex &destinationVertex);

		//prints entire tree structure
		void printTree(const Graph& graph);

	};
}

#endif
