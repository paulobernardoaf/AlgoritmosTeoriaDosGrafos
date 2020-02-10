#include<bits/stdc++.h> 
using namespace std; 
main() 
{ 
    int numVertices, numEdges;
    vector<vector<pair<int, int>>> graph;

    cin >> numVertices >> numEdges;

    graph.resize(numVertices);

    for (int i=0;i<numEdges;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(w, v));
        graph[v].push_back(make_pair(w, u));
    }

    vector<int> dist;
    dist.resize(numVertices, 100000);
    dist[0] = 0;

    priority_queue< pair<int, int>, vector<pair<int, int>>, less<pair<int, int> >> pq;

    pq.push( {dist[0], 0} );

    vector<pair<int, int>> path;
    path.resize(numVertices, {0, -1});

    while(!pq.empty()) {
        pair<int, int> v = pq.top();
        pq.pop();

        for(auto x : graph[v.second]) {
            if(dist[v.second] + x.first < dist[x.second]) {
                dist[x.second] = dist[v.second] + x.first;
                path[x.second] = make_pair(dist[x.second], v.second);
                pq.push({dist[x.second], x.second});
            }
        }   
    }    

    for (int i = 0; i < graph.size(); ++i) {
        printf("Path to vertex %d: ", i);
        int aux = path[i].second, count = 0;
        int p[100000] = {0};
        while (aux != -1) {
            // printf("%d => ", aux);
            p[count++] = aux;
            aux = path[aux].second;
        }
        int j;
        if (count == 0) {
            printf("-\n");
        } else {
            for (j = count - 1; j >= 0; j--) {
                if (j == 0) {
                    printf("%d and distance %d\n", p[j], dist[i]);
                } else {
                    printf("%d, ", p[j]);
                }
            }
        }
    }
    
} 