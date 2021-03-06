#include<bits/stdc++.h> 
#include "../../include/Graph.hpp"
using namespace std; 

void dijkstra(Graph graph, int source) {

    priority_queue<IntPair, vector<IntPair>, greater<IntPair>> pq;

    vector<bool> visited(graph.numVertices, false);
    vector<int> dist(graph.numVertices, INT_MAX);

    dist[source] = 0;    

    pq.push({dist[source], source});

    while(!pq.empty()) {

        IntPair deq = pq.top(); pq.pop();
        
        if(!visited[deq.second]) {
            visited[deq.second] = true;         
            AdjacencyList::iterator i;
            for (i = graph.adjLists[deq.second].begin() ; i != graph.adjLists[deq.second].end(); i++) {
                if(dist[i->first] > dist[deq.second] + i->second) {
                    dist[i->first] = dist[deq.second] + i->second;
                    pq.push({dist[i->first], i->first});
                }
            }
        }
    }

    cout << "from \t| to \t| dist" << endl;
    for (int i = 0; i < graph.numVertices; ++i) {
        cout << source << "\t| " << i << "\t| " << dist[i] << endl;
    }
}

int main() 
{ 
    Graph graph = buildGraph();

    dijkstra(graph, 0);
    
} 