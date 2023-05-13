#ifndef graph_h
#define graph_h

#include <iostream>
#include <list>

namespace NS_BFS_ALGO {

	class Graph {

		private:

			std::list<std::pair<Vertex, Edge>>* graph = nullptr;
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
			void BFS(Graph graph, Vertex sourceVertex);

			//print path on tree structure
			void printPath(Graph graph, Vertex sourceVertex, Vertex destinationVertex);

	};
}

#endif
