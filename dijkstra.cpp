#include<bits/stdc++.h> 
using namespace std; 
main() 
{ 
    int numVertices, numEdges;
    vector<vector<pair<int, int>>> graph; //coisa feia da porr

    cin >> numVertices >> numEdges;

    graph.resize(numVertices + 1);

    for (int i=0;i<numEdges;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(w, v));
        graph[v].push_back(make_pair(w, u));
    }

    int index = 0;
    for(auto i : graph) {
        cout << index++ << ": " << endl ;
        for(auto j : i) {
            cout << "\t" << j.first << " " << j.second << endl;
        }
    }

    cout << endl << endl;

    vector<int> dist;
    dist.resize(numVertices + 1, 100000);
    dist[1] = 0;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq; // lixo

    pq.push(make_tuple(0, 1, 1));

    vector<pair<int, int>> path;
    path.resize(numVertices + 1);

    while(!pq.empty()) {
        tuple<int, int , int> deq = pq.top();
        pq.pop();
        for (auto x : graph[get<2>(deq)]) {
            int actual_dist = dist[get<1>(deq)] + get<0>(deq);
            if (dist[])
        }
    }

    for (int i = 0; i < dist.size(); i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

} 