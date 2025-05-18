#include<bits/stdc++.h>
using namespace std;

#define V 5
bool isSafe(bool graph[V][V], int v,vector<int> &path,int pos){
    if(!graph[path[pos-1]][v]){
        return false;
    }

    for(int i=0;i<path.size();i++){
        if(path[i]==v){
            return false;
        }
    }
    return true;
}


bool hamiltonianCycleUtil(bool graph[V][V], vector<int> &path, int pos){
    if(pos==V){
        return graph[path[pos-1]][path[0]];

    }

    for(int i = 1;i<V;i++){
        if(isSafe(graph,i,path,pos)){
            path[pos] = i;
            if(hamiltonianCycleUtil(graph,path,pos+1)){
                return true;
            }
            path[pos] = -1;
        }
    }
    return false;

}


void hamiltonianCYCLE(bool graph[][]){
    vector<int> path(V,-1);

    path[0] = 0;

    if(hamiltonianCycleUtil(graph,path,1)){
        cout<<"found"<<endl;
        for(int v:path){
            cout<<v<<" ";

        }
        cout<<path[0];
    }
    else{
        cout<<"nope";
    }
}
