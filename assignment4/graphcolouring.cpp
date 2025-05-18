#include<bits/stdc++.h>
using namespace std;

#define V 5

bool isSafe(int node,bool graph[V][V], vector<int> color, int c){
    for(int i=0;i<V;i++){
        if(graph[node][i]&&color[i]==c){
            return false;
        }
    }
    return true;
}




bool graphutil(bool graph[V][V], vector<int> color, int node){
    if(node==V){
        return true;
    }

    for(int i=1;i<=V;i++){
        if(isSafe(node,graph,color,i)){
            color[node] = i;
            if(graphutil(graph,color,node+1)){
                return true;
            }
            color[node] = 0;//backtrack
        }
    }
    return false;
}


bool graphcolor(bool graph[V][V]){

    vector<int> color(V,0);
    if(!graphutil(graph,color,0)){
        cout<<"no solution";
        return false;
    }

    cout<<"solution exists";
    for (int i = 0; i < V; i++)
        cout << "Vertex " << i << " ---> Color " << color[i] << "\n";

    return true;
    
}


int main() {
    bool graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };


    graphcolor(graph);

    return 0;
}