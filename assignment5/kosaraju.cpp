#include<bits/stdc++.h>
using namespace std;

#define V 5
void dfs(bool graph[V][V], int node, vector<bool> &visited, stack<int> &st){
    visited[node] = true;

    for(int i=0;i<V;i++){
        if(graph[node][i] && !visited[i]){
            dfs(graph,i,visited,st);
        }
    }
    st.push(node);
}

void transpose(bool graph[V][V], bool transposeGraph[V][V]){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            transposeGraph[j][i] = graph[i][j];
        }
    }
}

