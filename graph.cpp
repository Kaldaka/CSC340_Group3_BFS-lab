#include "graph.h"
#include "vertex.h"
#include "edge.h"

#include <queue>
#include <iostream>

namespace NS_BFS_ALGO {

	//destructor
	Graph::~Graph() { 
		//might not be correct with list of lists
		delete[] graph;
		graph = nullptr;
	}

	//default constructor
	Graph::Graph() : treeSize(0) {
		try {
			this->graph = new std::list<std::pair<Vertex,Edge>>[this->treeSize];
		}
		catch (std::bad_alloc e) {
			std::cout << e.what() << " encountered. Cannot initialize array.\n";
		}
		graph->push_back({ Vertex(), Edge()});//TODO: fix
	}

	//copy constructor
	Graph::Graph(const Graph& copy) : treeSize(copy.treeSize) {
		try {
			delete this->graph;
			this->graph = copy.graph;
		}
		catch (std::bad_alloc e) {
			std::cout << e.what() << " encountered. Cannot initialize array.\n";
		}
		for (auto it = this->graph->begin(); it != this->graph->end(); it++){
			for (auto inner_it = it->begin(); inner_it != it->end(); inner_it++) {//TODO: fix
				//copy over inside list
			}
			//copy over outer list
		}
	}

	void Graph::addVertex(Vertex vertex) {
		//add vertex to graph structure
	}

	void Graph::addEdge(Edge edge) {
		//add edge between two vertices
	}

	void Graph::BFS(int s) {
		for (Vertex* u : vertices) {
		u->setColor("WHITE");
		u->setDistance(INT_MAX);
		u->setPredecessor(nullptr);
	    	}
	    	vertices[s]->setColor("GRAY");
	    	vertices[s]->setDistance(0);
	    	std::queue<Vertex*> Q;
	    	Q.push(vertices[s]);
	    	while (!Q.empty()) {
			Vertex* u = Q.front();
			Q.pop();
			for (Vertex* v : adj[u->getId()]) {
		    		if (v->getColor() == "WHITE") {
					v->setColor("GRAY");
					v->setDistance(u->getDistance() + 1);
					v->setPredecessor(u);
					Q.push(v);
		    		}
			}
			u->setColor("BLACK");
	    	}
	}

	void Graph::printPath(Graph graph, Vertex sourceVertex, Vertex destinationVertex){
		//implement recursive algorithm from class slides
	}

}
