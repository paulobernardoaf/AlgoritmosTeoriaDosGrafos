#ifndef GRAPH_HPP
#define GRAPH_HPP

#include<bits/stdc++.h> 
using namespace std; 

typedef list<pair<int, int>> AdjacencyList;

typedef pair<int, pair<int, int>> Edge;

typedef vector<Edge> EdgeVector;

class Graph {
    public:
        int numVertices;
        int numEdges;
        AdjacencyList* adjLists;
        Graph(int V);
        EdgeVector getEdges();
        void addEdge(int src, int dest, int weight);
        int getEdgeCost(int src, int dest);
        void print();
};

Graph buildGraph();

Graph buildDirectedGraph();

#endif