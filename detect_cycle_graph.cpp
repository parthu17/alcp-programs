#include<bits/stdc++.h>
using namespace std;
bool dfsCycle(int node,int parent,vector<vector<int>&adj,vector<int> visited){
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
bool hasCycle(int n,vector<vector<int> &adj){
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(dfsCycle(i,-1,adj,visited)) return true;
        }
    }
    return false;
}
int main(){
    
}
