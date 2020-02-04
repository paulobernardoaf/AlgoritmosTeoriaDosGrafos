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

    vector<bool> visited;
    visited.resize(numVertices + 1, false);

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq; // lixo

        // cout << "BOTANO";
    for(auto v : graph[1]){
		pq.push(make_tuple(v.first, 1, v.second));
	}
    visited[1] = true;

    int cost = 0;
    vector<pair<int, int>> path;
    path.resize(numVertices + 1);

    while(!pq.empty()) {
        tuple<int, int , int> deq = pq.top();
        pq.pop();
        // cout << "AAAAAAA: " << get<2>(deq);
        if(!visited[get<2>(deq)]) {
            cost += get<0>(deq);
            cout << "SOMANDO: " << get<0>(deq) << " A PARTIR DO " << get<1>(deq) << endl;
            cout << "CUSTO: " << cost << endl;
            path[get<2>(deq)] = make_pair(get<1>(deq), get<0>(deq));
            visited[get<2>(deq)] = true;
            for(int i=0; i < graph[get<2>(deq)].size(); i++) {
                if(!visited[graph[get<2>(deq)][i].second]) {
                    cout << "COLOCANDO " << graph[get<2>(deq)][i].first << ", " << get<2>(deq) << ", " << graph[get<2>(deq)][i].second << endl; 
                    pq.push(make_tuple(graph[get<2>(deq)][i].first, get<2>(deq), graph[get<2>(deq)][i].second));
                }
            }
        }

    }

    cout << cost << endl;

} 