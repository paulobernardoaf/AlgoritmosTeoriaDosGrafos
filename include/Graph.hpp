#ifndef GRAPH_HPP
#define GRAPH_HPP

#include<bits/stdc++.h> 
using namespace std; 

typedef pair<int, int> IntPair;

typedef list<IntPair> AdjacencyList;

typedef pair<int, IntPair> Edge;

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