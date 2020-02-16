#include<bits/stdc++.h> 
#include "Graph.hpp"
using namespace std; 

Graph::Graph(int numVertices) {
    this->numVertices = numVertices;
    this->numEdges = 0;
    this->adjLists = new AdjacencyList[numVertices];
}

void Graph::addEdge(int src, int dest, int weight){
    this->adjLists[src].push_front(make_pair(dest, weight));
    this->numEdges++;
}

EdgeVector Graph::getEdges() {

    EdgeVector result = EdgeVector(this->numEdges);

    for(int i = 0; i < this->numVertices; i++) {
        
        AdjacencyList::iterator j;
        for (j = this->adjLists[i].begin(); j != this->adjLists[i].end(); j++) {
            int v = j->first;
            int w = j->second;

            pair<int, pair<int, int>> weigthPair = {w, {i, v}};

            result.push_back(weigthPair);
        }
    }

    sort(result.begin(), result.end()); 
    return result;
}

int Graph::getEdgeCost(int src, int dest) {

    if (src == -1) {
        return 0;
    }

    AdjacencyList::iterator i;
    for (i = this->adjLists[src].begin(); i != this->adjLists[src].end(); i++) {
        if (i->first == dest) {
            return i->second;
        }
    }

}

void Graph::print() {
    for (int i = 0; i < this->numVertices; i++) {
        cout << "From: " << i << " -> ";

        AdjacencyList::iterator j;
        for(j = this->adjLists[i].begin(); j != this->adjLists[i].end(); j++ ){
            cout << j->first << " with weigth: " << j->second << " | ";
        }

        cout << endl;
    }
}

Graph buildGraph() {

    int numVertices, numEdges, src, dest, weigth;

    cin >> numVertices >> numEdges;

    Graph graph(numVertices);

    for (int i=0;i<numEdges;i++) {
        int u, v, w;
        cin >> src >> dest >> weigth;
        graph.addEdge(src, dest, weigth);
        graph.addEdge(dest, src, weigth);
    }

    return graph;

}

Graph buildDirectedGraph() {

    int numVertices, numEdges, src, dest, weigth;

    cin >> numVertices >> numEdges;

    Graph graph(numVertices);

    for (int i=0;i<numEdges;i++) {
        int u, v, w;
        cin >> src >> dest >> weigth;
        graph.addEdge(src, dest, weigth);
    }

    return graph;
}