#ifndef edge_h
#define edge_h

#include <iostream>

namespace NS_BFS_ALGO {

	class Edge {

		private:

			Vertex sourceVertex, destinationVertex;
			int distance;

		public:

			Edge();
			Edge(Vertex sourceVertex, Vertex destinationVertex,int distance);

			//mutators
			void setSourceVertex(Vertex newSourceVertex);
			void setDestinationVertex(Vertex newDestinationVertex);
			void setDistance(int newDistance);

			//accessors
			Vertex getSourceVertex();
			Vertex getDestinationVertex();
			int getDistance();
	};
}

#endif
