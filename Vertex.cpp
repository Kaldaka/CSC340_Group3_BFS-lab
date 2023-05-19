#include "Graph.h"
#include "Vertex.h"
#include "climits"

namespace NS_BFS_ALGO {

	//constructor defined
	Vertex::Vertex() : id(0), color("WHITE"), distance(INT_MAX), predecessor(nullptr) {}
	Vertex::Vertex(int id) : id(id), color("WHITE"), distance(INT_MAX), predecessor(nullptr) {}
	
	Vertex::Vertex(int id, std::string color, int distance, Vertex* predecessore) {
		this->id = id;
		this->color = color;
		this->predecessor = predecessor;
		this->distance = distance;
	}

	// Copy Constructor
	Vertex::Vertex(const Vertex& other) {
        this->id = other.id;
		this->color = other.color;
		this->predecessor = other.predecessor;
		this->distance = other.distance;
	}

	// Destructor
	Vertex::~Vertex() {
		delete predecessor;
	}


	//mutators defined
	void Vertex::setColor(std::string color) { this->color = color; }
	void Vertex::setDistance(int d) { this->distance = d; }
	void Vertex::setPredecessor(Vertex* p) { this->predecessor = p; }
	void Vertex::setId(int id){this->id = id;}

	//accessors defined
	int Vertex::getId() const { return this->id; }
	std::string Vertex::getColor() const { return this->color; }
	int Vertex::getDistance() const{ return this->distance; }
	Vertex* Vertex::getPredecessor() const{ return this->predecessor; }


	//overload == operator
	bool Vertex::operator==(const Vertex& other) const {
		return (this->id == other.id &&
				this->color == other.color &&
				*(this->predecessor) == *(other.predecessor) &&
				this->distance == other.distance);
	}

}
