#include "BFS_algo.h"

namespace NS_BFS_ALGO {

	Graph::~Graph() {
		delete[] graph;
		graph = nullptr;
	}

	Graph::Graph() : vertex(0), edge(0) {
		//do something to initialize graph array object
		//use different structure than array?
	}

	Graph::Graph(const Graph& copy) : vertex(copy.vertex), edge(copy.edge) {
		//copy graph structure
	}

	void Graph::addVertex(int vertex) {
		//add vertex to graph structure
	}

	void Graph::addEdge(int vertex1, int vertex2) {
		//add edge between two vertices
	}

	void Graph::BFS(Graph graph, int sourceVertex) {
		//implement pseudo code from class slides
	}

	void Graph::printPath(Graph graph, int sourceVertex, int destinationVertex){
		//implement recursive algorithm from class slides
	}

}