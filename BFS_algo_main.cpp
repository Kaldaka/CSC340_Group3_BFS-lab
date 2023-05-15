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

#include "graph.h"
#include "vertex.h"
using namespace NS_BFS_ALGO;

int main()
{
    //call BFS method and mutators 
    //print out tree from given vertex
    //print shortest bath from source vertex (s) to destination vertex (v) using recursive algorithm 
    
    Graph g(5);
    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.BFS(0);
    std::cout << "\nShortest path from 0 to 4: ";
    g.printPath(0, 4);

    return 0;
    
}
