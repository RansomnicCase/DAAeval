#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &visited, stack<int> &st) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, st);
        }
    }

    st.push(node); 
}

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    vector<int> topo;
    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }

    return topo;
}

int main() {
    int V = 6;
    vector<int> adj[V];


    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> result = topoSort(V, adj);

    cout << "Topological Sort Order:\n";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
