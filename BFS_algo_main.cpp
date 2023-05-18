/***
CSC340_Group3_BFS - lab.cpp
Last lab of CSC340 at SFSU
Uses Breadth-first search algorithm to explore tree structures

Created by:
    Abdarrahman Ayyaz
    Dyllan Grossman
    Elliot Warren
    Mohammed Deeb
***/

#include "Graph.h"
#include "Vertex.h"
using namespace NS_BFS_ALGO;

int main()
{
    //call BFS method and mutators 
    //print out tree from given vertex
    //print shortest bath from source vertex (s) to destination vertex (v) using recursive algorithm 
    
    Graph g;

    Vertex v0(0);
    Vertex v1(1);
    Vertex v2(2);
    Vertex v3(3);
    Vertex v4(4);
    Vertex v5(5);
    
    g.addVertex(v0);
    g.addVertex(v1);
    g.addVertex(v2);
    g.addVertex(v3);
    g.addVertex(v4);
    g.addVertex(v5);

    g.addAdjacentVertex(1, v3);
    g.addAdjacentVertex(2, v3);
    g.addAdjacentVertex(4, v3);
    g.addAdjacentVertex(0, v1);
    g.addAdjacentVertex(3, v0);
    g.addAdjacentVertex(5, v2);
    g.addAdjacentVertex(1, v5);

    g.BFS(0);
    std::cout << "\nShortest path from 0 to 4: ";
    g.printPath(0, 4);

    return 0;
    
}
