#ifndef graph_h
#define graph_h

#include <iostream>
#include <list>
#include "Vertex.h"
#include "LinkedList.h"

namespace NS_BFS_ALGO {

	class Graph {

	private:
		std::list<LinkedList<Vertex>*> *graph; 
		int treeSize = 0;

        //print path on tree structure
		void printPath(Vertex* sourceVertex, Vertex* destinationVertex);
	public:

		//big 3: deconstructor, constructor, copy constructor
		~Graph();
		Graph();
		Graph(const Graph& copy);

		//mutators
		void addVertex(Vertex vertex);
		bool addAdjacentVertex(int id, int adjId);

		//main BFS method
		void BFS(int sourceID);

        //print path on tree structure
		void printPath(int sourceId, int destinationId);

		//prints entire tree structure
		void printTree();

	};
}

#endif
