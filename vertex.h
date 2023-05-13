#ifndef vertex_h
#define vertex_h

#include <iostream>

namespace NS_BFS_ALGO {

	class Vertex {

		private:

			int identifier = 0;
			std::string color = "na";
			int predecessor = 0;

		public:

			Vertex();
			Vertex(int identifier, std::string color, int predecessor);

			//mutators
			void setIdentifier(int newIdentifier);
			void setColor(std::string newColor);
			void setPredecessor(int newPredecessor);

			//accessors
			int getIdentifier();
			std::string getColor();
			int getPredecessor();
	};
}

#endif
