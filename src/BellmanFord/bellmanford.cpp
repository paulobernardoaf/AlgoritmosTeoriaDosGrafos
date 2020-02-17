#include<bits/stdc++.h> 
#include "../../include/Graph.hpp"
using namespace std; 

void bellmanFord(Graph graph, int source) {

    priority_queue<IntPair, vector<IntPair>, greater<IntPair>> pq;
    bool negativeCycle = false;

    vector<int> dist(graph.numVertices, INT_MAX);

    dist[source] = 0;    

    for (int i = 0; i < graph.numVertices - 1; i++) {
        for (int u = 0; u < graph.numVertices; u++) {
            AdjacencyList::iterator j;
            for (j = graph.adjLists[u].begin() ; j != graph.adjLists[u].end(); j++) {
                if(dist[j->first] > dist[u] + j->second) {
                    dist[j->first] = dist[u] + j->second;
                }
            }
        }
    }

    for (int u = 0; u < graph.numVertices; u++) {
        AdjacencyList::iterator j;
        for (j = graph.adjLists[u].begin() ; j != graph.adjLists[u].end(); j++) {
            if(dist[j->first] > dist[u] + j->second) {
                negativeCycle = true;
            }
        }
    }

    if(negativeCycle) {
        cout << "Graph contains a negative cycle!" << endl;
    } else {
        cout << "from \t| to \t| dist" << endl;
        for (int i = 0; i < graph.numVertices; ++i) {
            cout << source << "\t| " << i << "\t| " << dist[i] << endl;
        }
    }

}

int main() 
{ 
    Graph graph = buildDirectedGraph();

    bellmanFord(graph, 0);    
} 