#include<bits/stdc++.h>
using namespace std;

vector<int> topo(vector<vector<int>> &adj, int V){
    vector<int> indegree(V,0);


    for(int u=0;u<V;u++){
        for(int v:adj[u]){
            indegree[v]++;  
        }
    }


    queue<int> q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }


    vector<int> topo;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        topo.push_back(u);


        for(int v:adj[u]){
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
    }

    if(topo.size()==V){
        return topo;
    }

    else{
        return {};//cycle detected
    }


}


int main() {
    int V = 6; 
    vector<vector<int>> adj(V);

   
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> result = topo(adj,V);

    if (!result.empty()) {
        cout << "Topological Sort: ";
        for (int node : result)
            cout << node << " ";
        cout << "\n";
    } else {
        cout << "The graph has a cycle. Topological sort not possible.\n";
    }

    return 0;
}