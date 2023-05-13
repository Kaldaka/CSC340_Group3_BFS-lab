#include "graph.h"
#include "vertex.h"
#include "edge.h"

namespace NS_BFS_ALGO {

	//constructors defined
	Edge::Edge() : sourceVertex(Vertex()), destinationVertex(Vertex()), distance(0) {}
	Edge::Edge(Vertex sourceVertex, Vertex destinationVertex, int distance) : sourceVertex(sourceVertex), destinationVertex(destinationVertex), distance(distance) {}

	//mutators defined
	void Edge::setSourceVertex(Vertex newSourceVertex) { this->sourceVertex = newSourceVertex; }
	void Edge::setDestinationVertex(Vertex newDestinationVertex) { this->destinationVertex = newDestinationVertex; }
	void Edge::setDistance(int newDistance) { this->distance = newDistance; }

	//accessors defined
	Vertex Edge::getSourceVertex() { return this->sourceVertex; }
	Vertex Edge::getDestinationVertex() { return this->destinationVertex; }
	int Edge::getDistance() { return this->distance; }

}