#include "Graph.h"
#include "Vertex.h"
#include "LinkedList.h"
#include <queue>
#include <iostream>
#include <climits>
#include <list>


namespace NS_BFS_ALGO {
	//destructor
	Graph::~Graph() { 
		//might not be correct with list of lists
		graph->clear(); // Clear the list of adjacency lists
		delete graph;
	}

	//default constructor
	Graph::Graph() : treeSize(0) {
		try {
			this->graph = new std::list<LinkedList<Vertex>>();
		}
		catch (std::bad_alloc e) {
			std::cout << e.what() << "Encountered. Cannot initialize array.\n";
		}
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
        std::list<LinkedList<Vertex>>::iterator it;
        for (it = copy.graph->begin(); it != copy.graph->end(); ++it) {
            LinkedList<Vertex> newList;
            Iterator<Vertex> it2 (it->begin());
            while (it2.hasNext()) {
                Vertex vertex = *it2;
                newList.add(vertex);
                ++it2;
            }
            
            graph->push_back(newList);
        }

	}

	void Graph::addVertex(Vertex vertex) {
		LinkedList<Vertex> newLinkedList;
		newLinkedList.add(vertex);
		graph->push_back(newLinkedList);
		treeSize++;
	}

	
	bool Graph::addAdjacentVertex(int id, Vertex adjecentVertex) {
		std::list<LinkedList<Vertex>>::iterator it;
		for (it = graph->begin(); it != graph->end(); ++it) {
			Vertex currentVertex(it->getFirstValue());
			if (currentVertex.getId()==id){
				it->add(adjecentVertex);
				return true;
			}
		}
		return false;
	}



	void Graph::BFS(Vertex *s) {
        std::list<LinkedList<Vertex>>::iterator it;
		for (it = graph->begin(); it != graph->end(); ++it) {
            Iterator<Vertex> it2 = it->begin();
			(*it2).setColor("WHITE");
			(*it2).setDistance(INT_MAX);
			(*it2).setPredecessor(nullptr);
		}
		s->setColor("GRAY");
		s->setDistance(0);
		s->setPredecessor(nullptr);
		std::queue<Vertex*> Q;
		Q.push(s);
		while (!Q.empty()) {
			Vertex* u = Q.front();
			Q.pop();
            std::list<LinkedList<Vertex>>::iterator it;
		    for (it = graph->begin(); it != graph->end(); ++it) {
                if(it->getFirstValue().getId()==u->getId()){
                    Iterator<Vertex> it2 (it->begin());
                    while (it2.hasNext()) {
                        if ((*it2).getColor() == "WHITE") {
                            (*it2).setColor("GRAY");
                            (*it2).setDistance((*it2).getDistance() + 1);
                            (*it2).setPredecessor(u);
                            Vertex* v = &(*it2);
                            Q.push(v);
                        }
                        ++it2;
                    }
                    u->setColor("BLACK");
                }
            }
	    }
	}

    //TODO: modify params to poniters instead
	void Graph::printPath(const Graph &graph, const Vertex &sourceVertex, const Vertex &destinationVertex){
		if (destinationVertex == sourceVertex){
			std::cout<<sourceVertex.getId();
		}
		else if (destinationVertex.getPredecessor()==nullptr){
			std::cout<<"No path from "<<sourceVertex.getId()<< " to "<< destinationVertex.getId()<<std::endl;
		}
		else{
			printPath(graph, sourceVertex, *(destinationVertex.getPredecessor()));
			std::cout<< " -> " << destinationVertex.getId();
		}
	}

	

}
