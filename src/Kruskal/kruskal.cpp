#include<bits/stdc++.h> 
#include "../../include/Graph.hpp"
using namespace std; 

class UnionFind {
    public:
        int* parent;
        int* rank;
        int size;
        UnionFind(int N);
        int find(int u);
        void merge(int v, int u);
        bool sameSet(int v, int u);
};

UnionFind::UnionFind(int numVertices) {
    this->size = numVertices;
    this->parent = new int[numVertices + 1];
    for (int i = 0; i < numVertices; i++) {
        parent[i] = -1;
    }
}

int UnionFind::find(int u) {
    if(parent[u] < 0) {
        return u;
    }
    parent[u] = find(parent[u]);
    return parent[u];
}

void UnionFind::merge(int v, int u) {
    v = find(v), u = find(u); 

    if(parent[u] < parent[v]) {
        int aux = parent[u];
        parent[u] = parent[v];
        parent[v] = aux;
    }
    parent[v] += parent[u];
    parent[u] = v;
}

bool UnionFind::sameSet(int v, int u) {
    return find(v) == find(u);
}

int kruskal(Graph graph) {

    int mstCost = 0;

    EdgeVector edges = EdgeVector(graph.numEdges);

    for(int i = 0; i < graph.numVertices; i++) {
        
        AdjacencyList::iterator j;
        for (j = graph.adjLists[i].begin(); j != graph.adjLists[i].end(); j++) {
            int v = j->first;
            int w = j->second;

            Edge weigthPair = {w, {i, v}};

            edges.push_back(weigthPair);
        }
    }

    sort(edges.begin(), edges.end()); 
    
    UnionFind UF(graph.numVertices);

    EdgeVector::iterator i;
    for(i = edges.begin(); i < edges.end(); i++) {
        int src = i->second.first;
        int dest = i->second.second;

        int srcSet = UF.find(src);
        int destSet = UF.find(dest);

        if(!UF.sameSet(srcSet, destSet)) {
            mstCost += i->first;
            UF.merge(srcSet, destSet);
        }
    }

    return mstCost;    

}

int main() 
{ 
    Graph graph = buildDirectedGraph();

    cout << "MST Cost: " << kruskal(graph) << endl;    
} 