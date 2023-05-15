#ifndef vertex_h
#define vertex_h

#include <iostream>

namespace NS_BFS_ALGO {

	class Vertex {

		private:
			int num_vertices;
			std::vector<Vertex*> vertices;
			std::vector<std::list<Vertex*>> adj;

		public:
			Graph(int num_vertices);
		    	~Graph();

			void addEdge(int u, int v);
			void BFS(int s);
			void printPath(int s, int v);
	};
}

#endif
