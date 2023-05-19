#include "Graph.h"
#include "Vertex.h"
#include "LinkedList.h"
#include <queue>
#include <iostream>
#include <climits>
#include <list>

namespace NS_BFS_ALGO {
    using namespace std;
	// Destructor
	Graph::~Graph() {
		// Clear the list of adjacency lists
		for (auto it = graph->begin(); it != graph->end(); ++it) {
			delete *it;
		}
		delete graph;
	}

	// Default constructor
	Graph::Graph() : treeSize(0) {
		try {
			this->graph = new std::list<LinkedList<Vertex>*>();
		}
		catch (std::bad_alloc& e) {
			std::cout << e.what() << " Encountered. Cannot initialize array.\n";
		}
	}

	// Copy constructor
	Graph::Graph(const Graph& copy) : treeSize(copy.treeSize) {
		try {
			this->graph = new std::list<LinkedList<Vertex>*>();
		}
		catch (std::bad_alloc& e) {
			std::cout << e.what() << " encountered. Cannot initialize array.\n";
		}
		for (auto it = copy.graph->begin(); it != copy.graph->end(); ++it) {
			LinkedList<Vertex>* newList = new LinkedList<Vertex>();
			Iterator<Vertex> it2 ((*it)->begin());
			while (it2.hasNext()) {
				Vertex* vertex = *it2;
				newList->add(vertex);
                ++it2;
			}
			graph->push_back(newList);
		}
	}

	// Add a vertex to the graph
	void Graph::addVertex(Vertex vertex) {
		LinkedList<Vertex>* newLinkedList = new LinkedList<Vertex>();
        Vertex* v = new Vertex(vertex);
		newLinkedList->add(v);
		graph->push_back(newLinkedList);
		treeSize++;
	}

	// Add an adjacent vertex to a specific vertex
	bool Graph::addAdjacentVertex(int id, int adjId) {
        Vertex *adj;
        for (auto it = graph->begin(); it != graph->end(); ++it) {
			Iterator<Vertex> it2 = (*it)->begin();
            if ((*it2)->getId()==adjId){
                adj = *it2;
                break;
            }
		}
		for (auto it = graph->begin(); it != graph->end(); ++it) {
			Iterator<Vertex> it2 = (*it)->begin();
			if (it2->getId() == id) {
				(*it)->add(adj);
				return true;
			}
		}
		return false;
	}


   void Graph::BFS(int sourceID) {
        std::queue<Vertex*> Q;
        for (auto it = graph->begin(); it != graph->end(); ++it) {
            Iterator<Vertex> it2 = (*it)->begin();
            if ((*it2)->getId()==sourceID){
                (*it2)->setColor("GRAY");
                (*it2)->setDistance(0);
                (*it2)->setPredecessor(nullptr);
                Q.push(*it2);
            }
            else{
                Vertex* vertex = *it2;
                vertex->setColor("WHITE");
                vertex->setDistance(INT_MAX);
                vertex->setPredecessor(nullptr);
            }
        }

        while (!Q.empty()) {
            Vertex* u = Q.front();
            Q.pop();

            for (auto it = graph->begin(); it != graph->end(); ++it) {
                Iterator<Vertex> it2 = (*it)->begin();
                if ((*it2)->getId() ==u->getId()) {
                    Iterator<Vertex> prev = it2;
                    while (prev.hasNext()) {
                        Vertex* vertex = *it2;
                        if (vertex->getColor() == "WHITE") {
                            vertex->setColor("GRAY");
                            vertex->setDistance(vertex->getDistance() + 1);
                            vertex->setPredecessor(u);
                            Q.push(vertex);
                        }
                        prev = it2;
                        ++it2;
                    }
                }
            }
            u->setColor("BLACK");
        }
    }

    void Graph::printPath(Vertex* sourceVertex, Vertex* destinationVertex) {
        if (destinationVertex == sourceVertex) {
            std::cout << sourceVertex->getId();
        }
        else if (destinationVertex->getPredecessor() == nullptr) {
            std::cout << "No path from " << sourceVertex->getId() << " to " << destinationVertex->getId() << std::endl;
        }
        else {
            printPath(sourceVertex, destinationVertex->getPredecessor());
            std::cout << " -> " << destinationVertex->getId();
        }
    }

    //print path on tree structure
	void Graph::printPath(int sourceId, int destinationId){
        Vertex* sourceVertex;
        Vertex* destinationVertex;
        for (auto it = graph->begin(); it != graph->end(); ++it) {
            Iterator<Vertex> it2 = (*it)->begin();
            if ((*it2)->getId()==sourceId){
                sourceVertex=*it2;
            }
            if ((*it2)->getId()==destinationId){
                destinationVertex=*it2;
            }
        }
        printPath(sourceVertex, destinationVertex);
    }

    void Graph::printTree() {
        for (auto it = graph->begin(); it != graph->end(); ++it) {
            Iterator<Vertex> it2 = (*it)->begin();
            Vertex* v = *it2;
           while (it2.hasNext()) {
                ++it2;
                Vertex* currentVertex = *it2;
                std::cout << v->getId() << ":" << v->getColor() << "->" << currentVertex->getId() << ":" << currentVertex->getColor() << std::endl;
            }
            std::cout << std::endl;
        }
    }
}
