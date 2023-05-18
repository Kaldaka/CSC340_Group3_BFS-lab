#ifndef vertex_h
#define vertex_h

#include <iostream>
#include <vector>
#include <string>
#include "graph.h"

namespace NS_BFS_ALGO {
	class Vertex {
	public:
		// Constructors
		Vertex();
		Vertex(int id);
		Vertex(int id, std::string color, int distance, Vertex* predecessor);
	
		// Copy Constructor
		Vertex(const Vertex& other);

		// Destructor
		~Vertex();

		// Setters
		void setColor(std::string color);
		void setPredecessor(Vertex* predecessor);
		void setDistance(int distance);
		void setId(int id);

		// Getters
		int getId();
		std::string getColor() const;
		Vertex* getPredecessor() const;
		int getDistance() const;
		
		//overload == operator
		bool operator==(const Vertex& other) const;

		private:
		int id;
		std::string color;
		Vertex* predecessor;
		int distance;
	};
}

#endif
