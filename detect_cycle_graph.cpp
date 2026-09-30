#include<bits/stdc++.h>
using namespace std;
bool dfsCycle(int node,int parent,vector<vector<int>>& adj,vector<bool>& visited){
    visited[node]=true;
    for(int nb:adj[node]){
        if(!visited[nb]){
            if(dfsCycle(nb,node,adj,visited)){
                return true;
            }
        }
        else if(nb!=parent){
            return true;
        }
    }
    return false;
}
bool hasCycle(int n,vector<vector<int>> &adj){
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(dfsCycle(i,-1,adj,visited)) return true;
        }
    }
    return false;
}
int main(){
    int n,m;
    cout<<"enter the number of edges\n";
    cin>>m;
    cout<<"enter the number of vertices\n";
    cin>>n;
    vector<vector<int>> adj(n);
    cout<<"enter edges as: u v\n";
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(hasCycle(n,adj)){
        cout<<"Cycle detected in the graph\n";
    }
    else{
        cout<<"No Cycle detected\n";
    }
    return 0;
}
