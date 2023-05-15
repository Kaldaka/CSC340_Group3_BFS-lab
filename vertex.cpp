#include "graph.h"
#include "vertex.h"
#include "edge.h"

namespace NS_BFS_ALGO {

	//constructor defined
	Vertex::Vertex() : id(0), color("WHITE"), distance(INT_MAX), predecessor(nullptr) {}
	Vertex::Vertex(int id) : id(id), color("WHITE"), distance(INT_MAX), predecessor(nullptr) {}


	//mutators defined
	void Vertex::setColor(std::string color) { this->color = color; }
	void Vertex::setDistance(int d) { this->distance = d; }
	void Vertex::setPredecessor(Vertex* p) { this->predecessor = p; }

	//accessors defined
	int Vertex::getId() { return this->id; }
	std::string Vertex::getColor() { return this->color; }
	int Vertex::getDistance() { return this->distance; }
	Vertex* Vertex::getPredecessor() { return this->predecessor; }

}
