#include <bits/stdc++.h>
using namespace std;

void dfs1(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st) {
    visited[node] = true;
    for (int nei : adj[node]) {
        if (!visited[nei])
            dfs1(nei, adj, visited, st);
    }
    st.push(node); // push after visiting all descendants
}

void dfs2(int node, vector<vector<int>> &transpose, vector<bool> &visited, vector<int> &component) {
    visited[node] = true;
    component.push_back(node);
    for (int nei : transpose[node]) {
        if (!visited[nei])
            dfs2(nei, transpose, visited, component);
    }
}

void kosaraju(int V, vector<vector<int>> &adj) {
    stack<int> st;
    vector<bool> visited(V, false);

    // Step 1: Do DFS and store nodes by finish time
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs1(i, adj, visited, st);
    }

    // Step 2: Transpose the graph
    vector<vector<int>> transpose(V);
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            transpose[v].push_back(u); // reverse the edge
        }
    }

    // Step 3: Do DFS in order of finish time on transposed graph
    fill(visited.begin(), visited.end(), false);
    cout << "Strongly Connected Components:\n";
    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            vector<int> component;
            dfs2(node, transpose, visited, component);

            for (int v : component)
                cout << v << " ";
            cout << "\n";
        }
    }
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    // Example graph
    adj[0].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(3);
    adj[3].push_back(4);

    kosaraju(V, adj);

    return 0;
}
