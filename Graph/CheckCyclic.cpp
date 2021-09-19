#include "bits/stdc++.h"
using namespace std;
bool checkCyclic(vector<bool> vis,vector<int> adj[],int curr){
    if(vis[curr] == true)
    return true;

    vis[curr]= true;
    bool flag=false;
    for(int i=0;i<adj[curr].size();i++){
          flag= checkCyclic(vis,adj,adj[curr][i]);
          if(flag)
          return true;
    }
    return false;
}
bool isCyclic(int V,vector<int> adj[]){
    vector<bool> visited(V,false);
    bool flag= false;
    for(int i=0;i<V;i++){
        visited[i]=true;
        for(int j=0;j<adj[i].size();j++){
            flag= checkCyclic(visited,adj,adj[i][j]);
            if(flag)
            return true;
        }
        visited[i]= false;
    }
    return false;
}
int main(){
   int v,e;
   cin>>v>>e;
   vector<int> adj[v];
   for(int i=0;i<e;i++){
       int u,v;
       cin>>u>>v;
       adj[u].push_back(v);
   }
   cout<< isCyclic(v,adj)<<endl;
}