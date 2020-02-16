#include<bits/stdc++.h> 
using namespace std;
#include "../Graph.hpp"

int prim(Graph graph, int source) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int mstCost = 0;
    vector<bool> visited(graph.numVertices, false);

    visited[source] = true;

    AdjacencyList::iterator i;
    for (i = graph.adjLists[source].begin() ; i != graph.adjLists[source].end(); i++) {
        if(!visited[i->first]) {
            pq.push({i->second, i->first});
        }
    }

    while(!pq.empty()) {

        pair<int, int> deq = pq.top(); pq.pop();
        
        if(!visited[deq.second]) {
            visited[deq.second] = true;
            mstCost += deq.first;            
            AdjacencyList::iterator i;
            for (i = graph.adjLists[deq.second].begin() ; i != graph.adjLists[deq.second].end(); i++) {
                if(!visited[i->first]) {
                    pq.push({i->second, i->first});
                }
            }
        }
    }

    return mstCost;
}


int main() 
{ 
    Graph graph = buildGraph();

    cout << "MST cost: " << prim(graph, 0) << endl;

    return 0;
} 