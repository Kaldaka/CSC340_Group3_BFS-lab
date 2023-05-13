#include "graph.h"
#include "vertex.h"
#include "edge.h"

namespace NS_BFS_ALGO {

	//constructor defined
	Vertex::Vertex() : identifier(0), color("white"), predecessor(-1) {}

	//mutators defined
	void Vertex::setIdentifier(int newIdentifier) { this->identifier = newIdentifier; }
	void Vertex::setColor(std::string newColor) { this->color = newColor; }
	void Vertex::setPredecessor(int newPredecessor) { this->predecessor = newPredecessor; }

	//accessors defined
	int Vertex::getIdentifier() { return this->identifier; }
	std::string Vertex::getColor() { return this->color; }
	int Vertex::getPredecessor() { return this->predecessor; }

}