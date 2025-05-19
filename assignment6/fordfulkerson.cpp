#include <bits/stdc++.h>
using namespace std;

#define V 6

bool bfs(vector<vector<int>> &residualGraph, int s, int t, vector<int> &parent) {
    vector<bool> visited(V, false);
    queue<int> q;

    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                parent[v] = u;
                visited[v] = true;
                q.push(v);
                if (v == t) return true; // Reached sink
            }
        }
    }

    return false;
}

int fordFulkerson(vector<vector<int>> &graph, int s, int t) {
    vector<vector<int>> residualGraph = graph; // Make a copy
    vector<int> parent(V); // Store augmenting path
    int maxFlow = 0;

   
    while (bfs(residualGraph, s, t, parent)) {
        
        int pathFlow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    
    vector<vector<int>> graph = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int source = 0, sink = 5;
    cout << "Maximum Flow: " << fordFulkerson(graph, source, sink) << "\n";

    return 0;
}
